#include "LCD.h"
#include "GestBtn.h"
#include "menu.h"
#include <stdio.h>
#include "app.h"
#include "system_definitions.h"
#include "ProfilStorage.h"
#include "LIS2HH12.h"

static MenuState currentMenu = MENU_WELCOME;
static uint8_t profilIndex = 0; // 0 à 4 (4 = Nouveau)
static uint8_t saveIndex = 0; // 0 à 3
static uint8_t curseurParametre = 0;
static uint8_t curseurBatterie = 0;

void Menu_Display(void) {
    lcd_set_cursor(1, 1);
    lcd_put_string("                    ");
    lcd_set_cursor(1, 2);
    lcd_put_string("                    ");

    switch (currentMenu) {
            /* --- Écrans principaux ------------------------------------ */
        case MENU_WELCOME:
            lcd_set_cursor(1, 1);
            lcd_put_string("Capteur RPM");
            lcd_set_cursor(1, 2);
            lcd_put_string("ETML-ES  LMS");
            break;

        case MENU_BATTERIE:
            if (curseurBatterie == 0) {
                lcd_set_cursor(1, 1);
                lcd_put_string(">Batterie = XXX");
                lcd_set_cursor(1, 2);
                lcd_put_string(" Gestion profils");
            } else {
                lcd_set_cursor(1, 1);
                lcd_put_string(" Batterie = XXX");
                lcd_set_cursor(1, 2);
                lcd_put_string(">Gestion profils");
            }
            break;

        case MENU_PARAMETRE:
            if (curseurParametre == 0) {
                lcd_set_cursor(1, 1);
                lcd_put_string(">Parametre");
                lcd_set_cursor(1, 2);
                lcd_put_string("  Eteindre");
            } else {
                lcd_set_cursor(1, 1);
                lcd_put_string(" Parametre");
                lcd_set_cursor(1, 2);
                lcd_put_string(">Eteindre");
            }
            break;

            /* --- Choix / sauvegarde de profil ------------------------- */
        case MENU_CHOIX_PROFIL:
            lcd_set_cursor(1, 1);
            lcd_put_string("Choisir Profil");
            lcd_set_cursor(1, 2);
            switch (profilIndex) {
                case 0: lcd_put_string(">1 2 3 4 Nouveau");
                    break;
                case 1: lcd_put_string(" 1>2 3 4 Nouveau");
                    break;
                case 2: lcd_put_string(" 1 2>3 4 Nouveau");
                    break;
                case 3: lcd_put_string(" 1 2 3>4 Nouveau");
                    break;
                case 4: lcd_put_string(" 1 2 3 4>Nouveau");
                    break;
            }
            break;

        case MENU_SAUVEGARDE:
            lcd_set_cursor(1, 1);
            lcd_put_string("Sauvegarder sous");
            lcd_set_cursor(1, 2);
            switch (saveIndex) {
                case 0: lcd_put_string(">1 2 3 4");
                    break;
                case 1: lcd_put_string(" 1>2 3 4");
                    break;
                case 2: lcd_put_string(" 1 2>3 4");
                    break;
                case 3: lcd_put_string(" 1 2 3>4");
                    break;
            }
            break;

            /* --- Configuration pales / cylindres ---------------------- */
        case MENU_CONF_NB_HELICE:
        {
            char buf[21];
            lcd_set_cursor(1, 1);
            lcd_put_string("Nbr Helices :");
            lcd_set_cursor(1, 2);
            sprintf(buf, "> %d", appData.nbBlades);
            lcd_put_string(buf);
            break;
        }

        case MENU_CONF_NB_CYLINDRE:
        {
            char buf[21];
            lcd_set_cursor(1, 1);
            lcd_put_string("Nbr Cylindres:");
            lcd_set_cursor(1, 2);
            sprintf(buf, "> %d", appData.nbCylindres);
            lcd_put_string(buf);
            break;
        }

            /* --- Mesures ---------------------------------------------- */
        case MENU_MESURE_VISUEL:
        {
            char buf[21];
            uint8_t profilNum;
            Profil *p;
            profilNum = appData.selectedProfil + 1; // <= toujours le bon numéro
            p = Profils_Get(appData.selectedProfil);

            lcd_set_cursor(1, 1);
            sprintf(buf, "Visuel : %5u RPM", (uint16_t) appData.rpm);
            lcd_put_string(buf);

            lcd_set_cursor(1, 2);
            if (p != 0 && p->validFlag == PROFIL_VALID_FLAG) {
                sprintf(buf, "Profil%d : %dH  %dC", profilNum, p->nbBlades, p->nbCylindres);
            } else {
                sprintf(buf, "Profil%d : --   --", profilNum); // <= toujours le bon numéro
            }
            lcd_put_string(buf);
            break;
        }

        case MENU_MESURE_AUDIO:
            lcd_set_cursor(1, 1);
            lcd_put_string("Mesure Audio");
            lcd_set_cursor(1, 2);
            lcd_put_string("xxxx RPM / Cyl.");
            break;

        case MENU_MESURE_VIBRATION:
            lcd_set_cursor(1, 1);
            lcd_put_string("Mesure Vibration");
            lcd_set_cursor(1, 2);
            lcd_put_string("xxxx RPM / Cyl.");
            break;
    }
}

