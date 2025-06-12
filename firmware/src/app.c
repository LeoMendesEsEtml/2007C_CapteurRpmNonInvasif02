/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"           // Inclusion du header principal de l'application
#include "LCD.h"           // Inclusion du module d'affichage LCD
#include "GestBtn.h"       // Inclusion du module de gestion des boutons
#include "PotControl.h"    // Inclusion du module de controle du potentiometre
#include "menu.h"          // Inclusion du module de gestion des menus
#include "ProfilStorage.h" // Inclusion du module de stockage des profils
#include "system_config.h" // Inclusion de la configuration systeme

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
 */

APP_DATA appData = {
    .state = 0,
    .currentMenu = 0,
    .rpmCaptureActive = false,
    .captureIndex = 0,
    .rpm = 0,
    .nbBlades = 2,
    .refreshNeeded = true};

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
#define WAIT_INIT 2999 // Nombre d'iterations approximatives pour 3 secondes

// Callback du Timer1, gere l'attente d'initialisation et l'execution periodique des taches
/**
 * @brief Callback du Timer1 pour la gestion de l'initialisation et des taches periodiques.
 *
 * @details
 * Cette fonction utilise un compteur pour attendre 3 secondes apres le demarrage,
 * puis execute periodiquement les taches de service. Elle met a jour l'etat de l'application
 * en consequence.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Le systeme doit etre initialise avant d'appeler cette fonction.
 * @post L'etat de l'application est mis a jour selon l'avancement de l'initialisation.
 */
void App_Timer1Callback()
{
    // Compteur pour les 3 premieres secondes

    static uint16_t WaitIteration = 0; // Variable statique qui conserve sa valeur entre appels
    static uint8_t InitDone = 0;       // Flag pour indiquer si l'init est terminee

    GestBtn_Update(); // Met a jour l'etat des boutons
    // Pendant les 3 premieres secondes, on incremente WaitIteration
    if ((WaitIteration <= WAIT_INIT) && (InitDone == 0))
    {
        WaitIteration++; // Incremente le compteur d'attente
    }
    else
    {
        // Si on est toujours dans l'etat d'attente d'init (APP_GEN_INIT_WAIT)
        if (appData.state == APP_STATE_INIT_WAIT)
        {
            APP_UpdateState(APP_STATE_SERVICE_TASKS); // Change l'etat de l'application
            InitDone = 1;                             // Note que l'init est terminee
            WaitIteration = 0;                        // Reinitialise le compteur
            InitDone = 1;                             // Note que l'init est terminee
        }
        else
        {
            // Une fois l'init terminee, on execute periodiquement le SERVICE_TASKS
            if (WaitIteration >= 10)
            {
                WaitIteration = 0;                        // Reset du compteur
                APP_UpdateState(APP_STATE_SERVICE_TASKS); // Demande execution des tâches
            }
            else
            {
                WaitIteration++; // Incremente jusqu'a 10 pour la prochaine execution
            }
        }
    }
}
#define TIMER_FREQ_HZ 100000000UL // 100 MHz timer base (PBCLK3)
#define PULSES_PER_REV 1          // Nombre de fronts par tour

/**
 * @brief Callback pour la capture d'impulsions RPM.
 *
 * @details
 * Cette fonction lit les valeurs capturees par l'input capture et les stocke dans un buffer circulaire
 * si la capture RPM est active.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre La capture RPM doit etre active.
 * @post Le buffer de capture est mis a jour avec la nouvelle valeur.
 */
