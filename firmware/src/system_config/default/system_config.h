/*******************************************************************************
  MPLAB Harmony System Configuration Header

  File Name:
    system_config.h

  Summary:
    Build-time configuration header for the system defined by this MPLAB Harmony
    project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options that are not instantiated
    until used by another MPLAB Harmony module or application.

    Created with MPLAB Harmony Version 2.06
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Common System Service Configuration Options
*/
#define SYS_VERSION_STR           "2.06"
#define SYS_VERSION               20600

// *****************************************************************************
/* Clock System Service Configuration Options
*/
#define SYS_CLK_FREQ                        100000000ul
#define SYS_CLK_BUS_PERIPHERAL_1            50000000ul
#define SYS_CLK_BUS_PERIPHERAL_2            25000000ul
#define SYS_CLK_BUS_PERIPHERAL_3            10000000ul
#define SYS_CLK_BUS_PERIPHERAL_4            50000000ul
#define SYS_CLK_BUS_PERIPHERAL_5            50000000ul
#define SYS_CLK_BUS_PERIPHERAL_7            100000000ul
#define SYS_CLK_BUS_PERIPHERAL_8            50000000ul
#define SYS_CLK_CONFIG_PRIMARY_XTAL         8000000ul
#define SYS_CLK_CONFIG_SECONDARY_XTAL       32768ul
   
/*** Ports System Service Configuration ***/
#define SYS_PORT_B_ANSEL        0xFF1F
#define SYS_PORT_B_TRIS         0xFFFF
#define SYS_PORT_B_LAT          0x0000
#define SYS_PORT_B_ODC          0x0000
#define SYS_PORT_B_CNPU         0x0000
#define SYS_PORT_B_CNPD         0x0000
#define SYS_PORT_B_CNEN         0x0000

#define SYS_PORT_C_ANSEL        0xDFFF
#define SYS_PORT_C_TRIS         0xFFFF
#define SYS_PORT_C_LAT          0x0000
#define SYS_PORT_C_ODC          0x0000
#define SYS_PORT_C_CNPU         0x0000
#define SYS_PORT_C_CNPD         0x0000
#define SYS_PORT_C_CNEN         0x0000

#define SYS_PORT_D_ANSEL        0xF1C0
#define SYS_PORT_D_TRIS         0xF7C3
#define SYS_PORT_D_LAT          0x0000
#define SYS_PORT_D_ODC          0x0000
#define SYS_PORT_D_CNPU         0x0000
#define SYS_PORT_D_CNPD         0x0000
#define SYS_PORT_D_CNEN         0x0000

#define SYS_PORT_E_ANSEL        0xFF10
#define SYS_PORT_E_TRIS         0xFF17
#define SYS_PORT_E_LAT          0x0000
#define SYS_PORT_E_ODC          0x0000
#define SYS_PORT_E_CNPU         0x0000
#define SYS_PORT_E_CNPD         0x0000
#define SYS_PORT_E_CNEN         0x0000

#define SYS_PORT_F_ANSEL        0xFFC4
#define SYS_PORT_F_TRIS         0xFFFF
#define SYS_PORT_F_LAT          0x0000
#define SYS_PORT_F_ODC          0x0000
#define SYS_PORT_F_CNPU         0x0000
#define SYS_PORT_F_CNPD         0x0000
#define SYS_PORT_F_CNEN         0x0000

#define SYS_PORT_G_ANSEL        0xFEBF
#define SYS_PORT_G_TRIS         0xFFFF
#define SYS_PORT_G_LAT          0x0000
#define SYS_PORT_G_ODC          0x0000
#define SYS_PORT_G_CNPU         0x0000
#define SYS_PORT_G_CNPD         0x0000
#define SYS_PORT_G_CNEN         0x0000


/*** Interrupt System Service Configuration ***/
#define SYS_INT                     true

// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************
#define DRV_I2C_INTERRUPT_MODE                    		false

#define DRV_IC_DRIVER_MODE_STATIC 

/*** NVM Driver Configuration ***/
#define DRV_NVM_INTERRUPT_MODE          false
#define DRV_NVM_BUFFER_OBJECT_NUMBER    5
#define DRV_NVM_MEDIA_SIZE              16384
#define DRV_NVM_MEDIA_START_ADDRESS     0xBD1FC000
#define DRV_NVM_ERASE_WRITE_ENABLE


/*** Timer Driver Configuration ***/
#define DRV_TMR_INTERRUPT_MODE             true

