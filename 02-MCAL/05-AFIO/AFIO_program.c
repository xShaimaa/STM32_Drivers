/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 26 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


void MAFIO_voidSetEXTIConfig(u8 Copy_u8Line, u8 Copy_u8PortMap)
{
	u8 Loc_u8RegIndex = 0;
	
	/* getting the required register index, every reg holds 4 places */
	Loc_u8RegIndex = Copy_u8Line / 4;
	
	/* getting the required offset to set and reset the register */
	Copy_u8Line %= 4;
	Copy_u8Line *= 4;
	
	/* resetting the AFIO_EXTICR[Loc_u8RegIndex] and reloading it with the required value */
	(AFIO -> AFIO_EXTICR[Loc_u8RegIndex]) &= ~((0b1111) 		<< (Copy_u8Line));
	(AFIO -> AFIO_EXTICR[Loc_u8RegIndex]) |=  ((Copy_u8PortMap) << (Copy_u8Line));
}
