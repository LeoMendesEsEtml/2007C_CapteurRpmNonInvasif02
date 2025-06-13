/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
 *******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h> // Inclusion des definitions de types entiers standard
#include <stdbool.h> // Inclusion du type booleen standard
#include <stddef.h> // Inclusion des definitions de tailles et pointeurs standard
#include <stdlib.h> // Inclusion des fonctions utilitaires generales
#include "system_config.h" // Inclusion de la configuration systeme
#include "system_definitions.h" // Inclusion des definitions systeme

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
    // DOM-IGNORE-END 

    // *****************************************************************************
    // *****************************************************************************
    // Section: Type Definitions
    // *****************************************************************************
    // *****************************************************************************

    // *****************************************************************************

    /* Etats de l'application

      Resume:
        Enumeration des etats de l'application

      Description:
        Cette enumeration definit les etats valides de l'application.  Ces etats
        determinent le comportement de l'application a differents moments.
     */

    typedef enum {
        /* etat initial de la machine d'etats de l'application. */
        APP_STATE_INIT = 0,
        APP_STATE_WAIT,
        APP_STATE_INIT_WAIT,
        APP_STATE_SERVICE_TASKS,

        /* TODO: Definir les etats utilises par la machine d'etats de l'application. */

    } APP_STATES;

#define WAIT_INIT 2999 // Nombre d'iterations approximatives pour 3 secondes
#define RPM_CAPTURE_BUFFER_SIZE 8 // Taille du buffer de capture RPM

    // *****************************************************************************

    /* Donnees de l'application

          Resume :
            Contient les donnees de l'application

          Description :
            Cette structure contient les donnees utilisees par l'application.

          Remarques :
            Les chaines et buffers de l'application sont definis en dehors de cette structure.
     */


    typedef struct {
        uint8_t state; // etat courant de l'application
        uint8_t currentMenu; // Menu courant selectionne

        volatile bool rpmCaptureActive; // Indique si la capture RPM est active
        volatile uint32_t captureBuffer[RPM_CAPTURE_BUFFER_SIZE]; // Buffer circulaire pour les captures
        volatile uint8_t captureIndex; // Index courant dans le buffer de capture
        uint32_t rpm; // Valeur RPM calculee
        uint8_t nbBlades; // Nombre de pales
        uint8_t nbCylindres; // Nombre de cylindres
        bool refreshNeeded; // Indique si un rafraichissement de l'affichage est necessaire
        uint8_t selectedProfil; // 0-3 : profil actif
    } APP_DATA;

    extern APP_DATA appData; // Declaration de la variable globale des donnees de l'application

    // *****************************************************************************
    // Section : Routines de rappel (callbacks) de l'application
    // *****************************************************************************
    /**
     * @brief Callback du Timer1 pour la gestion de l'initialisation et des tâches periodiques.
     *
     * @details
     * Cette fonction utilise un compteur pour attendre 3 secondes apres le demarrage,
     * puis execute periodiquement les tâches de service. Elle met a jour l'etat de l'application
     * en consequence.
     *
     * @param Aucun parametre.
     * @return Aucun retour.
     *
     * @pre Le systeme doit etre initialise avant d'appeler cette fonction.
     * @post L'etat de l'application est mis a jour selon l'avancement de l'initialisation.
     */
    void App_Timer1Callback();
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
    void DRV_IC3_Callback(void);
    // *****************************************************************************
    // Section : Fonctions d'initialisation et de gestion de la machine d'etat de l'application
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
    void APP_UpdateState(APP_STATES Newstate);

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
    void APP_Initialize(void);

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
    void APP_Tasks(void);


#endif /* _APP_H */

    //DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

