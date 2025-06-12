/*
--------------------------------------------------------
 Fichier : menu.c
 Auteur  : leo mendes
 Date    : 2024
 Role    : Fonctions de gestion des menus de l'interface utilisateur
--------------------------------------------------------
*/
// Inclusion du header LCD
#include "LCD.h" // Fonctions d'affichage LCD
// Inclusion du header gestion boutons
#include "GestBtn.h" // Fonctions de gestion des boutons
// Inclusion du header menu
#include "menu.h" // Prototypes des fonctions menu
#include <stdio.h> // Pour les fonctions d'affichage
// Inclusion du header application
#include "app.h" // Definitions de l'application
// Inclusion des definitions systeme
#include "system_definitions.h" // Definitions systeme
// Inclusion du header stockage profil
#include "ProfilStorage.h" // Fonctions de gestion des profils
// Inclusion du header capteur LIS2HH12
#include "LIS2HH12.h" // Fonctions du capteur LIS2HH12

static MenuState currentMenu = MENU_WELCOME;
static uint8_t profilIndex = 0; // 0 a 4 (4 = Nouveau)
static uint8_t saveIndex = 0; // 0 a 3
static uint8_t curseurParametre = 0;
static uint8_t curseurBatterie = 0;

/**
 * @brief Affiche le menu courant sur l'ecran LCD.
 *
 * @details
 * Cette fonction met a jour l'affichage LCD selon l'etat courant du menu.
 * Elle gere tous les ecrans principaux, la selection de profil, la sauvegarde,
 * la configuration des pales et cylindres, et les ecrans de mesure.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 */
void Menu_Display(void) {
    lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
    lcd_put_string("                    "); // Efface la premiere ligne
    lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
    lcd_put_string("                    "); // Efface la deuxieme ligne

    switch (currentMenu) {
        /** @brief Ecran d'accueil */
        case MENU_WELCOME:
            lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
            lcd_put_string("Capteur RPM"); // Affiche le titre
            lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
            lcd_put_string("ETML-ES  LMS"); // Affiche le sous-titre
            break;
        /** @brief Ecran batterie et gestion profils */
        case MENU_BATTERIE:
            if (curseurBatterie == 0) {
                lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
                lcd_put_string(">Batterie = XXX"); // Affiche la batterie selectionnee
                lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
                lcd_put_string(" Gestion profils"); // Affiche l'option de gestion de profils
            } else {
                lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
                lcd_put_string(" Batterie = XXX"); // Affiche la batterie non selectionnee
                lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
                lcd_put_string(">Gestion profils"); // Affiche la gestion de profils selectionnee
            }
            break;
        /** @brief Ecran parametres */
        case MENU_PARAMETRE:
            if (curseurParametre == 0) {
                lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
                lcd_put_string(">Parametre"); // Affiche l'option parametre selectionnee
                lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
                lcd_put_string("  Eteindre"); // Affiche l'option eteindre non selectionnee
            } else {
                lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
                lcd_put_string(" Parametre"); // Affiche l'option parametre non selectionnee
                lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
                lcd_put_string(">Eteindre"); // Affiche l'option eteindre selectionnee
            }
            break;
        /** @brief Choix du profil utilisateur */
        case MENU_CHOIX_PROFIL:
            lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
            lcd_put_string("Choisir Profil"); // Affiche le titre
            lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
            switch (profilIndex) {
                /** @brief Profil 1 selectionne */
                case 0: lcd_put_string(">1 2 3 4 Nouveau"); break; // Affiche la selection sur le profil 1
                /** @brief Profil 2 selectionne */
                case 1: lcd_put_string(" 1>2 3 4 Nouveau"); break; // Affiche la selection sur le profil 2
                /** @brief Profil 3 selectionne */
                case 2: lcd_put_string(" 1 2>3 4 Nouveau"); break; // Affiche la selection sur le profil 3
                /** @brief Profil 4 selectionne */
                case 3: lcd_put_string(" 1 2 3>4 Nouveau"); break; // Affiche la selection sur le profil 4
                /** @brief Nouveau profil selectionne */
                case 4: lcd_put_string(" 1 2 3 4>Nouveau"); break; // Affiche la selection sur nouveau profil
            }
            break;
        /** @brief Ecran de sauvegarde de profil */
        case MENU_SAUVEGARDE:
            lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
            lcd_put_string("Sauvegarder sous"); // Affiche le titre
            lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
            switch (saveIndex) {
                /** @brief Sauvegarde dans P1 */
                case 0: lcd_put_string(">1 2 3 4"); break; // Affiche la selection sur P1
                /** @brief Sauvegarde dans P2 */
                case 1: lcd_put_string(" 1>2 3 4"); break; // Affiche la selection sur P2
                /** @brief Sauvegarde dans P3 */
                case 2: lcd_put_string(" 1 2>3 4"); break; // Affiche la selection sur P3
                /** @brief Sauvegarde dans P4 */
                case 3: lcd_put_string(" 1 2 3>4"); break; // Affiche la selection sur P4
            }
            break;
        /** @brief Configuration du nombre de pales */
        case MENU_CONF_NB_pale: {
            char buf[21]; // Buffer pour l'affichage
            lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
            lcd_put_string("Nbr pales :"); // Affiche le texte
            lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
            sprintf(buf, "> %d", appData.nbBlades); // Prepare la valeur
            lcd_put_string(buf); // Affiche la valeur
            break;
        }
        /** @brief Configuration du nombre de cylindres */
        case MENU_CONF_NB_CYLINDRE: {
            char buf[21]; // Buffer pour l'affichage
            lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
            lcd_put_string("Nbr Cylindres:"); // Affiche le texte
            lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
            sprintf(buf, "> %d", appData.nbCylindres); // Prepare la valeur
            lcd_put_string(buf); // Affiche la valeur
            break;
        }
        /** @brief Ecran de mesure visuelle */
        case MENU_MESURE_VISUEL: {
            char buf[21]; // Buffer pour l'affichage
            uint8_t profilNum; // Numero du profil
            Profil *p; // Pointeur sur le profil
            profilNum = appData.selectedProfil + 1; // Calcule le numero du profil
            p = Profils_Get(appData.selectedProfil); // Recupere le profil
            lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
            sprintf(buf, "Visuel : %5u RPM", (uint16_t) appData.rpm); // Prepare la chaine RPM
            lcd_put_string(buf); // Affiche la valeur RPM
            lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
            if (p != 0 && p->validFlag == PROFIL_VALID_FLAG) {
                sprintf(buf, "Profil%d : %dH  %dC", profilNum, p->nbBlades, p->nbCylindres); // Affiche les infos du profil
            } else {
                sprintf(buf, "Profil%d : --   --", profilNum); // Affiche des tirets si profil non valide
            }
            lcd_put_string(buf); // Affiche la ligne profil
            break;
        }
        /** @brief Ecran de mesure audio */
        case MENU_MESURE_AUDIO:
            lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
            lcd_put_string("Mesure Audio"); // Affiche le texte
            lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
            lcd_put_string("xxxx RPM / Cyl."); // Affiche la ligne info
            break;
        /** @brief Ecran de mesure vibration */
        case MENU_MESURE_VIBRATION:
            lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
            lcd_put_string("Mesure Vibration"); // Affiche le texte
            lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
            lcd_put_string("xxxx RPM / Cyl."); // Affiche la ligne info
            break;
    }
}

