/*--------------------------------------------------------*/
/*  i2c_user.h  ? driver I²C bas niveau (PLIB)            */
/*  Adapte PIC32 MZ EF ? utilisable pour gestion LCD      */
/*--------------------------------------------------------*/
#ifndef I2C_USER_H
#define I2C_USER_H

#include <stdint.h> // Inclusion des definitions de types entiers standard
#include <stdbool.h> // Inclusion du type booleen standard
#include <xc.h> // Inclusion des definitions specifiques au compilateur XC
#include "system_config.h" // Inclusion de la configuration systeme
#include "system_definitions.h" // Inclusion des definitions systeme
#include <peripheral/i2c/plib_i2c.h> // Inclusion de la bibliotheque I2C PLIB

/* === Configuration du module I2C ======================= */
#define I2C_BUS I2C_ID_1 // Selection de l'ID du bus I2C utilise

/* === Prototypes des fonctions ========================== */
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
void     i2c_init(bool fast);
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
void     i2c_start(void);
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
void     i2c_stop(void);
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
void     i2c_restart(void);
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
bool     i2c_write(uint8_t data);
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
uint8_t  i2c_read(bool ack);

#endif /* I2C_USER_H */
