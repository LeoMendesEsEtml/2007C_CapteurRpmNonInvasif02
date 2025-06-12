/* lcd.h - NHD-C0220BIZ 2x20 I2C - Harmony 2.06 */
#ifndef LCD_H
#define LCD_H

#include <stdint.h> // Inclusion des types entiers standard
#include "system_definitions.h"   // Prototypes DRV_I2C0_*


/* ------------------------------------------------------------------
   Initialise l'afficheur.
------------------------------------------------------------------ */
/**
 * @brief Initialise l'afficheur LCD.
 *
 * @details
 * Cette fonction initialise le module LCD via le bus I2C.
 *
 * @param Aucun parametre.
 * @return Aucun retour.
 *
 * @pre Aucun prerequis specifique.
 * @post L'afficheur LCD est pret a etre utilise.
 */
void lcd_init(void);

/* ------------------------------------------------------------------
   Positionne le curseur : colonne 1-20, ligne 1-2.
------------------------------------------------------------------ */
/**
 * @brief Positionne le curseur sur l'ecran LCD.
 *
 * @details
 * Cette fonction place le curseur a la colonne et ligne indiquees.
 *
 * @param col Colonne (1-20)
 * @param row Ligne (1-2)
 * @return Aucun retour.
 *
 * @pre L'afficheur doit etre initialise.
 * @post Le curseur est positionne.
 */
void lcd_set_cursor(uint8_t col, uint8_t row);

/* ------------------------------------------------------------------
   Affiche un caractere (gere '\n' comme saut de ligne).
------------------------------------------------------------------ */
/**
 * @brief Affiche un caractere sur l'ecran LCD.
 *
 * @details
 * Gere le caractere '\n' comme saut de ligne.
 *
 * @param c Caractere a afficher.
 * @return Aucun retour.
 *
 * @pre L'afficheur doit etre initialise.
 * @post Le caractere est affiche.
 */
void lcd_putc(uint8_t c);

/* ------------------------------------------------------------------
   Affiche une chaine C terminee par '\0'.
------------------------------------------------------------------ */
/**
 * @brief Affiche une chaine de caracteres sur l'ecran LCD.
 *
 * @details
 * Affiche la chaine terminee par '\0'.
 *
 * @param str Pointeur sur la chaine a afficher.
 * @return Aucun retour.
 *
 * @pre L'afficheur doit etre initialise.
 * @post La chaine est affichee.
 */
void lcd_put_string(const char *str);

/* ------------------------------------------------------------------
   Affiche une chaine formatee (max 20 caracteres visibles).
------------------------------------------------------------------ */
/**
 * @brief Affiche une chaine formatee sur l'ecran LCD.
 *
 * @details
 * Affiche une chaine formatee, limitee a 20 caracteres visibles.
 *
 * @param format Format de la chaine.
 * @param ... Arguments variables.
 * @return Aucun retour.
 *
 * @pre L'afficheur doit etre initialise.
 * @post La chaine formatee est affichee.
 */
void lcd_printf(const char *format, ...);

/**
 * @brief Teste la presence de l'afficheur LCD sur le bus I2C.
 *
 * @details
 * Cette fonction verifie si l'afficheur repond sur le bus I2C.
 *
 * @param Aucun parametre.
 * @return true si l'afficheur repond, false sinon.
 *
 * @pre Aucun prerequis specifique.
 * @post Aucun effet de bord.
 */
bool LCD_Ping(void);
#endif /* LCD_H */
