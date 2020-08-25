/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 12 Aug 2020                                                       */
/*********************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* Pin values */
#define GPIO_HIGH 1
#define GPIO_LOW  0

/* GPIO PORTs */
#define	GPIOA  2
#define	GPIOB  3
#define	GPIOC  4

/* GPIO PINs  */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
#define PIN8   8
#define PIN9   9
#define PIN10  10
#define PIN11  11
#define PIN12  12
#define PIN13  13
#define PIN14  14
#define PIN15  15

/* GPIO INPUT Modes */
#define INPUT_ANALOG				0b0000
#define INPUT_FLOATING				0b0100
#define INPUT_PULL_UP_DOWN			0b1000

/* GPIO OUTPUT Modes */
#define OUTPUT_SPEED_10MHZ_PP		0b0001
#define OUTPUT_SPEED_10MHZ_OD		0b0101
#define OUTPUT_SPEED_10MHZ_AFPP		0b1001
#define OUTPUT_SPEED_10MHZ_AFOD		0b1101

#define OUTPUT_SPEED_2MHZ_PP		0b0010
#define OUTPUT_SPEED_2MHZ_OD		0b0110
#define OUTPUT_SPEED_2MHZ_AFPP		0b1010
#define OUTPUT_SPEED_2MHZ_AFOD		0b1110

#define OUTPUT_SPEED_50MHZ_PP		0b0011
#define OUTPUT_SPEED_50MHZ_OD		0b0111
#define OUTPUT_SPEED_50MHZ_AFPP		0b1011
#define OUTPUT_SPEED_50MHZ_AFOD		0b1111

/* GPIO PULL Modes */
#define PULL_UP		0
#define PULL_DOWN	1

/* public functions prototypes */

/******************************************************************************
* Description : setting the PIN mode
* Parameters  : PORT (GPIOA -> C) - PIN (PIN0 -> 15) - PIN Mode
* Return type : void
******************************************************************************/
void MGPIO_VoidSetPinDir(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode);

/******************************************************************************
* Description : setting the PIN value
* Parameters  : PORT (GPIOA -> C) - PIN (PIN0 -> 15) - Val (GPIO_HIGH - GPIO_LOW)
* Return type : void
******************************************************************************/
void MGPIO_VoidSetPinVal(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Val);

/******************************************************************************
* Description : setting the PIN PULL Mode
* Parameters  : PORT (GPIOA -> C) - PIN (PIN0 -> 15) - PULL Mode(PULL_UP, PULL_DOWN) 
* Return type : void
******************************************************************************/
void GPIO_voidSetPullMode (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8PullMode);

/******************************************************************************
* Description : setting multiple Pins' value
* Parameters  : PORT (GPIOA -> C) - PIN (PIN0 -> 15) - val (the required value)
* Return type : void
******************************************************************************/
void MGPIO_voidSetPinsFrom(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Val);

/******************************************************************************
* Description : toggling a pin
* Parameters  : PORT (GPIOA -> C) - PIN (PIN0 -> 15)
* Return type : void
******************************************************************************/
void MGPIO_VoidTogPin(u8 Copy_u8PORT, u8 Copy_u8PIN);

/******************************************************************************
* Description : reading a pin's value
* Parameters  : PORT (GPIOA -> C) - PIN (PIN0 -> 15)
* Return type : u8 (0 - 1)
******************************************************************************/
u8 MGPIO_u8GetPinVal(u8 Copy_u8PORT, u8 Copy_u8PIN);

/******************************************************************************
* Description : locking a pin's configuration
* Parameters  : PORT (GPIOA -> C) - PIN (PIN0 -> 15)
* Return type : void
******************************************************************************/
void MGPIO_VoidLockPin(u8 Copy_u8PORT, u8 Copy_u8PIN);


#endif
