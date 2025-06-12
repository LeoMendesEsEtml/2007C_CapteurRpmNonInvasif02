/* -----------------------------------------------------------------------------
 * LCD.c ? Driver for Newhaven NHD-C0220BiZ-FSW-FBW-3V3M
 * Simplified I²C driver using Harmony static functions (DRV_I2C0_*).
 *
 * Sequence and timing now match exactly the ST7036i datasheet example
 * (see "Initialization For ST7036i"), and hexadecimal literals are written
 * without the unsigned suffix.
 * ---------------------------------------------------------------------------*/

#include "lcd.h"
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include "Mc32Delays.h"
#include "system_definitions.h"

/* -------------------------------------------------------------------------- */
#define LCD_I2C_ADDR_WRITE  0x78   /* 8-bit write address from datasheet */
#define LCD_CMD             0x00   /* control byte: command */
#define LCD_DATA            0x40   /* control byte: data    */

static const uint8_t s_lineAddr[2] = {0x00, 0x40};

/* -------------------------------------------------------------------------- */
/* Byte-level helper ? 30 µs gap kept for compatibility                      */
/* -------------------------------------------------------------------------- */
static void _sendByte(uint8_t byte)
{
    DRV_I2C0_ByteWrite(byte);
    while (!DRV_I2C0_WaitForByteWriteToComplete());
    delay_usCt(30);
}

static void _sendRaw(uint8_t control, uint8_t data)
{
    DRV_I2C0_MasterStart();
    delay_usCt(30);

    _sendByte(LCD_I2C_ADDR_WRITE);  /* slave address */
    _sendByte(control);             /* 0x00 or 0x40 */
    _sendByte(data);

    DRV_I2C0_MasterStop();
    delay_usCt(30);
}

static inline void _cmd(uint8_t c)  { _sendRaw(LCD_CMD , c); }
static inline void _data(uint8_t d) { _sendRaw(LCD_DATA, d); }

/* -------------------------------------------------------------------------- */
/* Initialization strict datasheet sequence                                */
/* -------------------------------------------------------------------------- */
void lcd_init(void)
{
    /* ?40 ms after VDD rises to 2.7 V */
    delay_msCt(50);

    //DRV_I2C0_MasterStart(); /* implicit in _sendRaw but we keep exact timing */

    /* Function set (IS=0) */
    _cmd(0x38);
    delay_usCt(30);

    /* Function set (IS=1) */
    _cmd(0x39);
    delay_usCt(30);

    /* Bias/OSC */
    _cmd(0x14);
    delay_usCt(30);

    /* Contrast low byte */
    _cmd(0x78);
    delay_usCt(30);

    /* Contrast high + booster */
    _cmd(0x5E);
    delay_usCt(30);

    /* Follower control */
    _cmd(0x6D);
    delay_usCt(200);          /* booster stabilization */

    /* Display ON */
    _cmd(0x0C);
    delay_usCt(30);

    /* Clear display */
    _cmd(0x01);
    delay_msCt(2);

    /* Entry mode */
    _cmd(0x06);
    delay_usCt(30);
}

/* -------------------------------------------------------------------------- */
/* High-level API                                                             */
/* -------------------------------------------------------------------------- */
void lcd_set_cursor(uint8_t col, uint8_t row)
{
    if (col == 0 || col > 20 || row < 1 || row > 2) 
    {
        return;
    }
    _cmd(0x80 | (s_lineAddr[row - 1] + col - 1));
}

void lcd_putc(uint8_t c)
{
    if (c == '\n') 
    {
        lcd_set_cursor(1, 2);
    }
    else 
    {
        _data(c);
    }
}

void lcd_put_string(const char *s)
{
    while (*s)
    { 
        lcd_putc((uint8_t)*s++);
    }
}

void lcd_printf(const char *fmt, ...)
{
    char buf[21];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    lcd_put_string(buf);
}
bool LCD_Ping(void)
{
    /* 1. S?assurer que le bus est libre */
    if (!DRV_I2C0_MasterBusIdle())
    {
        DRV_I2C0_MasterStop();               // libère si besoin
    }

    /* 2. START */
    if (!DRV_I2C0_MasterStart())             // génère START
    {
        return false;
    /* (on ne teste pas WaitForStartComplete, il revient très vite) */
    }
    
    /* 3. Adresse esclave + W = 0 (0x78) */
    if (!DRV_I2C0_ByteWrite(0x78))
        goto stop;                           // erreur d?écriture

    /* attendre fin de décaleur */
    if (!DRV_I2C0_WaitForByteWriteToComplete())
        goto stop;

    /* 4. Lire l?ACK/NACK du LCD */
    bool ack = DRV_I2C0_WriteByteAcknowledged();

stop:
    /* 5. STOP, libère le bus */
    DRV_I2C0_MasterStop();
    DRV_I2C0_WaitForStopComplete();

    return ack;      /* true  = LCD présent, false = pas d?ACK */
}