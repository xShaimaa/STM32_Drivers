/*********************************************************************************/
/* Author    : shimo		                                                     */
/* Version   : V01                                                               */
/* Date      : 23 Aug 2020                                                       */
/*********************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Register Definitions */
typedef struct{
	volatile u32 EXTI_IMR 	; 
	volatile u32 EXTI_EMR 	; 
	volatile u32 EXTI_RTSR  ; 
	volatile u32 EXTI_FTSR  ; 
	volatile u32 EXTI_SWIER ; 
	volatile u32 EXTI_PR 	; 

}EXTI_t;

#define EXTI ((EXTI_t *) 0x40010400)

#endif