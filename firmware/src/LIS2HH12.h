/*
 * Fichier : LIS2HH12.h
 * Description : Interface pour le controle du capteur accelerometre LIS2HH12 via SPI.
 * Auteur : LMS
 * Date : 2025-06-13
 *
 * Ce fichier definit les constantes, prototypes et fonctions pour l'utilisation du LIS2HH12.
 * Toutes les chaines et commentaires sont sans accents pour compatibilite ASCII/ISO.
 */

#ifndef _LIS2HH12_H_
#define _LIS2HH12_H_

#include <stdint.h> // Inclusion des types entiers standard
#include <stdbool.h> // Inclusion du type booleen standard

#define LIS2HH12_WHO_AM_I_REG 0x0F // Adresse du registre WHO_AM_I
#define LIS2HH12_WHO_AM_I_RESP 0x41 // Valeur attendue du registre WHO_AM_I

// Registres axes
#define LIS2HH12_OUT_X_L 0x28 // Registre X bas
#define LIS2HH12_OUT_X_H 0x29 // Registre X haut
#define LIS2HH12_OUT_Y_L 0x2A // Registre Y bas
#define LIS2HH12_OUT_Y_H 0x2B // Registre Y haut
#define LIS2HH12_OUT_Z_L 0x2C // Registre Z bas
#define LIS2HH12_OUT_Z_H 0x2D // Registre Z haut

/**
 * @brief Configure le SPI pour l'accelerometre LIS2HH12.
 *
 * @details
 * Cette fonction configure le peripherique SPI pour communiquer avec le LIS2HH12.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Aucun prerequis specifique.
 * @post Le SPI est pret pour l'accelerometre.
 */
void SPI_ConfigureAcc(void);

/**
 * @brief Lit un registre du LIS2HH12 (1 octet).
 *
 * @details
 * Cette fonction lit la valeur d'un registre du LIS2HH12 via SPI.
 *
 * @param reg Adresse du registre a lire.
 * @return Valeur lue (1 octet).
 *
 * @pre Le SPI doit etre configure.
 * @post Aucun effet de bord.
 */
uint8_t LIS2HH12_ReadReg(uint8_t reg);

/**
 * @brief Ecrit un registre du LIS2HH12 (1 octet).
 *
 * @details
 * Cette fonction ecrit une valeur dans un registre du LIS2HH12 via SPI.
 *
 * @param reg Adresse du registre a ecrire.
 * @param value Valeur a ecrire.
 * @return Aucun retour.
 *
 * @pre Le SPI doit etre configure.
 * @post Le registre est mis a jour.
 */
void LIS2HH12_WriteReg(uint8_t reg, uint8_t value);

/**
 * @brief Lit l'identifiant du LIS2HH12.
 *
 * @details
 * Cette fonction lit le registre WHO_AM_I pour verifier la presence du capteur.
 *
 * @param Aucun parametre.
 * @return Valeur du registre WHO_AM_I.
 *
 * @pre Le SPI doit etre configure.
 * @post Aucun effet de bord.
 */
uint8_t LIS2HH12_ReadID(void);

/**
 * @brief Lit les valeurs brutes XYZ de l'accelerometre.
 *
 * @details
 * Cette fonction lit les 3 axes (X, Y, Z) du LIS2HH12 et retourne les valeurs brutes.
 *
 * @param x Pointeur pour la valeur X.
 * @param y Pointeur pour la valeur Y.
 * @param z Pointeur pour la valeur Z.
 * @return Aucun retour.
 *
 * @pre Le SPI doit etre configure.
 * @post Les valeurs des axes sont mises a jour.
 */
void LIS2HH12_ReadXYZ(int16_t *x, int16_t *y, int16_t *z);

/**
 * @brief Initialise le LIS2HH12.
 *
 * @details
 * Cette fonction configure les registres de controle du LIS2HH12 pour un fonctionnement standard.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Le SPI doit etre configure.
 * @post Le capteur est initialise.
 */
void LIS2HH12_Init(void);

#endif
