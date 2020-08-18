/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 13 Aug 2020                                                       */
/*********************************************************************************/
#ifndef SSD_CONFIG_H
#define SSD_CONFIG_H

/* the SSD Common type   */
/* Options : COM_ANOD
  			 COM_CATHOD  */
#define SSD_COM  COM_CATHOD

/* SSD OUTPUT Modes 				 */
/* Options : OUTPUT_SPEED_10MHZ_PP
			 OUTPUT_SPEED_10MHZ_OD
			 OUTPUT_SPEED_10MHZ_AFPP
			 OUTPUT_SPEED_10MHZ_AFOD */
#define SSD_OUTPUT_MODE		OUTPUT_SPEED_10MHZ_PP


/* SSD PORT			*/
/* Options : GPIOA
 	 	 	 GPIOB
 	 	 	 GPIOC  */
#define SSD_PORT GPIOA

/* SSD PINs					 */
/* Options : from PIN0 -> 15 */
#define SSD_A	 PIN0
#define SSD_B 	 PIN1
#define SSD_C 	 PIN2
#define SSD_D 	 PIN3
#define SSD_E 	 PIN4
#define SSD_F 	 PIN5
#define SSD_G 	 PIN6

#endif
