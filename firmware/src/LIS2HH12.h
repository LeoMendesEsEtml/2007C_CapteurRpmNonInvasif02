#ifndef _LIS2HH12_H_
#define _LIS2HH12_H_

#include <stdint.h>
#include <stdbool.h>

#define LIS2HH12_WHO_AM_I_REG 0x0F
#define LIS2HH12_WHO_AM_I_RESP 0x41

// Registres axes
#define LIS2HH12_OUT_X_L 0x28
#define LIS2HH12_OUT_X_H 0x29
#define LIS2HH12_OUT_Y_L 0x2A
#define LIS2HH12_OUT_Y_H 0x2B
#define LIS2HH12_OUT_Z_L 0x2C
#define LIS2HH12_OUT_Z_H 0x2D

// Initialisation SPI pour LIS2HH12
void SPI_ConfigureAcc(void);

// Lecture d?un registre (1 octet)
uint8_t LIS2HH12_ReadReg(uint8_t reg);

// Écriture d?un registre (1 octet)
void LIS2HH12_WriteReg(uint8_t reg, uint8_t value);

// Lecture ID accéléro
uint8_t LIS2HH12_ReadID(void);

// Lecture brute XYZ
void LIS2HH12_ReadXYZ(int16_t *x, int16_t *y, int16_t *z);

void LIS2HH12_Init(void);

#endif