void DRV_IC3_Callback(void)
{
    if (!appData.rpmCaptureActive)
    {
        return; // Si la capture n'est pas active, on quitte
    }

    if (!DRV_IC0_BufferIsEmpty())
    {
        uint32_t cap = DRV_IC0_Capture32BitDataRead(); // Lit la valeur capturee
        uint8_t i = appData.captureIndex;              // Recupere l'index courant du buffer

        appData.captureBuffer[i] = cap; // Stocke la valeur dans le buffer
        i = i + 1;                      // Incremente l'index
        if (i >= RPM_CAPTURE_BUFFER_SIZE)
        {
            i = 0; // Revient au debut du buffer si necessaire
        }

        appData.captureIndex = i; // Met a jour l'index du buffer
    }
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/**
 * @brief Met a jour l'etat actuel de l'application.
 *
 * @details
 * Cette fonction met a jour la variable globale `appData.state` avec
 * la valeur de l'etat fourni en parametre.
 *
 * @param Newstate Nouveau etat a affecter a l'application (type APP_STATES).
 * @return Aucun retour.
 *
 * @pre Aucun prerequis specifique.
 * @post L'etat de l'application est mis a jour.
 */
void APP_UpdateState(APP_STATES Newstate)
{
    appData.state = Newstate; // Met a jour l'etat de l'application avec le nouvel etat specifie
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

/**
 * @brief Initialise l'application et place la machine d'etat dans son etat initial.
 *
 * @details
 * Cette fonction initialise l'etat de l'application a APP_STATE_INIT.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Le systeme doit etre initialise avant d'appeler cette fonction.
 * @post L'application est prete a demarrer.
 */
void APP_Initialize(void)
{
    appData.state = APP_STATE_INIT; // Place la machine d'etat dans son etat initial
    // PLIB_TMR_Period32BitSet(TMR_ID_2, 0xFFFFFFFF); // timer libre (commente)
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

/**
 * @brief Fonction principale de la machine d'etat de l'application.
 *
 * @details
 * Cette fonction gere les differents etats de l'application et execute les actions
 * associees a chaque etat.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre L'application doit etre initialisee.
 * @post Les actions correspondant a l'etat courant sont executees.
 */
void APP_Tasks(void)
{
    uint8_t val; // Variable pour stocker la valeur lue

    switch (appData.state)
    {
    case APP_STATE_INIT:
    {
        BL_CONTROL_On();       // Allume le retroeclairage
        Profils_LoadFromNVM(); // Charge les profils depuis la memoire non volatile

        SPI_ConfigurePot();            // Configure le potentiometre via SPI
        lcd_init();                    // Initialise l'ecran LCD
        GestBtn_Init();                // Initialise la gestion des boutons
        lcd_set_cursor(1, 1);          // Place le curseur sur la premiere ligne
        lcd_put_string("Capteur RPM"); // Affiche le texte sur la premiere ligne
        lcd_set_cursor(1, 2);          // Place le curseur sur la deuxieme ligne
        lcd_put_string("LMS");         // Affiche le texte sur la deuxieme ligne

        DRV_TMR0_Start(); // Demarre le timer principal

        EN_LDO_On(); // Active le LDO
        IR_EN_Off(); // Desactive l'emetteur IR

        lcd_set_cursor(1, 1);                // Replace le curseur sur la premiere ligne
        Pot_Write(POT_INDEX_U5_WIPER0, 70);  // Definit la valeur du potentiometre U5 W0
        Pot_Write(POT_INDEX_U3_WIPER0, 30);  // Definit la valeur du potentiometre U3 W0
        Pot_Write(POT_INDEX_U3_WIPER1, 250); // Definit la valeur du potentiometre U3 W1

        if (Pot_Read(POT_INDEX_U3_WIPER0, &val))
        {
            lcd_set_cursor(1, 1);          // Place le curseur sur la premiere ligne
            lcd_printf("U3 W0: %3d", val); // Affiche la valeur lue
        }
        else
        {
            lcd_put_string("U3 W0: ERR"); // Affiche une erreur si la lecture echoue
        }

        lcd_set_cursor(1, 2); // Place le curseur sur la deuxieme ligne
        if (Pot_Read(POT_INDEX_U3_WIPER1, &val))
        {
            lcd_printf("U3 W1: %3d", val); // Affiche la valeur lue
        }
        else
        {
            lcd_put_string("U3 W1: ERR"); // Affiche une erreur si la lecture echoue
        }

        APP_UpdateState(APP_STATE_INIT_WAIT); // Passe a l'etat d'attente d'initialisation
        break;
    }

    case APP_STATE_INIT_WAIT:
    {
        // Tout est gere par le callback Timer1
        break;
    }

    case APP_STATE_WAIT:
    {
        break;
    }

    case APP_STATE_SERVICE_TASKS:
    {
#ifdef DEBUG_MEMORY
        Profils_TestSaveLoad(); // Teste la sauvegarde/lecture des profils (debug)
#endif
        Menu_Task();                     // Execute la tâche du menu
        APP_UpdateState(APP_STATE_WAIT); // Passe a l'etat d'attente
        break;
    }

    default:
    {
        // Erreur inattendue
        break;
    }
    }
}

/*******************************************************************************
 End of File
 */
