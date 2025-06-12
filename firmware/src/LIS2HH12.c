/*
 * Fichier : LIS2HH12.c
 * Description : Implementation pour le controle du capteur accelerometre LIS2HH12 via SPI.
 * Auteur : LMS
 * Date : 2025-06-13
 *
 * Ce fichier contient les fonctions pour l'initialisation, la lecture et l'ecriture du LIS2HH12.
 * Toutes les chaines et commentaires sont sans accents pour compatibilite ASCII/ISO.
 */

#include "LIS2HH12.h" // Inclusion du header LIS2HH12
#include "system_config.h" // Inclusion de la configuration systeme
#include "system_definitions.h" // Inclusion des definitions systeme
#include "Mc32Spi.h" // Inclusion du module SPI
#include "Mc32Delays.h" // Inclusion des fonctions de delai
#include "peripheral/spi/plib_spi.h" // Inclusion de la bibliotheque SPI

/**
 * @brief Configure le SPI pour l'accelerometre LIS2HH12.
 *
 * @details
 * Cette fonction configure le peripherique SPI pour communiquer avec le LIS2HH12.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 */
void SPI_ConfigureAcc(void)
{
    PLIB_SPI_Disable(SPI_ID_1); // Desactive le SPI

    PLIB_SPI_BufferClear(SPI_ID_1); // Vide le buffer SPI
    PLIB_SPI_StopInIdleDisable(SPI_ID_1); // SPI actif en idle
    PLIB_SPI_PinEnable(SPI_ID_1, SPI_PIN_DATA_OUT); // Active la pin data out
    PLIB_SPI_CommunicationWidthSelect(SPI_ID_1, SPI_COMMUNICATION_WIDTH_8BITS); // 8 bits
    PLIB_SPI_BaudRateSet(SPI_ID_1, SYS_CLK_PeripheralFrequencyGet(CLK_BUS_PERIPHERAL_1), 2000000); // 2 MHz max
    PLIB_SPI_InputSamplePhaseSelect(SPI_ID_1, SPI_INPUT_SAMPLING_PHASE_AT_END); // Echantillon en fin
    PLIB_SPI_ClockPolaritySelect(SPI_ID_1, SPI_CLOCK_POLARITY_IDLE_LOW); // Polarite idle bas
    PLIB_SPI_OutputDataPhaseSelect(SPI_ID_1, SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK); // Phase donnee
    PLIB_SPI_MasterEnable(SPI_ID_1); // Mode maitre
    PLIB_SPI_FramedCommunicationDisable(SPI_ID_1); // Pas de trame
    PLIB_SPI_FIFOEnable(SPI_ID_1); // Active le FIFO

    PLIB_SPI_Enable(SPI_ID_1); // Active le SPI
}

/**
 * @brief Initialise le LIS2HH12.
 *
 * @details
 * Configure les registres de controle pour un fonctionnement standard.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 */
void LIS2HH12_Init(void)
{
    // CTRL1 : ODR = 100 Hz, mode normal, tous les axes actives
    // 0x57 = 0101 0111 => ODR = 100Hz, X/Y/Z actives
    LIS2HH12_WriteReg(0x20, 0x57);

    // CTRL2 : filtre haute frequence desactive (par defaut), on ne change rien ici

    // CTRL3 : toutes les interruptions desactivees, DRDY desactive
    LIS2HH12_WriteReg(0x22, 0x00);

    // CTRL4 : echelle +-2g, high resolution desactive (par defaut)
    LIS2HH12_WriteReg(0x23, 0x00);

    // CTRL5 : filtre FIFO, pas necessaire pour lecture simple
    LIS2HH12_WriteReg(0x24, 0x00);
}

/**
 * @brief Lit un registre du LIS2HH12 (1 octet).
 *
 * @details
 * Lit la valeur d'un registre via SPI.
 *
 * @param reg Adresse du registre a lire.
 * @return Valeur lue (1 octet).
 */
uint8_t LIS2HH12_ReadReg(uint8_t reg)
{
    uint8_t value;

    CS_ACC_Off(); // Active le chip select
    spi_write1(0x80 | reg); // 0x80 = bit read
    value = spi_read1(0xFF); // Lit la reponse
    CS_ACC_On(); // Desactive le chip select

    return value;
}

/**
 * @brief Ecrit un registre du LIS2HH12 (1 octet).
 *
 * @details
 * Ecrit une valeur dans un registre via SPI.
 *
 * @param reg Adresse du registre a ecrire.
 * @param value Valeur a ecrire.
 * @return Aucun retour.
 */
void LIS2HH12_WriteReg(uint8_t reg, uint8_t value)
{
    CS_ACC_Off(); // Active le chip select
    spi_write1(reg & 0x7F); // Write, bit 7=0
    spi_write1(value); // Ecrit la valeur
    CS_ACC_On(); // Desactive le chip select
}

/**
 * @brief Lit l'identifiant du LIS2HH12.
 *
 * @details
 * Lit le registre WHO_AM_I pour verifier la presence du capteur.
 *
 * @param Aucun parametre.
 * @return Valeur du registre WHO_AM_I.
 */
uint8_t LIS2HH12_ReadID(void)
{
    return LIS2HH12_ReadReg(LIS2HH12_WHO_AM_I_REG);
}

/**
 * @brief Lit les valeurs brutes XYZ de l'accelerometre.
 *
 * @details
 * Lit les 3 axes (X, Y, Z) et retourne les valeurs brutes.
 *
 * @param x Pointeur pour la valeur X.
 * @param y Pointeur pour la valeur Y.
 * @param z Pointeur pour la valeur Z.
 * @return Aucun retour.
 */
void LIS2HH12_ReadXYZ(int16_t *x, int16_t *y, int16_t *z)
{
    uint8_t buf[6]; // Buffer pour les donnees lues
    uint8_t i;

    CS_ACC_Off(); // Active le chip select
    spi_write1(0xC0 | LIS2HH12_OUT_X_L); // 0xC0 = read + auto-increment
    for (i = 0; i < 6; i = i + 1) {
        buf[i] = spi_read1(0xFF); // Lit chaque octet
    }
    CS_ACC_On(); // Desactive le chip select

    *x = (int16_t)((buf[1] << 8) | buf[0]); // Assemble X
    *y = (int16_t)((buf[3] << 8) | buf[2]); // Assemble Y
    *z = (int16_t)((buf[5] << 8) | buf[4]); // Assemble Z
}
