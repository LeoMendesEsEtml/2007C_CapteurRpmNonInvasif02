#ifndef PROFIL_STORAGE_H
#define PROFIL_STORAGE_H

#include <stdint.h>
#include <stdbool.h>

#define NB_PROFILS 4
#define PROFIL_VALID_FLAG 0xA5

// Structure alignée sur 4 octets pour écriture en NVM
typedef struct {
    uint8_t nbBlades;
    uint8_t nbCylindres;
    uint8_t validFlag;
    uint8_t reserved; // alignement
} Profil;

/**
 * @brief Initialise tous les profils avec les valeurs par défaut.
 */
void Profils_Init(void);

/**
 * @brief Charge les profils depuis la mémoire NVM.
 */
void Profils_LoadFromNVM(void);

/**
 * @brief Sauvegarde un profil spécifique dans la mémoire NVM.
 * @param index Indice du profil (0 à NB_PROFILS-1)
 * @param blades Nombre de pales
 * @param cyl Nombre de cylindres
 */
void Profils_SaveToNVM(uint8_t index, uint8_t blades, uint8_t cyl);

/**
 * @brief Retourne un pointeur vers le profil spécifié.
 * @param index Indice du profil
 * @return Pointeur vers le profil ou NULL si index invalide
 */
Profil* Profils_Get(uint8_t index);
int Profils_TestSaveLoad(void);
#endif
