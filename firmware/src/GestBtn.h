// GestBtn.h
#ifndef GESTBTN_H
#define GESTBTN_H

#include <stdint.h>
#include <stdbool.h>

/** Masques de retour de GestBtn_Scan() **/
#define GESTBTN_NONE    0x00u
#define GESTBTN_OK      0x01u    // bit 0
#define GESTBTN_SELECT  0x02u    // bit 1

/**
 * @brief  Initialise l?�tat interne du d�bounce.  
 *         *Ne touche pas � la config des broches !*
 */
void GestBtn_Init(void);

/**
 * @brief  Doit �tre appel� toutes les ~1 ms pour actualiser le d�bounce.
 */
void GestBtn_Update(void);

/**
 * @brief  Renvoie le masque des boutons press�s depuis le dernier appel,
 *         et r�initialise leur flag � pressed �.
 * @retval combinaison de GESTBTN_OK | GESTBTN_SELECT
 */
uint8_t GestBtn_Scan(void);

#endif // GESTBTN_H
