// GestBtn.c
#include "peripheral/ports/plib_ports.h" // Inclusion des fonctions de gestion des ports
#include "system_config.h" // Inclusion de la configuration systeme
#include "GestBtn.h" // Inclusion du header de gestion des boutons
// --- Parametres internes de debounce ---
static const uint8_t kMaxDebounceCount = 5; // Nombre d'iterations pour valider un changement

typedef enum {
    DebounceWaitChange, // Attente d'un changement d'etat
    DebounceWaitStable  // Attente de la stabilite de l'etat
} E_DebounceState;

typedef struct {
    E_DebounceState state; // etat du mecanisme d'antirebond
    uint8_t         counter; // Compteur d'iterations
    struct {
        uint8_t pressed : 1;  // evenement presse detecte
        uint8_t prev    : 1;  // Derniere valeur brute lue
        uint8_t value   : 1;  // Valeur stable apres antirebond
    } bits;
} S_Switch;

// Descripteurs pour OK et SELECT
static S_Switch swOK, swSelect;

/**
 * @brief  Mecanisme de debounce, a appeler chaque tick (~1 ms).
 *
 * @details
 * Cette fonction gere l'antirebond logiciel d'un bouton. Elle doit etre appelee
 * a chaque tick (environ 1 ms) pour chaque bouton a surveiller.
 *
 * @param sw   pointeur sur le descripteur du bouton
 * @param raw  etat brut (1 = relâche, 0 = appuye)
 * @return Aucun retour.
 *
 * @pre Le descripteur doit etre initialise.
 * @post L'etat stable du bouton est mis a jour.
 */
static void debounce_switch(S_Switch *sw, bool raw)
{
    switch (sw->state) {
        case DebounceWaitChange:
            if (raw != sw->bits.prev) {
                sw->bits.prev = raw; // Met a jour la valeur precedente
                sw->state      = DebounceWaitStable; // Passe a l'attente de stabilite
            }
            break;

        case DebounceWaitStable:
            if (raw == sw->bits.prev) {
                if (++sw->counter >= kMaxDebounceCount) {
                    sw->bits.value   = raw; // Met a jour la valeur stable
                    if (!raw)        // front descendant = appui
                        sw->bits.pressed = 1; // Note l'appui
                    sw->state        = DebounceWaitChange; // Retour a l'attente de changement
                    sw->counter      = 0; // Reinitialise le compteur
                }
            } else {
                sw->counter   = 0; // Reinitialise le compteur
                sw->bits.prev = raw; // Met a jour la valeur precedente
            }
            break;
    }
}

/**
 * @brief  Initialise l'etat interne du debounce.
 *
 * @details
 * Cette fonction initialise les variables internes utilisees pour l'antirebond des boutons.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Aucun prerequis specifique.
 * @post Les variables internes de detection de bouton sont initialisees.
 */
void GestBtn_Init(void)
{
    // Initialisation interne uniquement
    swOK.state        = DebounceWaitChange; // etat initial
    swOK.counter      = 0; // Compteur a zero
    swOK.bits.prev    = 1; // Valeur precedente relâchee
    swOK.bits.value   = 1; // Valeur stable relâchee
    swOK.bits.pressed = 0; // Aucun appui detecte

    swSelect.state        = DebounceWaitChange; // etat initial
    swSelect.counter      = 0; // Compteur a zero
    swSelect.bits.prev    = 1; // Valeur precedente relâchee
    swSelect.bits.value   = 1; // Valeur stable relâchee
    swSelect.bits.pressed = 0; // Aucun appui detecte
}

/**
 * @brief  Doit etre appelee toutes les ~1 ms pour actualiser le debounce.
 *
 * @details
 * Cette fonction lit l'etat brut des boutons OK et SELECT, puis appelle le mecanisme
 * d'antirebond logiciel pour chacun.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre GestBtn_Init doit avoir ete appelee.
 * @post L'etat des boutons est mis a jour.
 */
void GestBtn_Update(void)
{
    // 1 = relâche, 0 = appuye
    uint8_t okState     = PB_OK_StateGet(); // Lecture de l'etat du bouton OK
    uint8_t selectState = PB_SELECT_StateGet(); // Lecture de l'etat du bouton SELECT
    bool rawOK     = false; // etat brut du bouton OK
    bool rawSelect = false; // etat brut du bouton SELECT
    
    if (okState == 0u) {
        rawOK = true; // Bouton OK appuye
    }

    if (selectState == 0u) {
        rawSelect = true; // Bouton SELECT appuye
    }

    debounce_switch(&swOK,     rawOK); // Antirebond pour OK
    debounce_switch(&swSelect, rawSelect); // Antirebond pour SELECT
}

/**
 * @brief  Renvoie le masque des boutons presses depuis le dernier appel,
 *         et reinitialise leur flag « pressed ».
 *
 * @details
 * Cette fonction retourne un masque indiquant quels boutons ont ete presses
 * depuis le dernier appel, puis reinitialise leur etat interne.
 *
 * @param Aucun parametre.
 * @return combinaison de GESTBTN_OK | GESTBTN_SELECT
 *
 * @pre GestBtn_Update doit etre appelee regulierement.
 * @post Les flags internes des boutons sont reinitialises.
 */
uint8_t GestBtn_Scan(void)
{
    uint8_t mask = GESTBTN_NONE; // Masque de retour
    if (swOK.bits.pressed) {
        mask |= GESTBTN_OK; // Ajoute OK si appuye
        swOK.bits.pressed = 0; // Reinitialise le flag
    }
    if (swSelect.bits.pressed) {
        mask |= GESTBTN_SELECT; // Ajoute SELECT si appuye
        swSelect.bits.pressed = 0; // Reinitialise le flag
    }
    return mask; // Retourne le masque
}
