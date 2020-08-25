/*********************************************************************************/
/* Author    : shimo		                                                     */
/* Version   : V01                                                               */
/* Date      : 23 Aug 2020                                                       */
/*********************************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/* Register Definitions */
typedef struct{
	volatile u32 AFIO_EVCR 		; 
	volatile u32 AFIO_MAPR 		; 
	volatile u32 AFIO_EXTICR[4] ; 
	volatile u32 AFIO_MAPR2  	; 
}AFIO_t;

#define AFIO ((AFIO_t *) 0x40010000)

#endif