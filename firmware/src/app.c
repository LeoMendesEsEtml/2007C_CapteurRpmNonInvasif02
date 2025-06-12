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

#include "app.h"
#include "LCD.h"
#include "GestBtn.h"
#include "PotControl.h"
#include "menu.h"
#include "ProfilStorage.h"
#include "system_config.h"

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
    .refreshNeeded = true
};

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
#define WAIT_INIT 2999  // Nombre d'itérations approximatives pour 3 secondes

void App_Timer1Callback() {
    // Compteur pour les 3 premières secondes

    static uint16_t WaitIteration = 0; // Variable statique qui conserve sa valeur entre appels
    static uint8_t InitDone = 0; // Flag pour indiquer si l'init est terminée

    GestBtn_Update();
    // Pendant les 3 premières secondes, on incrémente WaitIteration
    if ((WaitIteration <= WAIT_INIT) && (InitDone == 0)) {
        WaitIteration++; // Incrémente le compteur d'attente
    } else {
        // Si on est toujours dans l'état d'attente d'init (APP_GEN_INIT_WAIT)
        if (appData.state == APP_STATE_INIT_WAIT) {
            APP_UpdateState(APP_STATE_SERVICE_TASKS); // Change l'état de l'application
            InitDone = 1;
            WaitIteration = 0; // Réinitialise le compteur
            InitDone = 1; // Note que l'init est terminée
        } else {
            // Une fois l'init terminée, on exécute périodiquement le SERVICE_TASKS
            if (WaitIteration >= 10) {
                WaitIteration = 0; // Reset du compteur
                APP_UpdateState(APP_STATE_SERVICE_TASKS); // Demande exécution des tâches
            } else {
                WaitIteration++; // Incrémente jusqu'à 10 pour la prochaine exécution
            }
        }
    }
}
#define TIMER_FREQ_HZ     100000000UL  // 100 MHz timer base (PBCLK3)
#define PULSES_PER_REV    1            // Nombre de fronts par tour

void DRV_IC3_Callback(void) {
    if (!appData.rpmCaptureActive) {
        return;
    }

    if (!DRV_IC0_BufferIsEmpty()) {
        uint32_t cap = DRV_IC0_Capture32BitDataRead();
        uint8_t i = appData.captureIndex;

        appData.captureBuffer[i] = cap;
        i = i + 1;
        if (i >= RPM_CAPTURE_BUFFER_SIZE) {
            i = 0;
        }

        appData.captureIndex = i;
    }
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/**
 * @brief Met à jour l'état actuel de l'application.
 * @author LMS - VCO
 * @date 2025-01-02
 * 
 * @param Newstate Nouveau état à affecter à l'application (type APP_STATES).
 * 
 * @details Cette fonction met à jour la variable globale `appData.state` avec
 *          la valeur de l'état fourni en paramètre.
 */
void APP_UpdateState(APP_STATES Newstate) {
    // Met à jour l'état de l'application avec le nouvel état spécifié
    appData.state = Newstate;
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

void APP_Initialize(void) {
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    //PLIB_TMR_Period32BitSet(TMR_ID_2, 0xFFFFFFFF); // timer libre
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks(void) {
    uint8_t val;

    switch (appData.state) {
        case APP_STATE_INIT:
        {
            BL_CONTROL_On();
            Profils_LoadFromNVM();


            SPI_ConfigurePot();
            lcd_init();
            GestBtn_Init();
            lcd_set_cursor(1, 1);
            lcd_put_string("Capteur RPM");
            lcd_set_cursor(1, 2);
            lcd_put_string("LMS");

            DRV_TMR0_Start();

            EN_LDO_On();
            IR_EN_Off();

            lcd_set_cursor(1, 1);
            Pot_Write(POT_INDEX_U5_WIPER0, 70);
            Pot_Write(POT_INDEX_U3_WIPER0, 30);
            Pot_Write(POT_INDEX_U3_WIPER1, 250);

            if (Pot_Read(POT_INDEX_U3_WIPER0, &val)) {
                lcd_set_cursor(1, 1);
                lcd_printf("U3 W0: %3d", val);
            } else {
                lcd_put_string("U3 W0: ERR");
            }

            lcd_set_cursor(1, 2);
            if (Pot_Read(POT_INDEX_U3_WIPER1, &val)) {
                lcd_printf("U3 W1: %3d", val);
            } else {
                lcd_put_string("U3 W1: ERR");
            }

            APP_UpdateState(APP_STATE_INIT_WAIT);
            break;
        }

        case APP_STATE_INIT_WAIT:
        {
            // Tout est géré par le callback Timer1
            break;
        }

        case APP_STATE_WAIT:
        {
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
#ifdef DEBUG_MEMORY
            Profils_TestSaveLoad();
#endif
            Menu_Task();
            APP_UpdateState(APP_STATE_WAIT);
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
