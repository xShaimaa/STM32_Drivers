/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 31 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

#include "LEDMRX_private.h"
#include "LEDMRX_config.h"
#include "LEDMRX_interface.h"

/* Global variables */

/* arrays to hold the PORT and PIN of the rows */
u8 LEDMRX_ROWS_PORT[16] = {LEDMRX_ROW0_PORT, LEDMRX_ROW1_PORT, LEDMRX_ROW2_PORT, LEDMRX_ROW3_PORT, LEDMRX_ROW4_PORT, LEDMRX_ROW5_PORT, LEDMRX_ROW6_PORT, LEDMRX_ROW7_PORT};
u8 LEDMRX_ROWS_PINS[16] = {LEDMRX_ROW0_PIN, LEDMRX_ROW1_PIN, LEDMRX_ROW2_PIN, LEDMRX_ROW3_PIN, LEDMRX_ROW4_PIN, LEDMRX_ROW5_PIN, LEDMRX_ROW6_PIN, LEDMRX_ROW7_PIN};

/* arrays to hold the PORT and PIN of the columns */
u8 LEDMRX_COLS_PORT[16] = {LEDMRX_COL0_PORT, LEDMRX_COL1_PORT, LEDMRX_COL2_PORT, LEDMRX_COL3_PORT, LEDMRX_COL4_PORT, LEDMRX_COL5_PORT, LEDMRX_COL6_PORT, LEDMRX_COL7_PORT};
u8 LEDMRX_COLS_PINS[16] = {LEDMRX_COL0_PIN, LEDMRX_COL1_PIN, LEDMRX_COL2_PIN, LEDMRX_COL3_PIN, LEDMRX_COL4_PIN, LEDMRX_COL5_PIN, LEDMRX_COL6_PIN, LEDMRX_COL7_PIN};

/* initializing the LED Matrix pins as output */
void HLEDMRX_voidInit(void)
{
	for(u8 i = 0; i<8; i++)
	{
		MGPIO_VoidSetPinDir(LEDMRX_ROWS_PORT[i], LEDMRX_ROWS_PINS[i], OUTPUT_SPEED_2MHZ_PP);
		MGPIO_VoidSetPinDir(LEDMRX_COLS_PORT[i], LEDMRX_COLS_PINS[i], OUTPUT_SPEED_2MHZ_PP);
	}
}

/* sending data to be displayed */
void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
		for(u8 i = 0; i<8; i++)
		{
			/* for column i */
			/* disable all columns, set to high */
			DisableAllCols();
			/* writting to one row at a time */
			SetRowVal(Copy_u8Data[i]);
			/* enable one column at a time, setting it to low */
			MGPIO_VoidSetPinVal(LEDMRX_COLS_PORT[i], LEDMRX_COLS_PINS[i], GPIO_LOW);
			/* setting a 2 ms delay */
			MSTK_voidSetBusyWait(2);
		}
}

static void DisableAllCols(void)
{
	/* disable all columns, set to high */
	for(u8 i = 0; i<8; i++)
	{
		MGPIO_VoidSetPinVal(LEDMRX_COLS_PORT[i], LEDMRX_COLS_PINS[i], GPIO_HIGH);
	}
}

static void SetRowVal(u8 Copy_u8Val)
{
	u8 Loc_u8BIT;
	/* setting the rows value one row at a time */
	for(u8 i =0; i<8; i++)
	{
		Loc_u8BIT = GET_BIT(Copy_u8Val, i);
		MGPIO_VoidSetPinVal(LEDMRX_ROWS_PORT[i], LEDMRX_ROWS_PINS[i], Loc_u8BIT);
	}
}
