/*
--------------------------------------------------------
 Fichier : PotControl.h
 Auteur  : leo mendes
 Date    : 2024
 Role    : Declarations et prototypes pour la gestion du potentiometre numerique
--------------------------------------------------------*/

#ifndef _POTCONTROL_H_
#define _POTCONTROL_H_

#include <stdint.h> // Types entiers standard
#include <stdbool.h> // Type bool

// Index du wiper 0 du MCP4231 sur CS_POT_1_
#define POT_INDEX_U3_WIPER0   0
// Index du wiper 1 du MCP4231 sur CS_POT_1_
#define POT_INDEX_U3_WIPER1   1
// Index du wiper 0 du MCP4131 sur CS_POT_2_
#define POT_INDEX_U5_WIPER0   2
// Nombre total de wipers geres
#define POT_TOTAL 3

/**
 * @brief Ecrit une valeur sur un wiper du potentiometre numerique.
 *
 * @param index Index du wiper a ecrire (0, 1 ou 2)
 * @param value Valeur a ecrire
 */
void Pot_Write(uint8_t index, uint8_t value);

/**
 * @brief Lit la valeur d'un wiper du potentiometre numerique.
 *
 * @param index Index du wiper a lire (0 ou 1)
 * @param value Pointeur vers la variable de reception
 * @return true si lecture reussie, false sinon
 */
bool Pot_Read(uint8_t index, uint8_t* value);

/**
 * @brief Configure le peripherique SPI pour le potentiometre.
 */
void SPI_ConfigurePot(void);

#endif
