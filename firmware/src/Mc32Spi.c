/*
--------------------------------------------------------
 Fichier : Mc32Spi.c
 Auteur  : leo mendes
 Date    : 2024
 Role    : Fonctions utilitaires SPI pour la communication
--------------------------------------------------------
*/
// Inclusion du header application
#include "app.h" // Fonctions et definitions de l'application principale
// Inclusion du header SPI
#include "Mc32Spi.h" // Prototypes des fonctions SPI utilitaires
// Inclusion de la librairie SPI
#include "peripheral/SPI/plib_spi.h" // Fonctions de la librairie SPI Harmony

/**
 * @brief Ecrit une donnee sur le bus SPI1 et vide le buffer de reception.
 *
 * @details
 * Cette fonction ecrit un octet sur le bus SPI1, attend la fin de la transmission,
 * puis vide le buffer de reception pour eviter tout residu.
 *
 * @param val Valeur a ecrire sur le bus SPI1.
 * @return Aucun retour.
 */
void spi_write1(uint8_t val)
{
    PLIB_SPI_BufferWrite(SPI_ID_1, val); // Ecrit la donnee sur SPI1
    while (PLIB_SPI_IsBusy(SPI_ID_1)); // Attend la fin de la transmission
    while (PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_1)); // Attend la reception
    (void)PLIB_SPI_BufferRead(SPI_ID_1); // Vide le buffer de reception
}

/**
 * @brief Ecrit une donnee sur le bus SPI2.
 *
 * @details
 * Cette fonction ecrit un octet sur le bus SPI2 et attend la fin de la transmission.
 *
 * @param Val Valeur a ecrire sur le bus SPI2.
 * @return Aucun retour.
 */
void spi_write2(uint8_t Val){
   int SpiBusy; // Variable pour surveiller l'etat du SPI
   PLIB_SPI_BufferWrite(SPI_ID_2, Val); // Ecrit la donnee sur SPI2
   do {
     SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_2) ; // Attend la fin de la transmission
   } while (SpiBusy == 1);
}

/**
 * @brief Ecrit une donnee sur SPI1 puis lit la reponse recue.
 *
 * @details
 * Cette fonction ecrit un octet sur le bus SPI1, attend la fin de la transmission,
 * puis lit la valeur recue sur le bus SPI1.
 *
 * @param Val Valeur a envoyer sur le bus SPI1.
 * @return Valeur recue sur le bus SPI1.
 */
uint8_t spi_read1(uint8_t Val){
   int SpiBusy; // Variable pour surveiller l'etat du SPI
   uint32_t lu; // Variable pour stocker la valeur lue
   PLIB_SPI_BufferWrite(SPI_ID_1, Val); // Ecrit la donnee sur SPI1
   do {
        SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_1) ; // Attend la fin de la transmission
   } while (SpiBusy == 1);
   while (PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_1)); // Attend la reception
   lu = PLIB_SPI_BufferRead(SPI_ID_1); // Lit la valeur recue
   return lu; // Retourne la valeur recue
}

/**
 * @brief Ecrit une donnee sur SPI2 puis lit la reponse recue.
 *
 * @details
 * Cette fonction ecrit un octet sur le bus SPI2, attend la fin de la transmission,
 * puis lit la valeur recue sur le bus SPI2.
 *
 * @param Val Valeur a envoyer sur le bus SPI2.
 * @return Valeur recue sur le bus SPI2.
 */
uint8_t spi_read2(uint8_t Val){
   int SpiBusy; // Variable pour surveiller l'etat du SPI
   uint8_t lu; // Variable pour stocker la valeur lue
   PLIB_SPI_BufferWrite(SPI_ID_2, Val); // Ecrit la donnee sur SPI2
   do {
      SpiBusy =  PLIB_SPI_IsBusy(SPI_ID_2) ; // Attend la fin de la transmission
   } while (SpiBusy == 1);
   while (PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_2)); // Attend la reception
   lu = PLIB_SPI_BufferRead(SPI_ID_2); // Lit la valeur recue
   return lu; // Retourne la valeur recue
}



