/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 21 Sep 2020                                                       */
/*********************************************************************************/
#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H


/* Private Functions Prototypes */

/******************************************************************************
* Description : 
* Parameters  : 
* Return type : 
******************************************************************************/		 
static void WriteCommand(u8 Copy_u8Command);

static void WriteData(u8 Coy_u8Data);

static void SetAddress(u8 Copy_u8X1, u8 Copy_u8X2, u8 Copy_u8Y1, u8 Copy_u8Y2);

static void SetPixelData(u16 Copy_u16Pixel);

static void DrawPixel(u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16PixelColor);

#endif 
