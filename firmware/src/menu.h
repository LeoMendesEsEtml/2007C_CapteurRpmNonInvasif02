/*
--------------------------------------------------------
 Fichier : menu.h
 Auteur  : leo mendes
 Date    : 2024
 Role    : Declarations et prototypes pour la gestion des menus utilisateur
--------------------------------------------------------
*/
#include <stdint.h>
#include <stdbool.h>

// Enumeration des etats de menu disponibles
typedef enum {
    MENU_WELCOME,
    MENU_BATTERIE,
    MENU_PARAMETRE,
    MENU_CHOIX_PROFIL,
    MENU_SAUVEGARDE,
    MENU_CONF_NB_pale,
    MENU_CONF_NB_CYLINDRE,
    MENU_MESURE_VISUEL,
    MENU_MESURE_AUDIO,
    MENU_MESURE_VIBRATION
} MenuState;

/**
 * @brief Initialise et affiche le contenu du menu courant.
 * 
 * Doit etre appelee au demarrage et après tout changement d'etat de menu.
 */
void Menu_Display(void);

/**
 * @brief Traite les evenements du menu (boutons).
 * 
 * Doit etre appelee regulièrement dans la boucle principale ou via une tâche.
 */
void Menu_Task(void);


