/*
--------------------------------------------------------
 Fichier : ProfilStorage.h
 Auteur  : leo mendes
 Date    : 2024
 Role    : Declarations et prototypes pour la gestion et le stockage des profils utilisateur
--------------------------------------------------------*/

#ifndef PROFIL_STORAGE_H
#define PROFIL_STORAGE_H

#include <stdint.h> // Types entiers standard
#include <stdbool.h> // Type bool

// Nombre de profils utilisateur geres
#define NB_PROFILS 4
// Valeur de validation d'un profil
#define PROFIL_VALID_FLAG 0xA5

/**
 * @brief Structure de donnees pour un profil utilisateur.
 *
 * @details
 * Alignee sur 4 octets pour ecriture en NVM.
 * - nbBlades : nombre de pales
 * - nbCylindres : nombre de cylindres
 * - validFlag : drapeau de validite
 * - reserved : pour alignement
 */
typedef struct {
    uint8_t nbBlades;      // Nombre de pales
    uint8_t nbCylindres;   // Nombre de cylindres
    uint8_t validFlag;     // Drapeau de validite
    uint8_t reserved;      // Pour alignement memoire
} Profil;

/**
 * @brief Initialise tous les profils avec les valeurs par defaut.
 */
void Profils_Init(void);

/**
 * @brief Charge les profils depuis la memoire NVM.
 */
void Profils_LoadFromNVM(void);

/**
 * @brief Sauvegarde un profil specifique dans la memoire NVM.
 * @param index Indice du profil (0 a NB_PROFILS-1)
 * @param blades Nombre de pales
 * @param cyl Nombre de cylindres
 */
void Profils_SaveToNVM(uint8_t index, uint8_t blades, uint8_t cyl);

/**
 * @brief Retourne un pointeur vers le profil specifie.
 * @param index Indice du profil
 * @return Pointeur vers le profil ou NULL si index invalide
 */
Profil* Profils_Get(uint8_t index);

/**
 * @brief Teste la sauvegarde et la lecture des profils en NVM.
 * @return 1 si OK, 0 ou -1 si erreur
 */
int Profils_TestSaveLoad(void);

#endif
