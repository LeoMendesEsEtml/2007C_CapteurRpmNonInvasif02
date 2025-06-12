#include "ProfilStorage.h"
#include "driver/nvm/drv_nvm.h"

#define NVM_ADDR_PROFILS 0xBD1FC000
#define PAGE_SIZE         16384
#define ROW_SIZE          2048

static Profil profils[NB_PROFILS] __attribute__((aligned(16)));
static DRV_HANDLE nvmHandle = DRV_HANDLE_INVALID;

// Ouverture du handle NVM
static void NVM_Open(void)
{
    if (nvmHandle == DRV_HANDLE_INVALID) {
        while (nvmHandle == DRV_HANDLE_INVALID) {
            nvmHandle = DRV_NVM_Open(0, DRV_IO_INTENT_READWRITE);
        }
    }
}

// Lecture de la NVM vers le buffer RAM
void Profils_LoadFromNVM(void)
{
    NVM_Open();
    DRV_NVM_Read(nvmHandle, NULL, (uint8_t *)profils, NVM_ADDR_PROFILS, sizeof(profils));
}

// Écriture/Sauvegarde d?un profil en NVM (toujours toute la page)
void Profils_SaveToNVM(uint8_t idx, uint8_t blades, uint8_t cyl)
{
    if (idx >= NB_PROFILS) {
        return;
    }
    profils[idx].nbBlades = blades;
    profils[idx].nbCylindres = cyl;
    profils[idx].validFlag = PROFIL_VALID_FLAG;
    profils[idx].reserved = 0;

    NVM_Open();
    DRV_NVM_Erase(nvmHandle, NULL, NVM_ADDR_PROFILS, PAGE_SIZE / ROW_SIZE);
    DRV_NVM_Write(nvmHandle, NULL, (uint8_t *)profils, NVM_ADDR_PROFILS, sizeof(profils));
}

// Accès direct à la RAM profils
Profil* Profils_Get(uint8_t idx)
{
    if (idx < NB_PROFILS) {
        return &profils[idx];
    } else {
        return 0;
    }
}

// Reset usine manuel UNIQUEMENT SI VOULU (jamais au boot)
void Profils_ResetAll(void)
{
    uint8_t i;
    for (i = 0; i < NB_PROFILS; i++) {
        profils[i].nbBlades = 2;
        profils[i].nbCylindres = 4;
        profils[i].validFlag = 0;
        profils[i].reserved = 0;
    }
    NVM_Open();
    DRV_NVM_Erase(nvmHandle, NULL, NVM_ADDR_PROFILS, PAGE_SIZE / ROW_SIZE);
    DRV_NVM_Write(nvmHandle, NULL, (uint8_t *)profils, NVM_ADDR_PROFILS, sizeof(profils));
}



int Profils_TestSaveLoad(void)
{
    Profil tmpAvant[NB_PROFILS];
    Profil tmpApres[NB_PROFILS];
    uint8_t idx = 1; // profil 2

    // 1. Efface la page
    NVM_Open();
    DRV_NVM_Erase(nvmHandle, NULL, NVM_ADDR_PROFILS, PAGE_SIZE / ROW_SIZE);

    // 2. Relis la page après effacement
    DRV_NVM_Read(nvmHandle, NULL, (uint8_t *)tmpAvant, NVM_ADDR_PROFILS, sizeof(tmpAvant));

    // 3. Vérifie que tout est à 0xFF avant écriture
    if (tmpAvant[idx].nbBlades != 0xFF ||
        tmpAvant[idx].nbCylindres != 0xFF ||
        tmpAvant[idx].validFlag != 0xFF ||
        tmpAvant[idx].reserved != 0xFF) {
        return -1; // Erase KO
    }

    // 4. Écrit une valeur
    profils[idx].nbBlades = 3;
    profils[idx].nbCylindres = 6;
    profils[idx].validFlag = PROFIL_VALID_FLAG;
    profils[idx].reserved = 0;
    DRV_NVM_Write(nvmHandle, NULL, (uint8_t *)profils, NVM_ADDR_PROFILS, sizeof(profils));

    // 5. Relis la page après écriture
    DRV_NVM_Read(nvmHandle, NULL, (uint8_t *)tmpApres, NVM_ADDR_PROFILS, sizeof(tmpApres));

    // 6. Vérifie que les valeurs écrites sont bien en NVM
    if (tmpApres[idx].nbBlades == 3 &&
        tmpApres[idx].nbCylindres == 6 &&
        tmpApres[idx].validFlag == PROFIL_VALID_FLAG &&
        tmpApres[idx].reserved == 0) {
        return 1; // OK écriture + effacement validés
    }
    return 0; // Ecriture KO
}
