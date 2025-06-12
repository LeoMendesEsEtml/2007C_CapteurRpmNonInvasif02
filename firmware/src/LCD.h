/* lcd.h ? NHD-C0220BIZ 2�20 I�C ? Harmony 2.06 */
#ifndef LCD_H
#define LCD_H

#include <stdint.h>
#include "system_definitions.h"   // prototypes DRV_I2C0_*


/* ------------------------------------------------------------------
   Initialise l?afficheur.
------------------------------------------------------------------ */
void lcd_init(void);

/* ------------------------------------------------------------------
   Positionne le curseur : colonne 1-20, ligne 1-2.
------------------------------------------------------------------ */
void lcd_set_cursor(uint8_t col, uint8_t row);

/* ------------------------------------------------------------------
   Affiche un caract�re (g�re '\n' comme saut de ligne).
------------------------------------------------------------------ */
void lcd_putc(uint8_t c);

/* ------------------------------------------------------------------
   Affiche une cha�ne C termin�e par '\0'.
------------------------------------------------------------------ */
void lcd_put_string(const char *str);

/* ------------------------------------------------------------------
   Affiche une cha�ne format�e (max 20 caract�res visibles).
------------------------------------------------------------------ */
void lcd_printf(const char *format, ...);

bool LCD_Ping(void);
#endif /* LCD_H */
