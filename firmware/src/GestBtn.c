// GestBtn.c
#include "peripheral/ports/plib_ports.h"

#include "system_config.h"

#include "GestBtn.h"
// --- Paramètres internes de débounce ---
static const uint8_t kMaxDebounceCount = 5;

typedef enum {
    DebounceWaitChange,
    DebounceWaitStable
} E_DebounceState;

typedef struct {
    E_DebounceState state;
    uint8_t         counter;
    struct {
        uint8_t pressed : 1;  // événement pressé détecté
        uint8_t prev    : 1;  // dernière valeur brute lue
        uint8_t value   : 1;  // valeur stable après antirebond
    } bits;
} S_Switch;

// Descripteurs pour OK et SELECT
static S_Switch swOK, swSelect;

/**
 * @brief  Mécanisme de débounce, à appeler chaque tick (~1 ms).
 * @param  sw   pointeur sur le descripteur
 * @param  raw  état brut (1 = relâché, 0 = appuyé)
 */
static void debounce_switch(S_Switch *sw, bool raw)
{
    switch (sw->state) {
        case DebounceWaitChange:
            if (raw != sw->bits.prev) {
                sw->bits.prev = raw;
                sw->state      = DebounceWaitStable;
            }
            break;

        case DebounceWaitStable:
            if (raw == sw->bits.prev) {
                if (++sw->counter >= kMaxDebounceCount) {
                    sw->bits.value   = raw;
                    if (!raw)        // front descendant = appui
                        sw->bits.pressed = 1;
                    sw->state        = DebounceWaitChange;
                    sw->counter      = 0;
                }
            } else {
                sw->counter   = 0;
                sw->bits.prev = raw;
            }
            break;
    }
}

void GestBtn_Init(void)
{
    // Initialisation interne uniquement
    swOK.state        = DebounceWaitChange;
    swOK.counter      = 0;
    swOK.bits.prev    = 1;
    swOK.bits.value   = 1;
    swOK.bits.pressed = 0;

    swSelect.state        = DebounceWaitChange;
    swSelect.counter      = 0;
    swSelect.bits.prev    = 1;
    swSelect.bits.value   = 1;
    swSelect.bits.pressed = 0;
}

void GestBtn_Update(void)
{
    // 1 = relâché, 0 = appuyé
    uint8_t okState     = PB_OK_StateGet();
    uint8_t selectState = PB_SELECT_StateGet();
    bool rawOK     = false;
    bool rawSelect = false;
    
    if (okState == 0u) {
        rawOK = true;
    }

    if (selectState == 0u) {
        rawSelect = true;
    }

    debounce_switch(&swOK,     rawOK);
    debounce_switch(&swSelect, rawSelect);
}


uint8_t GestBtn_Scan(void)
{
    uint8_t mask = GESTBTN_NONE;

    if (swOK.bits.pressed) {
        mask |= GESTBTN_OK;
        swOK.bits.pressed = 0;
    }
    if (swSelect.bits.pressed) {
        mask |= GESTBTN_SELECT;
        swSelect.bits.pressed = 0;
    }
    return mask;
}
