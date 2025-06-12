/* i2c_user.c - I2C driver bas niveau pour PIC32 MZ EF, appelable depuis gestion LCD */

#include "system_config.h"
#include "system_definitions.h"
#include <peripheral/i2c/plib_i2c.h>

#define I2C_BUS I2C_ID_1
#define PBCLK_FREQ 100000000UL

void i2c_init(bool fast)
{
    PLIB_I2C_Disable(I2C_BUS);

    PLIB_I2C_HighFrequencyEnable(I2C_BUS);
    PLIB_I2C_BaudRateSet(I2C_BUS, PBCLK_FREQ, fast ? 400000 : 100000);

    PLIB_I2C_SlaveClockStretchingEnable(I2C_BUS);
    PLIB_I2C_Enable(I2C_BUS);
}

void i2c_start(void)
{
    while (!PLIB_I2C_BusIsIdle(I2C_BUS));
    PLIB_I2C_MasterStart(I2C_BUS);
    while (!PLIB_I2C_StartWasDetected(I2C_BUS));
}

void i2c_stop(void)
{
    while (!PLIB_I2C_BusIsIdle(I2C_BUS));
    PLIB_I2C_MasterStop(I2C_BUS);
    while (!PLIB_I2C_StopWasDetected(I2C_BUS));
}

void i2c_restart(void)
{
    PLIB_I2C_MasterStartRepeat(I2C_BUS);
    while (!PLIB_I2C_StartWasDetected(I2C_BUS));
}

bool i2c_write(uint8_t data)
{
    while (!PLIB_I2C_TransmitterIsReady(I2C_BUS));
    PLIB_I2C_TransmitterByteSend(I2C_BUS, data);
    while (PLIB_I2C_TransmitterIsBusy(I2C_BUS));
    return PLIB_I2C_TransmitterByteWasAcknowledged(I2C_BUS);
}

uint8_t i2c_read(bool ack)
{
    uint8_t val;

    PLIB_I2C_MasterReceiverClock1Byte(I2C_BUS);
    while (!PLIB_I2C_ReceivedByteIsAvailable(I2C_BUS));
    val = PLIB_I2C_ReceivedByteGet(I2C_BUS);

    PLIB_I2C_ReceivedByteAcknowledge(I2C_BUS, ack);

    // Attendre que l'envoi de ACK/NACK soit terminé
    while (!PLIB_I2C_AcknowledgeHasCompleted(I2C_BUS));

    return val;
}

