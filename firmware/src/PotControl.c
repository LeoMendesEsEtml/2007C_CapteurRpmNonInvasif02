/*
--------------------------------------------------------
 Fichier : PotControl.c
 Auteur  : leo mendes
 Date    : 2024
 Role    : Fonctions de gestion du potentiometre numerique
--------------------------------------------------------
*/
// Inclusion du header de gestion du potentiometre
#include "PotControl.h" // Prototypes et definitions du potentiometre
// Inclusion du header SPI
#include "Mc32Spi.h" // Fonctions SPI
// Inclusion de la configuration systeme
#include "system_config.h" // Configuration systeme
// Inclusion des definitions systeme
#include "system_definitions.h" // Definitions systeme
#include <stddef.h> // Pour NULL
// Inclusion de la librairie SPI
#include "peripheral/spi/plib_spi.h" // Fonctions SPI Harmony
// Inclusion du header pour les delais
#include "Mc32Delays.h" // Fonctions de delais

/**
 * @brief Configure le peripherique SPI pour le potentiometre.
 *
 * @details
 * Cette fonction initialise et configure le module SPI1 pour la communication
 * avec le potentiometre numerique. Elle regle la frequence, la largeur, la polarite,
 * et active le module SPI.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 */
void SPI_ConfigurePot(void)
{
    PLIB_SPI_Disable(SPI_ID_1); // Desactive SPI1 avant configuration
    PLIB_SPI_BufferClear(SPI_ID_1); // Vide le buffer SPI1
    PLIB_SPI_StopInIdleDisable(SPI_ID_1); // SPI actif meme en idle
    PLIB_SPI_PinEnable(SPI_ID_1, SPI_PIN_DATA_OUT); // Active la pin data out
    PLIB_SPI_CommunicationWidthSelect(SPI_ID_1, SPI_COMMUNICATION_WIDTH_8BITS); // 8 bits
    PLIB_SPI_BaudRateSet(SPI_ID_1, SYS_CLK_PeripheralFrequencyGet(CLK_BUS_PERIPHERAL_1), 5000000); // 5 MHz
    PLIB_SPI_InputSamplePhaseSelect(SPI_ID_1, SPI_INPUT_SAMPLING_PHASE_AT_END); // Echantillon en fin de cycle
    PLIB_SPI_ClockPolaritySelect(SPI_ID_1, SPI_CLOCK_POLARITY_IDLE_LOW); // Polarite idle bas
    PLIB_SPI_OutputDataPhaseSelect(SPI_ID_1, SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK); // Phase active
    PLIB_SPI_MasterEnable(SPI_ID_1); // Mode maitre
    PLIB_SPI_FramedCommunicationDisable(SPI_ID_1); // Pas de trame
    PLIB_SPI_FIFOEnable(SPI_ID_1); // Active le FIFO
    PLIB_SPI_Enable(SPI_ID_1); // Active SPI1
}

/**
 * @brief Ecrit une valeur sur le potentiometre numerique.
 *
 * @details
 * Cette fonction permet d'ecrire une valeur sur un des wipers du potentiometre.
 * Elle selectionne le bon chip select selon l'index, puis envoie la commande et la valeur.
 *
 * @param index Index du wiper a ecrire (0, 1 ou 2)
 * @param value Valeur a ecrire sur le wiper
 * @return Aucun retour.
 */
void Pot_Write(uint8_t index, uint8_t value)
{
    if (index >= POT_TOTAL) {
        return; // Index hors limite, ne fait rien
    }
    if (index == POT_INDEX_U3_WIPER0) {
        CS_POT_1_Off(); // Active le chip select 1
        spi_write1(0x00); // Commande pour wiper 0
        spi_write1(value); // Envoie la valeur
        CS_POT_1_On(); // Desactive le chip select 1
    }
    else if (index == POT_INDEX_U3_WIPER1) {
        CS_POT_1_Off(); // Active le chip select 1
        spi_write1(0x10); // Commande pour wiper 1
        spi_write1(value); // Envoie la valeur
        CS_POT_1_On(); // Desactive le chip select 1
    }
    else if (index == POT_INDEX_U5_WIPER0) {
        CS_POT_2_Off(); // Active le chip select 2
        spi_write1(0x00); // Commande pour wiper 0
        spi_write1(value); // Envoie la valeur
        CS_POT_2_On(); // Desactive le chip select 2
    }
}

/**
 * @brief Lit la valeur d'un wiper du potentiometre numerique.
 *
 * @details
 * Cette fonction lit la valeur d'un wiper du potentiometre. Elle gere la selection
 * du chip select, envoie la commande de lecture, attend le delai necessaire, puis lit la valeur.
 *
 * @param index Index du wiper a lire (0 ou 1)
 * @param value Pointeur vers la variable de reception
 * @return true si lecture reussie, false sinon
 */
bool Pot_Read(uint8_t index, uint8_t* value)
{
    if (value == NULL) {
        return false; // Pointeur non valide
    }
    if (index > POT_INDEX_U3_WIPER1) {
        return false; // Lecture interdite sur MCP4131
    }
    uint8_t cmd = (index == POT_INDEX_U3_WIPER0) ? 0x0D : 0x1D; // Commande selon wiper
    // CS_POT_1_Off active le chip select 1
    CS_POT_1_Off();
    (void)spi_read1(cmd); // Envoie la commande de lecture
    delay_us(5); // Petit delai pour stabilite
    *value = spi_read1(0xFF); // Lit la valeur recue
    delay_us(10); // Delai apres lecture
    CS_POT_1_On(); // Desactive le chip select 1
    return true; // Lecture reussie
}