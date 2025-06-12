#include "LIS2HH12.h"
#include "system_config.h"
#include "system_definitions.h"
#include "Mc32Spi.h"
#include "Mc32Delays.h"
#include "peripheral/spi/plib_spi.h"

void SPI_ConfigureAcc(void)
{
    PLIB_SPI_Disable(SPI_ID_1);

    PLIB_SPI_BufferClear(SPI_ID_1);
    PLIB_SPI_StopInIdleDisable(SPI_ID_1);
    PLIB_SPI_PinEnable(SPI_ID_1, SPI_PIN_DATA_OUT);
    PLIB_SPI_CommunicationWidthSelect(SPI_ID_1, SPI_COMMUNICATION_WIDTH_8BITS);
    PLIB_SPI_BaudRateSet(SPI_ID_1, SYS_CLK_PeripheralFrequencyGet(CLK_BUS_PERIPHERAL_1), 2000000); // 2 MHz max
    PLIB_SPI_InputSamplePhaseSelect(SPI_ID_1, SPI_INPUT_SAMPLING_PHASE_AT_END);
    PLIB_SPI_ClockPolaritySelect(SPI_ID_1, SPI_CLOCK_POLARITY_IDLE_LOW);
    PLIB_SPI_OutputDataPhaseSelect(SPI_ID_1, SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK);
    PLIB_SPI_MasterEnable(SPI_ID_1);
    PLIB_SPI_FramedCommunicationDisable(SPI_ID_1);
    PLIB_SPI_FIFOEnable(SPI_ID_1);

    PLIB_SPI_Enable(SPI_ID_1);
}
void LIS2HH12_Init(void)
{
    // CTRL1 : ODR = 100 Hz, mode normal, tous les axes activés
    // 0x57 = 0101 0111 => ODR = 100Hz, X/Y/Z activés
    LIS2HH12_WriteReg(0x20, 0x57);

    // CTRL2 : filtre haute fréquence désactivé (par défaut), on ne change rien ici

    // CTRL3 : toutes les interruptions désactivées, DRDY désactivé
    LIS2HH12_WriteReg(0x22, 0x00);

    // CTRL4 : échelle ±2g, high resolution désactivé (par défaut)
    LIS2HH12_WriteReg(0x23, 0x00);

    // CTRL5 : filtre FIFO, pas nécessaire pour lecture simple
    LIS2HH12_WriteReg(0x24, 0x00);
}
uint8_t LIS2HH12_ReadReg(uint8_t reg)
{
    uint8_t value;

    CS_ACC_Off();
    spi_write1(0x80 | reg); // 0x80 = bit read
    value = spi_read1(0xFF);
    CS_ACC_On();

    return value;
}

void LIS2HH12_WriteReg(uint8_t reg, uint8_t value)
{
    CS_ACC_Off();
    spi_write1(reg & 0x7F); // Write, bit 7=0
    spi_write1(value);
    CS_ACC_On();
}

uint8_t LIS2HH12_ReadID(void)
{
    return LIS2HH12_ReadReg(LIS2HH12_WHO_AM_I_REG);
}

void LIS2HH12_ReadXYZ(int16_t *x, int16_t *y, int16_t *z)
{
    uint8_t buf[6];
    uint8_t i;

    CS_ACC_Off();
    spi_write1(0xC0 | LIS2HH12_OUT_X_L); // 0xC0 = read + auto-increment
    for (i = 0; i < 6; i = i + 1) {
        buf[i] = spi_read1(0xFF);
    }
    CS_ACC_On();

    *x = (int16_t)((buf[1] << 8) | buf[0]);
    *y = (int16_t)((buf[3] << 8) | buf[2]);
    *z = (int16_t)((buf[5] << 8) | buf[4]);
}
