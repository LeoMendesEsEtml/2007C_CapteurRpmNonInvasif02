/* i2c_user.c - I2C driver bas niveau pour PIC32 MZ EF, appelable depuis gestion LCD */

#include "system_config.h" // Inclusion de la configuration systeme
#include "system_definitions.h" // Inclusion des definitions systeme
#include <peripheral/i2c/plib_i2c.h> // Inclusion de la bibliotheque I2C PLIB

#define I2C_BUS I2C_ID_1 // Selection de l'ID du bus I2C utilise
#define PBCLK_FREQ 100000000UL // Frequence du bus peripherique

/**
 * @brief Initialise le module I2C avec la vitesse souhaitee.
 *
 * @details
 * Cette fonction configure le module I2C en mode rapide (400kHz) ou standard (100kHz).
 *
 * @param fast Si true, configure en mode rapide (400kHz), sinon standard (100kHz).
 * @return Aucun retour.
 *
 * @pre Aucun prerequis specifique.
 * @post Le module I2C est pret a etre utilise.
 */
void i2c_init(bool fast)
{
    PLIB_I2C_Disable(I2C_BUS); // Desactive le module I2C

    PLIB_I2C_HighFrequencyEnable(I2C_BUS); // Active la haute frequence
    PLIB_I2C_BaudRateSet(I2C_BUS, PBCLK_FREQ, fast ? 400000 : 100000); // Definit la vitesse

    PLIB_I2C_SlaveClockStretchingEnable(I2C_BUS); // Active l'etirement d'horloge pour l'esclave
    PLIB_I2C_Enable(I2C_BUS); // Active le module I2C
}

/**
 * @brief Genere une condition de start sur le bus I2C.
 *
 * @details
 * Cette fonction attend que le bus soit libre puis genere un start.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Le module I2C doit etre initialise.
 * @post Le bus I2C est en condition de start.
 */
void i2c_start(void)
{
    while (!PLIB_I2C_BusIsIdle(I2C_BUS)); // Attend que le bus soit libre
    PLIB_I2C_MasterStart(I2C_BUS); // Genere le start
    while (!PLIB_I2C_StartWasDetected(I2C_BUS)); // Attend la detection du start
}

/**
 * @brief Genere une condition de stop sur le bus I2C.
 *
 * @details
 * Cette fonction attend que le bus soit libre puis genere un stop.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Le module I2C doit etre initialise.
 * @post Le bus I2C est en condition de stop.
 */
void i2c_stop(void)
{
    while (!PLIB_I2C_BusIsIdle(I2C_BUS)); // Attend que le bus soit libre
    PLIB_I2C_MasterStop(I2C_BUS); // Genere le stop
    while (!PLIB_I2C_StopWasDetected(I2C_BUS)); // Attend la detection du stop
}

/**
 * @brief Genere une condition de restart sur le bus I2C.
 *
 * @details
 * Cette fonction genere une condition de redemarrage sur le bus I2C.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Le module I2C doit etre initialise.
 * @post Le bus I2C est en condition de restart.
 */
void i2c_restart(void)
{
    PLIB_I2C_MasterStartRepeat(I2C_BUS); // Genere le restart
    while (!PLIB_I2C_StartWasDetected(I2C_BUS)); // Attend la detection du restart
}

/**
 * @brief ecrit un octet sur le bus I2C.
 *
 * @details
 * Cette fonction envoie un octet sur le bus I2C et retourne si l'esclave a acquitte.
 *
 * @param data Octet a envoyer.
 * @return true si acquittement reçu, false sinon.
 *
 * @pre Le bus I2C doit etre en condition de start ou restart.
 * @post L'octet est envoye sur le bus.
 */
bool i2c_write(uint8_t data)
{
    while (!PLIB_I2C_TransmitterIsReady(I2C_BUS)); // Attend que le transmetteur soit pret
    PLIB_I2C_TransmitterByteSend(I2C_BUS, data); // Envoie l'octet
    while (PLIB_I2C_TransmitterIsBusy(I2C_BUS)); // Attend la fin de la transmission
    return PLIB_I2C_TransmitterByteWasAcknowledged(I2C_BUS); // Retourne l'acquittement
}

/**
 * @brief Lit un octet sur le bus I2C.
 *
 * @details
 * Cette fonction lit un octet depuis le bus I2C et envoie un ACK ou NACK selon le parametre.
 *
 * @param ack true pour envoyer un ACK, false pour NACK.
 * @return L'octet lu.
 *
 * @pre Le bus I2C doit etre en condition de lecture.
 * @post L'octet est lu et un ACK/NACK est envoye.
 */
uint8_t i2c_read(bool ack)
{
    uint8_t val; // Variable pour stocker l'octet lu

    PLIB_I2C_MasterReceiverClock1Byte(I2C_BUS); // Lance la lecture d'un octet
    while (!PLIB_I2C_ReceivedByteIsAvailable(I2C_BUS)); // Attend que l'octet soit disponible
    val = PLIB_I2C_ReceivedByteGet(I2C_BUS); // Recupere l'octet

    PLIB_I2C_ReceivedByteAcknowledge(I2C_BUS, ack); // Envoie ACK ou NACK

    // Attendre que l'envoi de ACK/NACK soit termine
    while (!PLIB_I2C_AcknowledgeHasCompleted(I2C_BUS)); // Attend la fin de l'acquittement

    return val; // Retourne l'octet lu
}