#define TIMER_FREQ 10000000UL  // 10 MHz

/**
 * @brief Gere la logique de navigation et d'action des menus.
 *
 * @details
 * Cette fonction gere les entrees utilisateur (boutons), la navigation entre les differents
 * menus, la gestion des profils, la configuration, et les mesures. Elle met a jour l'etat
 * courant du menu et declenche l'affichage si necessaire.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 */
void Menu_Task(void) {
    uint8_t btn = GestBtn_Scan(); // Lit l'etat des boutons
    static uint8_t RefreshNeeded = 0; // Flag pour rafraichir l'affichage
    static bool captureStarted = false; // Etat de la capture RPM
    static uint16_t lastRpm; // Dernier RPM affiche
    static uint8_t accInitDone = 0; // Flag d'init acc
    static uint16_t accTick = 0; // Compteur pour lecture acc
    static int16_t accX = 0; // Acceleration X
    static int16_t accY = 0; // Acceleration Y
    static int16_t accZ = 0; // Acceleration Z
    static uint8_t accID = 0; // ID du capteur
    switch (currentMenu) {
        /** @brief Logique d'entree : passage a la selection de profil */
        case MENU_WELCOME:
            RefreshNeeded = true; // Demande un rafraichissement
            currentMenu = MENU_CHOIX_PROFIL; // Passe au menu choix profil
            break;
        /** @brief Gestion du menu batterie et navigation profils */
        case MENU_BATTERIE:
            if (btn & GESTBTN_SELECT) {
                curseurBatterie ^= 1; // Change la selection
                RefreshNeeded = true; // Rafraichit l'affichage
            } else if (btn & GESTBTN_OK) {
                if (curseurBatterie == 0) {
                    currentMenu = MENU_PARAMETRE; // Va au menu parametre
                    curseurParametre = 0; // Reset le curseur
                } else {
                    currentMenu = MENU_CHOIX_PROFIL; // Retour au choix profil
                }
                RefreshNeeded = true; // Rafraichit l'affichage
            }
            break;
        /** @brief Gestion du menu parametres */
        case MENU_PARAMETRE:
            if (btn & GESTBTN_SELECT) {
                if (curseurParametre == 0) {
                    curseurParametre = 1; // Change la selection
                    RefreshNeeded = true; // Rafraichit l'affichage
                } else {
                    currentMenu = MENU_MESURE_VISUEL; // Va a la mesure visuelle
                    RefreshNeeded = true; // Rafraichit l'affichage
                }
            } else if (btn & GESTBTN_OK) {
                if (curseurParametre == 0) {
                    currentMenu = MENU_BATTERIE; // Retour au menu batterie
                } else {
                    BL_CONTROL_Off(); // Eteint le retroeclairage
                    EN_LDO_Off(); // Eteint le regulateur
                }
                RefreshNeeded = true; // Rafraichit l'affichage
            }
            break;
        /** @brief Logique de selection ou creation de profil */
        case MENU_CHOIX_PROFIL:
            if (btn & GESTBTN_SELECT) {
                profilIndex = (profilIndex + 1) % 5; // Incremente l'index de profil
                RefreshNeeded = true; // Rafraichit l'affichage
            } else if (btn & GESTBTN_OK) {
                if (profilIndex == 4) {
                    uint8_t slot = 0xFF; // Slot pour nouveau profil
                    uint8_t i;
                    for (i = 0; i < NB_PROFILS; i++) {
                        Profil *p = Profils_Get(i); // Recupere le profil
                        if (p == 0 || p->validFlag != PROFIL_VALID_FLAG) {
                            slot = i; // Trouve un slot libre
                            break;
                        }
                    }
                    if (slot == 0xFF) {
                        slot = 0; // Si aucun slot libre, prend le premier
                    }
                    appData.selectedProfil = slot; // Selectionne le profil
                    currentMenu = MENU_CONF_NB_pale; // Passe a la config pales
                } else {
                    Profil *p;
                    appData.selectedProfil = profilIndex; // Selectionne le profil existant
                    p = Profils_Get(profilIndex); // Recupere le profil
                    if (p != 0 && p->validFlag == PROFIL_VALID_FLAG) {
                        appData.nbBlades = p->nbBlades; // Charge le nombre de pales
                        appData.nbCylindres = p->nbCylindres; // Charge le nombre de cylindres
                    }
                    currentMenu = MENU_MESURE_VISUEL; // Passe a la mesure visuelle
                }
                RefreshNeeded = true; // Rafraichit l'affichage
            }
            break;
        /** @brief Logique de sauvegarde de profil */
        case MENU_SAUVEGARDE:
            lcd_set_cursor(1, 1); // Place le curseur sur la premiere ligne
            lcd_put_string("Sauver dans P1-4"); // Affiche le titre
            lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
            {
                char buf[21]; // Buffer pour l'affichage
                sprintf(buf, ">P%d  (%dH %dC)", saveIndex + 1, appData.nbBlades, appData.nbCylindres); // Prepare la chaine
                lcd_put_string(buf); // Affiche la ligne
            }
            if (btn & GESTBTN_SELECT) {
                saveIndex = (saveIndex + 1) % NB_PROFILS; // Incremente l'index de sauvegarde
                RefreshNeeded = true; // Rafraichit l'affichage
            } else if (btn & GESTBTN_OK) {
                Profils_SaveToNVM(saveIndex, appData.nbBlades, appData.nbCylindres); // Sauvegarde le profil
                appData.selectedProfil = saveIndex; // Selectionne le profil sauvegarde
                currentMenu = MENU_MESURE_VISUEL; // Passe a la mesure visuelle
                RefreshNeeded = true; // Rafraichit l'affichage
            }
            break;
        /** @brief Reglage du nombre de pales */
        case MENU_CONF_NB_pale:
            if (btn & GESTBTN_SELECT) { /* bouton SELECT      */
                appData.nbBlades = (appData.nbBlades % 4) + 1; /* 1->2->3->4->1   */
                RefreshNeeded = true; /* rafraichir ecran   */
            } else if (btn & GESTBTN_OK) { /* bouton OK          */
                currentMenu = MENU_CONF_NB_CYLINDRE; /* etape suivante     */
                RefreshNeeded = true;
            }
            break;
        /** @brief Reglage du nombre de cylindres */
        case MENU_CONF_NB_CYLINDRE:
            if (btn & GESTBTN_SELECT) {
                if (++appData.nbCylindres > 7)
                    appData.nbCylindres = 4; // Remet a 4 si depasse 7
                RefreshNeeded = 1; // Rafraichit l'affichage
            } else if (btn & GESTBTN_OK) {
                currentMenu = MENU_SAUVEGARDE; // Passe a la sauvegarde
                saveIndex = appData.selectedProfil; // Propose le profil courant
                RefreshNeeded = 1; // Rafraichit l'affichage
            }
            break;
        /** @brief Mesure visuelle du RPM */
        case MENU_MESURE_VISUEL:
            if (!captureStarted) {
                captureStarted = true; // Demarre la capture
                appData.captureIndex = 0; // Reset l'index de capture
                appData.rpmCaptureActive = true; // Active la capture
                CFGCONbits.ICACLK = 0; // Configure le timer
                DRV_TMR1_Start(); // Demarre le timer
                DRV_IC0_Start(); // Demarre la capture
            }
            static uint16_t lostCaptureCounter = 0; // Compteur de perte de capture
            static uint8_t lastCaptureIndex = 0; // Dernier index de capture
            uint8_t i = appData.captureIndex; // Index courant
            uint8_t j = (i + RPM_CAPTURE_BUFFER_SIZE - 1) % RPM_CAPTURE_BUFFER_SIZE; // Index precedent
            uint8_t k = (j + RPM_CAPTURE_BUFFER_SIZE - 1) % RPM_CAPTURE_BUFFER_SIZE; // Index encore precedent
            uint32_t delta = appData.captureBuffer[j] - appData.captureBuffer[k]; // Difference de temps
            if (delta != 0 && appData.nbBlades != 0) {
                appData.rpm = (60UL * TIMER_FREQ) / (delta * appData.nbBlades); // Calcule le RPM
            }
            if (i == lastCaptureIndex) {
                lostCaptureCounter = lostCaptureCounter + 1; // Incremente le compteur de perte
                if (lostCaptureCounter > 100) {
                    if (appData.rpm != 0) {
                        appData.rpm = 0; // Met le RPM a zero si perte
                        RefreshNeeded = true; // Rafraichit l'affichage
                    }
                }
            } else {
                lostCaptureCounter = 0; // Reset le compteur de perte
                lastCaptureIndex = i; // Met a jour l'index
            }
            if ((uint16_t) appData.rpm != lastRpm) {
                lastRpm = (uint16_t) appData.rpm; // Met a jour le dernier RPM
                RefreshNeeded = true; // Rafraichit l'affichage
            }
            if (btn & GESTBTN_SELECT) {
                captureStarted = false; // Arrete la capture
                appData.rpmCaptureActive = false; // Desactive la capture
                DRV_IC0_Stop(); // Arrete la capture
                DRV_TMR1_Stop(); // Arrete le timer
                currentMenu = MENU_MESURE_AUDIO; // Passe a la mesure audio
                RefreshNeeded = true; // Rafraichit l'affichage
            }
            break;
        /** @brief Mesure audio du RPM */
        case MENU_MESURE_AUDIO:
            if (btn & GESTBTN_SELECT) {
                currentMenu = MENU_MESURE_VIBRATION; // Passe a la mesure vibration
                RefreshNeeded = true; // Rafraichit l'affichage
            }
            break;
        /** @brief Mesure vibration du RPM */
        case MENU_MESURE_VIBRATION:
            if (accInitDone == 0) {
                SPI_ConfigureAcc(); // Configure l'accelerometre
                LIS2HH12_Init(); // Initialise le capteur
                accID = LIS2HH12_ReadID(); // Lit l'ID du capteur
                if (accID == 0x41) {
                    LIFE_LED_Toggle(); // Indique la detection
                }
                accInitDone = 1; // Marque l'init comme faite
            }
            accTick = accTick + 1; // Incremente le compteur
            if (accTick >= 50) { // Lecture toutes les 50 iterations
                LIS2HH12_ReadXYZ(&accX, &accY, &accZ); // Lit les axes
                accTick = 0; // Reset le compteur
            }
            if (btn & GESTBTN_SELECT) {
                currentMenu = MENU_PARAMETRE; // Retour au menu parametre
                curseurParametre = 0; // Reset le curseur
                RefreshNeeded = true; // Rafraichit l'affichage
            }
            break;
        default:
            break;
    }
    if (RefreshNeeded) {
        Menu_Display(); // Rafraichit l'affichage
        RefreshNeeded = false; // Reset le flag
    }
}
