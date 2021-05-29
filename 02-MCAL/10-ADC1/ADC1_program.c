/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 				                                                     */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC1_interface.h"
#include "ADC1_private.h"
#include "ADC1_config.h"


void ADC1_voidInit(void)
{
	/* Configuring CR1 */
	/* configuring analog watchdog channel select bits */
	#if (ADC_AWDCH == ADC_CH0) 
	(ADC1 -> CR1) = (AWDCH << 0x00000);
	#endif
	
	/* configuring EOC interrupt */			
	#if (ADC_EOCIE == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR1), EOCIE);
	#endif
	
	/* configuring analog watchdog interrupt */			
	#if (ADC_AWDIE == ADC_ENABLE)
	SET_BIT((ADC1 -> CR1), AWDIE);
	#endif
	
	/* configuring interrupt for injected channels */			
	#if (ADC_JEOCIE == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR1), JEOCIE);
	#endif
	
	/* configuring scan mode */			
	#if (ADC_SCAN == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR1), SCAN);
	#endif
	
	/* configuring watchdog on single channel in scan mode */			
	#if (ADC_AWDSGL == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR1), AWDSGL);
	#endif
	
	/* configuring automatic injected group conversion */			
	#if (ADC_JAUTO == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR1), JAUTO);
	#endif
	
	/* configuring discontinuous mode on regular channels*/				
	#if (ADC_DISCEN == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR1), DISCEN);
	#endif
	
	/* configuring discontinuous mode on injected channels*/			
	#if (ADC_JDISCEN ==	ADC_DISABLE)
	CLR_BIT((ADC1 -> CR1), JDISCEN);
	#endif
	
	/* configuring number of channels to be conerted in discontinuous mode */			
	#if (ADC_DISCNUM ==	ADC_1_Channel)
	(ADC1 -> CR1) = (DISCNUM << 0x000);
	#endif
	
	/* configuring ADC1 dual mode */			
	#if (ADC_DUALMOD ==	ADC_DISABLE)
	(ADC1 -> CR1) = (DUALMOD << 0x0000);
	#endif
	
	/* configuring analog watchdog disable for injected channels */			
	#if (ADC_JAWDEN == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR1), JAWDEN);
	#endif
	
	/* configuring analog watchdog for regular channels */			
	#if (ADC_AWDEN == ADC_ENABLE)
	SET_BIT((ADC1 -> CR1), AWDEN);
	#endif


	/* Configuring CR2 */
	/* configuring continuous conversion mode */
	#if (ADC_CONT == ADC_ENABLE)
	SET_BIT((ADC1 -> CR2), CONT);
	#endif
	
	/* configuring calibration */				
	#if (ADC_CAL == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR2), CAL);
	#endif
	
	/* configuring calibration */	
	#if (ADC_RSTCAL == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR2), RSTCAL);
	#endif
	
	/* configuring direct memory access mode */	
	#if (ADC_DMA == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR2), DMA);
	#endif
	
	/* configuring data alignment */
	#if (ADC_ALIGN == ADC_RIGHT_ALIGNMENT)
	CLR_BIT((ADC1 -> CR2), ALIGN);
	#endif
	
	/* configuring external event select for injected group*/
	#if (ADC_JEXTSEL == ADC_JSWSTART)
	(ADC1 -> CR2) = (JEXTSEL << 0x111);
	#endif
	
	 /* configuring external trigger conversion mode for injected channels*/
	#if (ADC_JEXTTRIG == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR2), JEXTTRIG);
	#endif
	
	/* configuring external event select for regular group */
	#if (ADC_EXTSEL == ADC_SWSTART)
	(ADC1 -> CR2) = (EXTSEL << 0x111);
	#endif
	
	/* configuring external trigger conversion mode for regular channels */
	#if (ADC_EXTTRIG == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR2), EXTTRIG);
	#endif
	
	/* configuring Temp. sensor channel */
	#if (ADC_TSVREFE == ADC_DISABLE)
	CLR_BIT((ADC1 -> CR2), TSVREFE);
	#endif


	/* Configuring SMPR2 */
	/* configuring sample time selection */
	#if (ADC_SMP0 == ADC_1_5_CYCLES)
	#endif
	
	
	/* Configuring SQR1 */
	/* configuring regular channel sequence length */
	#if (ADC_REGULAR_SEQUENCE_LENGTH == ADC_1_CONVERSION)
	(ADC1 -> SQR[0]) = (L << 0x0000);
	
	/* Configuring SQR3 */
	(ADC1 -> SQR[2]) = (SQ1 << 0x00000);
	#endif


	/* Turning on ADC1 from power down state from CR2 */
	SET_BIT((ADC1 -> CR2), ADON);
}


u16 ADC1_u16GetRegularVal(void)
{
	/* writing 1 again to ADON bit to wake the ADC conversion */
	SET_BIT((ADC1 -> CR2), ADON);

	/* Setting SWSTART bit to start conversion */
	SET_BIT((ADC1 -> CR2), SWSTART);

	/* wait for conversion to end */
	while (GET_BIT((ADC1 -> SR), EOC) == 0);

	/* return data */
	return (ADC1 -> DR);
}


/* Private functions */

