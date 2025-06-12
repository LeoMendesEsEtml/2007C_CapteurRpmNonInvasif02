#include <stdint.h>
#include <stdbool.h>

// Enum�ration des �tats de menu disponibles
typedef enum {
    MENU_WELCOME,
    MENU_BATTERIE,
    MENU_PARAMETRE,
    MENU_CHOIX_PROFIL,
    MENU_SAUVEGARDE,
    MENU_CONF_NB_HELICE,
    MENU_CONF_NB_CYLINDRE,
    MENU_MESURE_VISUEL,
    MENU_MESURE_AUDIO,
    MENU_MESURE_VIBRATION
} MenuState;

/**
 * @brief Initialise et affiche le contenu du menu courant.
 * 
 * Doit �tre appel�e au d�marrage et apr�s tout changement d'�tat de menu.
 */
void Menu_Display(void);

/**
 * @brief Traite les �v�nements du menu (boutons).
 * 
 * Doit �tre appel�e r�guli�rement dans la boucle principale ou via une t�che.
 */
void Menu_Task(void);


