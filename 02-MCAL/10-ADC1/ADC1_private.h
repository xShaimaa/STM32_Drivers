/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 				                                                     */
/*********************************************************************************/

#ifndef _ADC1_PRIVATE_H_
#define _ADC1_PRIVATE_H_

/* Register Definitions */
typedef struct{
	volatile u32 SR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMPR[2];
	volatile u32 JOFR[4];
	volatile u32 HTR;
	volatile u32 LTR;
	volatile u32 SQR[3];
	volatile u32 JDR[4];
	volatile u32 JSQR;
	volatile u32 DR;
}ADC_t;


#define ADC1 ((ADC_t *) 0x40012400)


/* bits difinitions */
/* SR */
#define AWD		0		
#define EOC		1
#define JEOC	2			
#define JSTR	3		
#define STRT	4		

/* CR1 */
#define AWDCH		0		
#define EOCIE		5		
#define AWDIE		6		
#define JEOCIE		7		
#define SCAN		8
#define AWDSGL		9		
#define JAUTO		10		
#define DISCEN		11		
#define JDISCEN		12		
#define DISCNUM		13		
#define DUALMOD		16		
#define JAWDEN		22		
#define AWDEN		23		

/* CR2 */
#define ADON		0		
#define CONT		1		 
#define CAL			2	
#define RSTCAL		3		
#define DMA			8		
#define ALIGN		11
#define JEXTSEL		12		
#define JEXTTRIG	15		
#define EXTSEL		17	
#define EXTTRIG		20
#define JSWSTART	21	
#define SWSTART		22		
#define TSVREFE		23

/* SMPR1 */
#define SMP10		0		
#define SMP11		3		
#define SMP12		6		
#define SMP13		9		
#define SMP14		12		
#define SMP15		15		
#define SMP16		18		
#define SMP17		21		

/* SMPR2 */
#define SMP0		0		
#define SMP1		3		
#define SMP2		6		
#define SMP3		9		
#define SMP4		12		
#define SMP5		15		
#define SMP6		18		
#define SMP7		21		
#define SMP8		24		
#define SMP9		27		

/* SQR1 */
#define SQ13		0		
#define SQ14		5		
#define SQ15		10		
#define SQ16		15		
#define L			20

/* SQR2 */
#define SQ7			0		
#define SQ8			5		
#define SQ9			10		
#define SQ10		15		
#define SQ11		20		
#define SQ12		25		

/* SQR3 */
#define SQ1			0		
#define SQ2			5		
#define SQ3			10		
#define SQ4			15		
#define SQ5			20		
#define SQ6			25		

/* JSQR */
#define JSQ1		0		
#define JSQ2		5
#define JSQ3		10		
#define JSQ4		15		
#define JL			20

/* Private functions prototypes */





#endif 
