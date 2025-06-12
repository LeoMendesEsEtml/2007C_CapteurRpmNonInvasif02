// GestBtn.h
#ifndef GESTBTN_H
#define GESTBTN_H

#include <stdint.h> // Inclusion des definitions de types entiers standard
#include <stdbool.h> // Inclusion du type booleen standard

/** Masques de retour de GestBtn_Scan() **/
#define GESTBTN_NONE    0x00u // Aucun bouton
#define GESTBTN_OK      0x01u // bit 0 : bouton OK
#define GESTBTN_SELECT  0x02u // bit 1 : bouton SELECT

/**
 * @brief  Initialise l'etat interne du debounce.
 *         *Ne touche pas a la config des broches !*
 *
 * @details
 * Cette fonction initialise les variables internes utilisees pour l'antirebond des boutons.
 * Elle ne modifie pas la configuration materielle des broches.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Aucun prerequis specifique.
 * @post Les variables internes de detection de bouton sont initialisees.
 */
void GestBtn_Init(void);

/**
 * @brief  Doit etre appelee toutes les ~1 ms pour actualiser le debounce.
 *
 * @details
 * Cette fonction doit etre appelee periodiquement (toutes les 1 ms) pour assurer
 * la detection fiable des appuis sur les boutons via l'antirebond logiciel.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre GestBtn_Init doit avoir ete appelee.
 * @post L'etat des boutons est mis a jour.
 */
void GestBtn_Update(void);

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
uint8_t GestBtn_Scan(void);

#endif // GESTBTN_H
