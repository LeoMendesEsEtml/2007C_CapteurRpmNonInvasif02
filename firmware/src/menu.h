#include <stdint.h>
#include <stdbool.h>

// Enumération des états de menu disponibles
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
 * Doit être appelée au démarrage et après tout changement d'état de menu.
 */
void Menu_Display(void);

/**
 * @brief Traite les événements du menu (boutons).
 * 
 * Doit être appelée régulièrement dans la boucle principale ou via une tâche.
 */
void Menu_Task(void);