#define TIMER_FREQ 10000000UL  // 10 MHz

void Menu_Task(void) {
    uint8_t btn = GestBtn_Scan();
    static uint8_t RefreshNeeded = 0;
    static bool captureStarted = false;
    static uint16_t lastRpm;
    static uint8_t accInitDone = 0;
    static uint16_t accTick = 0;
    static int16_t accX = 0;
    static int16_t accY = 0;
    static int16_t accZ = 0;
    static uint8_t accID = 0;
    switch (currentMenu) {
        case MENU_WELCOME:
            RefreshNeeded = true;
            currentMenu = MENU_CHOIX_PROFIL;
            break;

        case MENU_BATTERIE:
            if (btn & GESTBTN_SELECT) {
                curseurBatterie ^= 1;
                RefreshNeeded = true;
            } else if (btn & GESTBTN_OK) {
                if (curseurBatterie == 0) {
                    currentMenu = MENU_PARAMETRE;
                    curseurParametre = 0;
                } else {
                    currentMenu = MENU_CHOIX_PROFIL;
                }
                RefreshNeeded = true;
            }
            break;

        case MENU_PARAMETRE:
            if (btn & GESTBTN_SELECT) {
                if (curseurParametre == 0) {
                    curseurParametre = 1;
                    RefreshNeeded = true;
                } else {
                    currentMenu = MENU_MESURE_VISUEL;
                    RefreshNeeded = true;
                }
            } else if (btn & GESTBTN_OK) {
                if (curseurParametre == 0) {
                    currentMenu = MENU_BATTERIE;
                } else {
                    BL_CONTROL_Off();
                    EN_LDO_Off();
                }
                RefreshNeeded = true;
            }
            break;

            /* ------------------------------------------------------------------ */
            /*  Choix d?un profil (P1-P4) ou création d?un nouveau                */
            /* ------------------------------------------------------------------ */
            // Dans MENU_CHOIX_PROFIL
        case MENU_CHOIX_PROFIL:
            if (btn & GESTBTN_SELECT) {
                profilIndex = (profilIndex + 1) % 5;
                RefreshNeeded = true;
            } else if (btn & GESTBTN_OK) {
                if (profilIndex == 4) {
                    uint8_t slot = 0xFF;
                    uint8_t i;
                    for (i = 0; i < NB_PROFILS; i++) {
                        Profil *p = Profils_Get(i);
                        if (p == 0 || p->validFlag != PROFIL_VALID_FLAG) {
                            slot = i;
                            break;
                        }
                    }
                    if (slot == 0xFF) {
                        slot = 0;
                    }
                    appData.selectedProfil = slot;
                    currentMenu = MENU_CONF_NB_HELICE;
                } else {
                    Profil *p;
                    appData.selectedProfil = profilIndex; // <-- TOUJOURS affecté
                    p = Profils_Get(profilIndex);
                    if (p != 0 && p->validFlag == PROFIL_VALID_FLAG) {
                        appData.nbBlades = p->nbBlades;
                        appData.nbCylindres = p->nbCylindres;
                    }
                    currentMenu = MENU_MESURE_VISUEL;
                }
                RefreshNeeded = true;
            }
            break;


        case MENU_SAUVEGARDE:
            lcd_set_cursor(1, 1);
            lcd_put_string("Sauver dans P1-4");

            lcd_set_cursor(1, 2);
        {
            char buf[21];
            sprintf(buf, ">P%d  (%dH %dC)", saveIndex + 1, appData.nbBlades, appData.nbCylindres);
            lcd_put_string(buf);
        }

            if (btn & GESTBTN_SELECT) {
                saveIndex = (saveIndex + 1) % NB_PROFILS;
                RefreshNeeded = true;
            } else if (btn & GESTBTN_OK) {
                Profils_SaveToNVM(saveIndex, appData.nbBlades, appData.nbCylindres);
                appData.selectedProfil = saveIndex;
                currentMenu = MENU_MESURE_VISUEL;
                RefreshNeeded = true;
            }
            break;


            /* ------------------------------------------------------------------ */
            /*  Réglage du nombre de pales (1 ? 4)                                */
            /* ------------------------------------------------------------------ */
        case MENU_CONF_NB_HELICE:
            if (btn & GESTBTN_SELECT) { /* bouton SELECT      */
                appData.nbBlades = (appData.nbBlades % 4) + 1; /* 1?2?3?4?1   */
                RefreshNeeded = true; /* rafraîchir écran   */
            } else if (btn & GESTBTN_OK) { /* bouton OK          */
                currentMenu = MENU_CONF_NB_CYLINDRE; /* étape suivante     */
                RefreshNeeded = true;
            }
            break;

        case MENU_CONF_NB_CYLINDRE:
            if (btn & GESTBTN_SELECT) {
                if (++appData.nbCylindres > 7)
                    appData.nbCylindres = 4;
                RefreshNeeded = 1;
            } else if (btn & GESTBTN_OK) {
                /* on passe maintenant par l?écran de sauvegarde */
                currentMenu = MENU_SAUVEGARDE;
                saveIndex = appData.selectedProfil; /* profil proposé */
                RefreshNeeded = 1;
            }
            break;


        case MENU_MESURE_VISUEL:
            if (!captureStarted) {
                captureStarted = true;
                appData.captureIndex = 0;
                appData.rpmCaptureActive = true;
                CFGCONbits.ICACLK = 0;
                DRV_TMR1_Start();
                DRV_IC0_Start();
            }

            // Variables de sécurité
            static uint16_t lostCaptureCounter = 0;
            static uint8_t lastCaptureIndex = 0;

            // Calcul RPM si assez d'échantillons
            uint8_t i = appData.captureIndex;
            uint8_t j = (i + RPM_CAPTURE_BUFFER_SIZE - 1) % RPM_CAPTURE_BUFFER_SIZE;
            uint8_t k = (j + RPM_CAPTURE_BUFFER_SIZE - 1) % RPM_CAPTURE_BUFFER_SIZE;

            uint32_t delta = appData.captureBuffer[j] - appData.captureBuffer[k];

            if (delta != 0 && appData.nbBlades != 0) {
                appData.rpm = (60UL * TIMER_FREQ) / (delta * appData.nbBlades);
            }

            // Détection de perte de signal : 100 cycles sans nouvelle capture
            if (i == lastCaptureIndex) {
                lostCaptureCounter = lostCaptureCounter + 1;
                if (lostCaptureCounter > 100) {
                    if (appData.rpm != 0) {
                        appData.rpm = 0;
                        RefreshNeeded = true;
                    }
                }
            } else {
                lostCaptureCounter = 0;
                lastCaptureIndex = i;
            }

            if ((uint16_t) appData.rpm != lastRpm) {
                lastRpm = (uint16_t) appData.rpm;
                RefreshNeeded = true;
            }

            if (btn & GESTBTN_SELECT) {
                captureStarted = false;
                appData.rpmCaptureActive = false;
                DRV_IC0_Stop();
                DRV_TMR1_Stop();

                currentMenu = MENU_MESURE_AUDIO;
                RefreshNeeded = true;
            }
            break;

        case MENU_MESURE_AUDIO:
            if (btn & GESTBTN_SELECT) {
                currentMenu = MENU_MESURE_VIBRATION;
                RefreshNeeded = true;
            }
            break;

        case MENU_MESURE_VIBRATION:
            if (accInitDone == 0) {
                SPI_ConfigureAcc();
                LIS2HH12_Init();
                accID = LIS2HH12_ReadID();
                if (accID == 0x41) {
                    LIFE_LED_Toggle();
                }
                accInitDone = 1;
            }
            accTick = accTick + 1;
            if (accTick >= 50) { // lecture toutes les 50 passages (ajuste selon besoin)
                LIS2HH12_ReadXYZ(&accX, &accY, &accZ);
                accTick = 0;
            }
            if (btn & GESTBTN_SELECT) {
                currentMenu = MENU_PARAMETRE;
                curseurParametre = 0;
                RefreshNeeded = true;
            }
            break;

        default:
            break;
    }

    if (RefreshNeeded) {
        Menu_Display();
        RefreshNeeded = false;
    }
}