/*** Timer Driver 0 Configuration ***/
#define DRV_TMR_PERIPHERAL_ID_IDX0          TMR_ID_1
#define DRV_TMR_INTERRUPT_SOURCE_IDX0       INT_SOURCE_TIMER_1
#define DRV_TMR_INTERRUPT_VECTOR_IDX0       INT_VECTOR_T1
#define DRV_TMR_ISR_VECTOR_IDX0             _TIMER_1_VECTOR
#define DRV_TMR_INTERRUPT_PRIORITY_IDX0     INT_PRIORITY_LEVEL1
#define DRV_TMR_INTERRUPT_SUB_PRIORITY_IDX0 INT_SUBPRIORITY_LEVEL0
#define DRV_TMR_CLOCK_SOURCE_IDX0           DRV_TMR_CLKSOURCE_INTERNAL
#define DRV_TMR_PRESCALE_IDX0               TMR_PRESCALE_VALUE_1
#define DRV_TMR_OPERATION_MODE_IDX0         DRV_TMR_OPERATION_MODE_16_BIT
#define DRV_TMR_ASYNC_WRITE_ENABLE_IDX0     false
#define DRV_TMR_POWER_STATE_IDX0            

#define DRV_TMR_PERIPHERAL_ID_IDX1          TMR_ID_2
#define DRV_TMR_INTERRUPT_SOURCE_IDX1       INT_SOURCE_TIMER_3
#define DRV_TMR_INTERRUPT_VECTOR_IDX1       INT_VECTOR_T3
#define DRV_TMR_ISR_VECTOR_IDX1             _TIMER_3_VECTOR
#define DRV_TMR_INTERRUPT_PRIORITY_IDX1     INT_DISABLE_INTERRUPT
#define DRV_TMR_INTERRUPT_SUB_PRIORITY_IDX1 INT_SUBPRIORITY_LEVEL0
#define DRV_TMR_CLOCK_SOURCE_IDX1           DRV_TMR_CLKSOURCE_INTERNAL
#define DRV_TMR_PRESCALE_IDX1               TMR_PRESCALE_VALUE_1
#define DRV_TMR_OPERATION_MODE_IDX1         DRV_TMR_OPERATION_MODE_32_BIT

#define DRV_TMR_ASYNC_WRITE_ENABLE_IDX1     false
#define DRV_TMR_POWER_STATE_IDX1            

 
// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Application Configuration
// *****************************************************************************
// *****************************************************************************
/*** Application Defined Pins ***/

/*** Functions for TX_485_EN pin ***/
#define TX_485_ENToggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_5)
#define TX_485_ENOn() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_5)
#define TX_485_ENOff() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_5)
#define TX_485_ENStateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_5)
#define TX_485_ENStateSet(Value) PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_5, Value)

/*** Functions for EN_LDO_ pin ***/
#define EN_LDO_Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_6)
#define EN_LDO_On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_6)
#define EN_LDO_Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_6)
#define EN_LDO_StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_6)
#define EN_LDO_StateSet(Value) PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_6, Value)

/*** Functions for LIFE_LED_ pin ***/
#define LIFE_LED_Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7)
#define LIFE_LED_On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7)
#define LIFE_LED_Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7)
#define LIFE_LED_StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7)
#define LIFE_LED_StateSet(Value) PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7, Value)

/*** Functions for IR_EN_ pin ***/
#define IR_EN_Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_11)
#define IR_EN_On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_11)
#define IR_EN_Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_11)
#define IR_EN_StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_11)
#define IR_EN_StateSet(Value) PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_11, Value)

/*** Functions for CS_ACC_ pin ***/
#define CS_ACC_Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2)
#define CS_ACC_On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2)
#define CS_ACC_Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2)
#define CS_ACC_StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2)
#define CS_ACC_StateSet(Value) PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_2, Value)

/*** Functions for USB_EN_ pin ***/
#define USB_EN_Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_3)
#define USB_EN_On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_3)
#define USB_EN_Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_3)
#define USB_EN_StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_3)
#define USB_EN_StateSet(Value) PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_3, Value)

/*** Functions for CS_POT_1_ pin ***/
#define CS_POT_1_Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_4)
#define CS_POT_1_On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_4)
#define CS_POT_1_Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_4)
#define CS_POT_1_StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_4)
#define CS_POT_1_StateSet(Value) PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_4, Value)

/*** Functions for CS_POT_2_ pin ***/
#define CS_POT_2_Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_5)
#define CS_POT_2_On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_5)
#define CS_POT_2_Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_5)
#define CS_POT_2_StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_5)
#define CS_POT_2_StateSet(Value) PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_5, Value)

/*** Functions for BL_CONTROL_ pin ***/
#define BL_CONTROL_Toggle() PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_3)
#define BL_CONTROL_On() PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_3)
#define BL_CONTROL_Off() PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_3)
#define BL_CONTROL_StateGet() PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_3)
#define BL_CONTROL_StateSet(Value) PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_3, Value)

/*** Functions for SCK_FOR_DEBUG_ pin ***/
#define SCK_FOR_DEBUG_StateGet() PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_13)

/*** Functions for PB_OK_ pin ***/
#define PB_OK_StateGet() PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_0)

/*** Functions for PB_SELECT_ pin ***/
#define PB_SELECT_StateGet() PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_1)


/*** Application Instance 0 Configuration ***/

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _SYSTEM_CONFIG_H
/*******************************************************************************
 End of File
*/
