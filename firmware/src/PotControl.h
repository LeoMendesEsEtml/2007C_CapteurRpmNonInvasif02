#ifndef _POTCONTROL_H_
#define _POTCONTROL_H_

#include <stdint.h>
#include <stdbool.h>

// MCP4231 sur CS_POT_1_
#define POT_INDEX_U3_WIPER0   0
#define POT_INDEX_U3_WIPER1   1

// MCP4131 sur CS_POT_2_
#define POT_INDEX_U5_WIPER0   2

#define POT_TOTAL 3

void Pot_Write(uint8_t index, uint8_t value);
bool Pot_Read(uint8_t index, uint8_t* value);
void SPI_ConfigurePot(void);

#endif
