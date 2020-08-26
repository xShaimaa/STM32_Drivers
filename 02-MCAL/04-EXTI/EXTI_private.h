/*********************************************************************************/
/* Author    : shimo		                                                     */
/* Version   : V01                                                               */
/* Date      : 23 Aug 2020                                                       */
/*********************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Register Definitions */
typedef struct{
	volatile u32 EXTI_IMR 	;		/* masks or unmasks the IRQ */ 
	volatile u32 EXTI_EMR 	; 		/* masks or unmasks the IRQ event*/
	volatile u32 EXTI_RTSR  ;		/* rising  trigger selection */ 
	volatile u32 EXTI_FTSR  ;		/* falling trigger selection */ 
	volatile u32 EXTI_SWIER ;		/* controls the software interrupt event*/ 
	volatile u32 EXTI_PR 	; 		/* pending register */

}EXTI_t;

#define EXTI ((EXTI_t *) 0x40010400)

#endif