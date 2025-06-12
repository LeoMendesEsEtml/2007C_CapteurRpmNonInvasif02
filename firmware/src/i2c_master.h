/*--------------------------------------------------------*/
/*  i2c_user.h  ? driver I²C bas niveau (PLIB)            */
/*  Adapté PIC32 MZ EF ? utilisable pour gestion LCD      */
/*--------------------------------------------------------*/
#ifndef I2C_USER_H
#define I2C_USER_H

#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
#include "system_config.h"
#include "system_definitions.h"
#include <peripheral/i2c/plib_i2c.h>

/* === Configuration du module I2C ======================= */
#define I2C_BUS I2C_ID_1

/* === Prototypes des fonctions ========================== */
void     i2c_init(bool fast);
void     i2c_start(void);
void     i2c_stop(void);
void     i2c_restart(void);
bool     i2c_write(uint8_t data);
uint8_t  i2c_read(bool ack);

#endif /* I2C_USER_H */
