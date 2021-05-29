/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V02                                                               */
/* Date      : 11 Nov 2020                                                       */
/*********************************************************************************/
#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H

/* Registers Definitions */

typedef struct 
{
	volatile u32 ACR		;
	volatile u32 KEYR		;
	volatile u32 OPTKEYR	;
	volatile u32 SR			;
	volatile u32 CR			;
	volatile u32 AR			;
	volatile u32 RESERVED	;
	volatile u32 OBR		;
	volatile u32 WRPR		;	
}FPEC_Register;

#define FPEC 	(FPEC_Register* (0x40022000))	

/* flash unlock keys */
#define KEY1  	0x45670123
#define KEY2  	0xCDEF89AB

/* Bits definitions */

/* CR */
#define PG		0
#define PER		1
#define STRT	6
#define LOCK	7
#define OPTWRE	9

/* SR */
#define  BSY	0

#define START_ADDRESS 	0x08000000
#define PAGE_SIZE		1024


#endif 