/* -----------------------------------------------------------------------------
 * LCD.c - Driver for Newhaven NHD-C0220BiZ-FSW-FBW-3V3M
 * Simplified I2C driver using Harmony static functions (DRV_I2C0_*).
 *
 * Sequence and timing now match exactly the ST7036i datasheet example
 * (see "Initialization For ST7036i"), and hexadecimal literals are written
 * without the unsigned suffix.
 * ---------------------------------------------------------------------------*/

#include "lcd.h" // Inclusion du header LCD
#include <xc.h> // Inclusion des definitions du compilateur
#include <stdint.h> // Inclusion des types entiers standard
#include <stdbool.h> // Inclusion du type booleen standard
#include <stdio.h> // Inclusion des fonctions d'entree/sortie standard
#include <stdarg.h> // Inclusion des fonctions pour arguments variables
#include "Mc32Delays.h" // Inclusion des fonctions de delai
#include "system_definitions.h" // Inclusion des definitions systeme

/* -------------------------------------------------------------------------- */
#define LCD_I2C_ADDR_WRITE  0x78   /* 8-bit write address from datasheet */
#define LCD_CMD             0x00   /* control byte: command */
#define LCD_DATA            0x40   /* control byte: data    */

static const uint8_t s_lineAddr[2] = {0x00, 0x40}; // Adresses de debut de ligne

/* -------------------------------------------------------------------------- */
/* Byte-level helper - 30 us gap kept for compatibility                      */
/* -------------------------------------------------------------------------- */
/**
 * @brief Envoie un octet sur le bus I2C vers le LCD.
 *
 * @details
 * Cette fonction ecrit un octet sur le bus I2C et attend la fin de l'ecriture.
 *
 * @param byte Octet a envoyer.
 * @return Aucun retour.
 *
 * @pre Le bus I2C doit etre initialise.
 * @post L'octet est envoye au LCD.
 */
static void _sendByte(uint8_t byte)
{
    DRV_I2C0_ByteWrite(byte); // Ecrit l'octet sur le bus I2C
    while (!DRV_I2C0_WaitForByteWriteToComplete()); // Attend la fin de l'ecriture
    delay_usCt(30); // Delai de 30 us
}

/**
 * @brief Envoie une paire (controle, donnee) brute au LCD.
 *
 * @details
 * Cette fonction envoie un octet de controle puis une donnee brute.
 *
 * @param control Octet de controle (commande ou donnee)
 * @param data Octet de donnee
 * @return Aucun retour.
 *
 * @pre Le bus I2C doit etre initialise.
 * @post La donnee est envoyee au LCD.
 */
static void _sendRaw(uint8_t control, uint8_t data)
{
    DRV_I2C0_MasterStart(); // Start I2C
    delay_usCt(30); // Delai

    _sendByte(LCD_I2C_ADDR_WRITE);  // Adresse esclave
    _sendByte(control);             // 0x00 ou 0x40
    _sendByte(data);                // Donnee

    DRV_I2C0_MasterStop(); // Stop I2C
    delay_usCt(30); // Delai
}

static inline void _cmd(uint8_t c)  { _sendRaw(LCD_CMD , c); } // Envoie une commande
static inline void _data(uint8_t d) { _sendRaw(LCD_DATA, d); } // Envoie une donnee

/* -------------------------------------------------------------------------- */
/* Initialisation sequence strict datasheet                                 */
/* -------------------------------------------------------------------------- */
/**
 * @brief Initialise l'afficheur LCD.
 *
 * @details
 * Sequence d'initialisation conforme a la datasheet ST7036i.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Aucun prerequis specifique.
 * @post L'afficheur LCD est pret a etre utilise.
 */
void lcd_init(void)
{
    /* 40 ms after VDD rises to 2.7 V */
    delay_msCt(50); // Delai d'attente apres alimentation

    //DRV_I2C0_MasterStart(); /* implicite dans _sendRaw mais on garde le timing exact */

    /* Function set (IS=0) */
    _cmd(0x38); // Commande function set
    delay_usCt(30);

    /* Function set (IS=1) */
    _cmd(0x39); // Commande function set avec IS=1
    delay_usCt(30);

    /* Bias/OSC */
    _cmd(0x14); // Reglage bias/oscillateur
    delay_usCt(30);

    /* Contrast low byte */
    _cmd(0x78); // Reglage contraste bas
    delay_usCt(30);

    /* Contrast high + booster */
    _cmd(0x5E); // Reglage contraste haut + booster
    delay_usCt(30);

    /* Follower control */
    _cmd(0x6D); // Reglage follower
    delay_usCt(200);          // Stabilisation booster

    /* Display ON */
    _cmd(0x0C); // Allume l'affichage
    delay_usCt(30);

    /* Clear display */
    _cmd(0x01); // Efface l'affichage
    delay_msCt(2);

    /* Entry mode */
    _cmd(0x06); // Mode entree
    delay_usCt(30);
}

/* -------------------------------------------------------------------------- */
/* High-level API                                                            */
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
        DRV_I2C0_MasterStop();               // libere si besoin
    }

    /* 2. START */
    if (!DRV_I2C0_MasterStart())             // genere START
    {
        return false;
    /* (on ne teste pas WaitForStartComplete, il revient tres vite) */
    }
    
    /* 3. Adresse esclave + W = 0 (0x78) */
    if (!DRV_I2C0_ByteWrite(0x78))
        goto stop;                           // erreur d?ecriture

    /* attendre fin de decaleur */
    if (!DRV_I2C0_WaitForByteWriteToComplete())
        goto stop;

    /* 4. Lire l?ACK/NACK du LCD */
    bool ack = DRV_I2C0_WriteByteAcknowledged();

stop:
    /* 5. STOP, libere le bus */
    DRV_I2C0_MasterStop();
    DRV_I2C0_WaitForStopComplete();

    return ack;      /* true  = LCD present, false = pas d?ACK */
}