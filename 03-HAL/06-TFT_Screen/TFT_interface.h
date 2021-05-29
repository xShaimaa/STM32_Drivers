/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 21 Sep 2020                                                       */
/*********************************************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

/* Color Codes */
#define RED		0xF800
#define GREEN	0x07E0
#define BLUE	0x001F
#define BLACK	0x0000
#define WHITE	0xFFFF
#define YELLOW	0xFFE0

/* Public Functions Prototypes */

/******************************************************************************
* Description : 
* Parameters  : void
* Return type : void
******************************************************************************/
void TFT_voidInit(void);

void TFT_voidDisplayImage(const u16* Copy_Image);

void TFT_voidFillColor(u16 Copy_u16Color);

void TFT_voidDrawRectagle(u8 Copy_u8X1, u8 Copy_u8X2, u8 Copy_u8Y1, u8 Copy_u8Y2, u16 Copy_u16Color);

void TFT_voidDrawChar(u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16Char, u16 Copy_u16CharColor);

void TFT_voidDrawText(u8 Copy_u8X, u8 Copy_u8Y, u16 * Copy_u16Text, u16 Copy_u16CTextColor);


#endif
