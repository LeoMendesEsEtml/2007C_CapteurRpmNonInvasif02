/*
--------------------------------------------------------
 Fichier : ProfilStorage.c
 Auteur  : leo mendes
 Date    : 2024
 Role    : Fonctions pour la gestion et le stockage des profils utilisateur en memoire NVM
--------------------------------------------------------
*/
#include "ProfilStorage.h" // Prototypes et structure Profil
#include "driver/nvm/drv_nvm.h" // Acces au driver NVM

#define NVM_ADDR_PROFILS 0xBD1FC000 // Adresse de stockage des profils en NVM
#define PAGE_SIZE         16384      // Taille d'une page NVM
#define ROW_SIZE          2048       // Taille d'une ligne NVM

// Tableau des profils en RAM, aligne pour la NVM
static Profil profils[NB_PROFILS] __attribute__((aligned(16)));
// Handle du driver NVM
static DRV_HANDLE nvmHandle = DRV_HANDLE_INVALID;

/**
 * @brief Ouvre le handle NVM si besoin.
 *
 * @details
 * Cette fonction tente d'ouvrir le driver NVM jusqu'a succes.
 */
static void NVM_Open(void)
{
    if (nvmHandle == DRV_HANDLE_INVALID) {
        while (nvmHandle == DRV_HANDLE_INVALID) {
            nvmHandle = DRV_NVM_Open(0, DRV_IO_INTENT_READWRITE); // Ouvre le driver NVM
        }
    }
}

/**
 * @brief Charge les profils depuis la memoire NVM vers la RAM.
 *
 * @details
 * Lit la zone NVM reservee aux profils et copie les donnees dans le tableau RAM.
 */
void Profils_LoadFromNVM(void)
{
    NVM_Open(); // Ouvre le driver NVM si besoin
    DRV_NVM_Read(nvmHandle, NULL, (uint8_t *)profils, NVM_ADDR_PROFILS, sizeof(profils)); // Lit la NVM
}

/**
 * @brief Sauvegarde un profil dans la memoire NVM.
 *
 * @details
 * Recharge la NVM en RAM avant modification pour ne pas perdre les autres profils.
 * Modifie le profil voulu, efface la page puis ecrit tout le tableau profils.
 *
 * @param idx Index du profil a sauvegarder
 * @param blades Nombre de pales
 * @param cyl Nombre de cylindres
 */
void Profils_SaveToNVM(uint8_t idx, uint8_t blades, uint8_t cyl)
{
    if (idx >= NB_PROFILS) {
        return; // Index hors limite
    }
    Profils_LoadFromNVM(); // Recharge la NVM en RAM avant modification
    profils[idx].nbBlades = blades; // Met a jour le nombre de pales
    profils[idx].nbCylindres = cyl; // Met a jour le nombre de cylindres
    profils[idx].validFlag = PROFIL_VALID_FLAG; // Marque comme valide
    profils[idx].reserved = 0; // Alignement
    NVM_Open(); // Ouvre le driver NVM
    DRV_NVM_Erase(nvmHandle, NULL, NVM_ADDR_PROFILS, PAGE_SIZE / ROW_SIZE); // Efface la page
    DRV_NVM_Write(nvmHandle, NULL, (uint8_t *)profils, NVM_ADDR_PROFILS, sizeof(profils)); // Ecrit la page
}

/**
 * @brief Retourne un pointeur vers le profil demande.
 *
 * @details
 * Permet d'acceder directement au profil en RAM.
 *
 * @param idx Index du profil
 * @return Pointeur vers le profil ou 0 si index invalide
 */
Profil* Profils_Get(uint8_t idx)
{
    if (idx < NB_PROFILS) {
        return &profils[idx]; // Retourne le pointeur
    } else {
        return 0; // Index hors limite
    }
}

/**
 * @brief Reinitialise tous les profils aux valeurs d'usine et sauvegarde en NVM.
 *
 * @details
 * Remet tous les profils a 2 pales, 4 cylindres, non valides, puis ecrit en NVM.
 */
void Profils_ResetAll(void)
{
    uint8_t i;
    for (i = 0; i < NB_PROFILS; i++) {
        profils[i].nbBlades = 2; // Valeur par defaut
        profils[i].nbCylindres = 4; // Valeur par defaut
        profils[i].validFlag = 0; // Non valide
        profils[i].reserved = 0; // Alignement
    }
    NVM_Open(); // Ouvre le driver NVM
    DRV_NVM_Erase(nvmHandle, NULL, NVM_ADDR_PROFILS, PAGE_SIZE / ROW_SIZE); // Efface la page
    DRV_NVM_Write(nvmHandle, NULL, (uint8_t *)profils, NVM_ADDR_PROFILS, sizeof(profils)); // Ecrit la page
}

/**
 * @brief Teste la sauvegarde et la lecture des profils en NVM.
 *
 * @details
 * Efface la page, verifie l'effacement, ecrit un profil, relit et verifie la valeur.
 *
 * @return 1 si OK, 0 ou -1 si erreur
 */
int Profils_TestSaveLoad(void)
{
    Profil tmpAvant[NB_PROFILS]; // Buffer avant ecriture
    Profil tmpApres[NB_PROFILS]; // Buffer apres ecriture
    uint8_t idx = 1; // Profil a tester
    NVM_Open(); // Ouvre le driver NVM
    DRV_NVM_Erase(nvmHandle, NULL, NVM_ADDR_PROFILS, PAGE_SIZE / ROW_SIZE); // Efface la page
    DRV_NVM_Read(nvmHandle, NULL, (uint8_t *)tmpAvant, NVM_ADDR_PROFILS, sizeof(tmpAvant)); // Lit apres effacement
    if (tmpAvant[idx].nbBlades != 0xFF ||
        tmpAvant[idx].nbCylindres != 0xFF ||
        tmpAvant[idx].validFlag != 0xFF ||
        tmpAvant[idx].reserved != 0xFF) {
        return -1; // Effacement KO
    }
    profils[idx].nbBlades = 3; // Nouvelle valeur
    profils[idx].nbCylindres = 6; // Nouvelle valeur
    profils[idx].validFlag = PROFIL_VALID_FLAG; // Marque comme valide
    profils[idx].reserved = 0; // Alignement
    DRV_NVM_Write(nvmHandle, NULL, (uint8_t *)profils, NVM_ADDR_PROFILS, sizeof(profils)); // Ecrit la page
    DRV_NVM_Read(nvmHandle, NULL, (uint8_t *)tmpApres, NVM_ADDR_PROFILS, sizeof(tmpApres)); // Lit apres ecriture
    if (tmpApres[idx].nbBlades == 3 &&
        tmpApres[idx].nbCylindres == 6 &&
        tmpApres[idx].validFlag == PROFIL_VALID_FLAG &&
        tmpApres[idx].reserved == 0) {
        return 1; // OK ecriture + effacement valides
    }
    return 0; // Ecriture KO
}
