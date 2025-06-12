#include "PotControl.h"
#include "Mc32Spi.h"
#include "system_config.h"
#include "system_definitions.h"
#include <stddef.h>
#include "peripheral/spi/plib_spi.h"
#include "Mc32Delays.h" // pour delay_us

void SPI_ConfigurePot(void)
{
    PLIB_SPI_Disable(SPI_ID_1);

    PLIB_SPI_BufferClear(SPI_ID_1);
    PLIB_SPI_StopInIdleDisable(SPI_ID_1);
    PLIB_SPI_PinEnable(SPI_ID_1, SPI_PIN_DATA_OUT);
    PLIB_SPI_CommunicationWidthSelect(SPI_ID_1, SPI_COMMUNICATION_WIDTH_8BITS);
    PLIB_SPI_BaudRateSet(SPI_ID_1, SYS_CLK_PeripheralFrequencyGet(CLK_BUS_PERIPHERAL_1), 5000000);
    PLIB_SPI_InputSamplePhaseSelect(SPI_ID_1, SPI_INPUT_SAMPLING_PHASE_AT_END);
    PLIB_SPI_ClockPolaritySelect(SPI_ID_1, SPI_CLOCK_POLARITY_IDLE_LOW);
    PLIB_SPI_OutputDataPhaseSelect(SPI_ID_1, SPI_OUTPUT_DATA_PHASE_ON_ACTIVE_TO_IDLE_CLOCK);
    PLIB_SPI_MasterEnable(SPI_ID_1);
    PLIB_SPI_FramedCommunicationDisable(SPI_ID_1);
    PLIB_SPI_FIFOEnable(SPI_ID_1);

    PLIB_SPI_Enable(SPI_ID_1);
}

void Pot_Write(uint8_t index, uint8_t value)
{
    if (index >= POT_TOTAL) {
        return;
    }
    
    if (index == POT_INDEX_U3_WIPER0) {
        CS_POT_1_Off();
        spi_write1(0x00);
        spi_write1(value);
        CS_POT_1_On();;
    }
    else if (index == POT_INDEX_U3_WIPER1) {
        CS_POT_1_Off();
        spi_write1(0x10);
        spi_write1(value);
        CS_POT_1_On();
    }
    else if (index == POT_INDEX_U5_WIPER0) {
        CS_POT_2_Off();
        spi_write1(0x00);
        spi_write1(value);
        CS_POT_2_On();
    }
}

bool Pot_Read(uint8_t index, uint8_t* value)
{
    if (value == NULL) {
        return false;
    }
    if (index > POT_INDEX_U3_WIPER1) {
        // Lecture interdite sur MCP4131
        return false;
    }

    uint8_t cmd = (index == POT_INDEX_U3_WIPER0) ? 0x0D : 0x1D;

//    while (!PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_1)) {
//        (void)PLIB_SPI_BufferRead(SPI_ID_1);
//    }

    CS_POT_1_Off();
    (void)spi_read1(cmd);
    delay_us(5);
    *value = spi_read1(0xFF);
    delay_us(10);
    CS_POT_1_On();

    return true;
}