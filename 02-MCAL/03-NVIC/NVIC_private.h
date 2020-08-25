/*********************************************************************************/
/* Author    : shimo		                                                     */
/* Version   : V01                                                               */
/* Date      : 22 Aug 2020                                                       */
/*********************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* Register Definitions */

#define NVIC_ISER0       *((u32*)0xE000E100)  			/* Enables  external IRQ from  0 to 31 */			 
#define NVIC_ISER1       *((u32*)0xE000E104) 			/* Enables  external IRQ from 32 to 63 */	

#define NVIC_ICER0       *((u32*)0xE000E180)			/* disables external IRQ from  0 to 31 */
#define NVIC_ICER1       *((u32*)0xE000E184)			/* disables external IRQ from 32 to 63 */

#define NVIC_ISPR0       *((u32*)0xE000E200)			/* sets   external IRQ pending flag from  0 to 31 */
#define NVIC_ISPR1       *((u32*)0xE000E204)			/* sets   external IRQ pending flag from 32 to 63 */

#define NVIC_ICPR0       *((u32*)0xE000E280)			/* clears external IRQ pending flag from  0 to 31 */
#define NVIC_ICPR1       *((u32*)0xE000E284)			/* clears external IRQ pending flag from 32 to 63 */

#define NVIC_IABR0       *((volatile u32*)0xE000E300)	/* holds external IRQ  active  flag from  0 to 31 */
#define NVIC_IABR1       *((volatile u32*)0xE000E304)	/* holds external IRQ  active  flag from 32 to 63 */

#define NVIC_IPR		 ((u8* )(0xE000E400)			/* sets the IRQ priority */

#define SCB_AIRCR		 ((u32*)(0xE000ED0C)			/* controls the group and sub priorities */

/* Group and sub priorities distribution, (the value | VECTKEY) */
#define MNVIC_GROUP_4_SUB_0      0x05FA0300
#define MNVIC_GROUP_3_SUB_1      0x05FA0400
#define MNVIC_GROUP_2_SUB_2      0x05FA0500
#define MNVIC_GROUP_1_SUB_3      0x05FA0600
#define MNVIC_GROUP_0_SUB_4      0x05FA0700


#endif
