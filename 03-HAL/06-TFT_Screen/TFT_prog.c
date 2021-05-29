/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 21 Sep 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_private.h"
#include "TFT_interface.h"
#include "TFT_config.h"
#include "Font8x8.h"

void TFT_voidInit(void)
{
	/* Reset pulse */
	MGPIO_VoidSetPinVal(TFT_RST_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_VoidSetPinVal(TFT_RST_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_VoidSetPinVal(TFT_RST_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_VoidSetPinVal(TFT_RST_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(100);
	MGPIO_VoidSetPinVal(TFT_RST_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);
	
	/* sleep out "SLPOUT" 0x11 command */
	WriteCommand(0x11);
	
	/* wait 150ms */
	MSTK_voidSetBusyWait(150000);
	
	/* color mode "COLMOD" 0x3A command */
	WriteCommand(0x3A);
	
	/* select the parameter {0x03 - 0x05 - 0x06} as data based on RGB mode */
	WriteData(0x05);
	
	/* display on "DISPON" 0x29 command */
	WriteCommand(0x29);
}


void TFT_voidDisplayImage(const u16* Copy_Image)
{
	/* setting the x,y address to display the whole image */
	SetAddress(0, TFT_X_PIXELS, 0, TFT_Y_PIXELS);

	/* displaying the high and low byte pixels of the image */
	for(u16 i = 0; i < (TFT_X_PIXELS * TFT_Y_PIXELS); i++)
	{
		SetPixelData(Copy_Image[i]);
	}
}

void TFT_voidFillColor(u16 Copy_u16Color)
{
	/* setting the x,y address to display the whole image */
	SetAddress(0, TFT_X_PIXELS, 0, TFT_Y_PIXELS);

	/* displaying the high and low byte pixels of the color */
	for(u16 i = 0; i < (TFT_X_PIXELS * TFT_Y_PIXELS); i++)
	{
		SetPixelData(Copy_u16Color);
	}
}


void TFT_voidDrawRectagle(u8 Copy_u8X1, u8 Copy_u8X2, u8 Copy_u8Y1, u8 Copy_u8Y2, u16 Copy_u16Color)
{
	/* validating the address */
	if((Copy_u8X1 < TFT_X_PIXELS) && (Copy_u8X2 < TFT_X_PIXELS)
	&& (Copy_u8Y1 < TFT_Y_PIXELS) && (Copy_u8Y2 < TFT_Y_PIXELS))
	{
		u16 size = (Copy_u8X2 - Copy_u8X1) * (Copy_u8Y2 - Copy_u8Y1);

		/* setting the x,y address to display the whole image */
		SetAddress(Copy_u8X1, Copy_u8X2, Copy_u8Y1, Copy_u8Y2);

		/* drawing the high and low byte pixels */
		for(u16 i = 0; i < size; i++)
		{
			SetPixelData(Copy_u16Color);
		}
	}
}

void TFT_voidDrawChar(u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16Char, u16 Copy_u16CharColor)
{
	/* validating the address */
	if((Copy_u8X < TFT_X_PIXELS) && (Copy_u8X < TFT_X_PIXELS)
	&& (Copy_u8Y < TFT_Y_PIXELS) && (Copy_u8Y < TFT_Y_PIXELS))
	{
		/* getting the ASCII value */
		u8 Loc_u8charIndex = GET_ASCII(Copy_u16Char);

		/**/
		for(u8 i = 0; i < CHAR_X_PIXELS; i++)
		{
			for(u8 j = 0; j < CHAR_Y_PIXELS; j++)
			{
				if(font8x8 [Loc_u8charIndex][i] & (1<<j))
				{
					DrawPixel(Copy_u8X+i, Copy_u8Y+j, Copy_u16CharColor);
				}
			}
		}
	}
}

void TFT_voidDrawText(u8 Copy_u8X, u8 Copy_u8Y, u16 * Copy_u16Text, u16 Copy_u16CTextColor)
{
	while(* Copy_u16Text)
	{
		u8 temp_u8X = Copy_u8X;
		u8 temp_u8Y = Copy_u8Y;

		/* print the first char */
		TFT_voidDrawChar(temp_u8X, temp_u8Y, Copy_u16Text, Copy_u16CTextColor);

		/* make enough space for the next char */
		temp_u8X = Copy_u8X + CHAR_X_PIXELS +1;

		/* when line if full, set cursor to new line */
		if(temp_u8X == TFT_X_PIXELS)
		{
			temp_u8X = Copy_u8X;
			temp_u8Y = Copy_u8Y + (CHAR_Y_PIXELS*2) ;
		}
		Copy_u16Text ++;
	}
}

static void WriteCommand(u8 Copy_u8Command)
{
	u8 Loc_u8Temp;
	
	/* set TFT_A0_PIN pin to low */
	MGPIO_VoidSetPinVal(TFT_A0_PIN, GPIO_LOW);
	
	/* send command over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Command, &Loc_u8Temp);
}

static void WriteData(u8 Coy_u8Data)
{
	u8 Loc_u8Temp;

	/* set TFT_A0_PIN pin to high */
	MGPIO_VoidSetPinVal(TFT_A0_PIN, GPIO_HIGH);
	
	/* send data over SPI */
	MSPI1_voidSendReceiveSynch(Coy_u8Data, &Loc_u8Temp);
}

static void SetAddress(u8 Copy_u8X1, u8 Copy_u8X2, u8 Copy_u8Y1, u8 Copy_u8Y2)
{
	/* validate the required address */
	if((Copy_u8X1 < TFT_X_PIXELS) && (Copy_u8X2 < TFT_X_PIXELS)
	&& (Copy_u8Y1 < TFT_Y_PIXELS) && (Copy_u8Y2 < TFT_Y_PIXELS))
	{
		/* set X address */
		WriteCommand(0x2A);
		/* start byte */
		WriteData((Copy_u8X1 >> 8));  /* MSB */
		WriteData(Copy_u8X1);
		/* end byte */
		WriteData((Copy_u8X2>> 8));   /* MSB */
		WriteData(Copy_u8X2);

		/* set Y address */
		WriteCommand(0x2B);
		/* start */
		WriteData((Copy_u8Y1 >> 8));  /* MSB */
		WriteData(Copy_u8Y1);
		/* end */
		WriteData((Copy_u8Y2 >> 8));  /* MSB */
		WriteData(Copy_u8Y2);

		/* RAM write */
		WriteCommand(0x2C);
	}
}

static void SetPixelData(u16 Copy_u16Pixel)
{
	/* write the high byte */
	WriteData(Copy_u16Pixel >> 8);

	/* write the low byte  */
	WriteData(Copy_u16Pixel & 0x00FF);
}

static void DrawPixel(u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16PixelColor)
{
	/* setting the address */
	SetAddress(Copy_u8X, TFT_X_PIXELS, Copy_u8Y, TFT_Y_PIXELS);
	
	/* filing the pixel */
	SetPixelData(Copy_u16PixelColor);
}


