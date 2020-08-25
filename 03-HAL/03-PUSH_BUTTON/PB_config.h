/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 17 Aug 2020                                                       */
/*********************************************************************************/
#ifndef PB_CONFIG_H
#define PB_CONFIG_H


/* 	PB INPUT Modes 				 		   */
/* 	Options : 			INTERNAL_PULL_UP
			 			EXTERNAL_PULL_UP
			 			INTERNAL_PULL_DOWN
			 			EXTERNAL_PULL_DOWN */
#define PB_INPUT_MODE	INTERNAL_PULL_UP

/* Push Button  PORT	*/
/* Options :	GPIOA
 	 	 	 	GPIOB
 	 	 	 	GPIOC   */
#define PB_PORT PORTB

/* Push Button  PIN			  */
/* Options :	PIN0 -> PIN15 */
#define PB_PIN  PIN0

#define PB_PRESS_VOLT	1
#define PB_RELEASE_VOLT	0



/* couter to check the button state */
#define PB_COUNT_CHECK 10















#endif