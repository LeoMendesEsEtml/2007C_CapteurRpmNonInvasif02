#ifndef __MC32DELAYS_H
#define __MC32DELAYS_H
/*--------------------------------------------------------*/
//      Mc32Delays.h
/*--------------------------------------------------------*/
//	Description :	Adaptation des fonctions de delay afin
//					de pouvoir utiliser la meme syntaxe
//					que sous CCS.
//
//	Auteur 		: 	F. Domine
//
//	Version		:	V1.0
//	Compilateur	:	C32 V2.01
//
/*--------------------------------------------------------*/


/*--------------------------------------------------------*/
// Definition des fonctions prototypes
/*--------------------------------------------------------*/
// Quelques commentaires:
// Avec notre configuration, le temps necessire pour passer
// une sortie a 0 puis a 1 est denviron 65ns
// En ajoutant un nop, on obtient environ 100ns
// On peut en conclure que le temps de cycle est de 33ns
#define delay_cycle() __asm__( "nop" )
void delay500ns(); // necessaire pour lcd
void delay_us(unsigned int); // 32 bits
void delay_ms(unsigned int); // 32 bits

//Fonctions basees sur Core Timer
void delay_msCt(unsigned int NbMs);
void delay_usCt(unsigned int NbUs);
void delay500nsCt(void);


#endif
