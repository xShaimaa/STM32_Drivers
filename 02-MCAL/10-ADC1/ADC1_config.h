/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 				                                                     */
/*********************************************************************************/

#ifndef ADC1_CONFIG_H
#define ADC1_CONFIG_H

/*CR1*/
#define ADC_AWDCH		ADC_CH0					/* Analog watchdog channel select 				        	*/
#define ADC_EOCIE		ADC_DISABLE				/* Interrupt enable for EOC (End Of Conversion)         	*/
#define ADC_AWDIE		ADC_ENABLE				/* Analog watchdog interrupt enable				        	*/
#define ADC_JEOCIE		ADC_DISABLE				/* Interrupt enable for injected channels		        	*/
#define ADC_SCAN		ADC_DISABLE				/* Scan mode									        	*/
#define ADC_AWDSGL		ADC_DISABLE				/* Enable the watchdog on a single channel in scan mode		*/
#define ADC_JAUTO		ADC_DISABLE				/* Automatic Injected Group conversion						*/
#define ADC_DISCEN		ADC_DISABLE				/* Discontinuous mode on regular channels					*/
#define ADC_JDISCEN		ADC_DISABLE				/* Discontinuous mode on injected channels					*/
#define ADC_DISCNUM		ADC_1_Channel			/* Discontinuous mode channel count							*/
#define ADC_DUALMOD		ADC_DISABLE				/* Dual mode selection										*/
#define ADC_JAWDEN		ADC_DISABLE				/* Analog watchdog enable on injected channels				*/
#define ADC_AWDEN		ADC_ENABLE				/* Analog watchdog enable on regular channels				*/

/* CR2 */
#define ADC_CONT		ADC_ENABLE				/* Continuous conversion 									*/
#define ADC_CAL			ADC_DISABLE				/* A/D Calibration 											*/
#define ADC_RSTCAL		ADC_DISABLE				/* Reset calibration 										*/
#define ADC_DMA			ADC_DISABLE				/* Direct memory access mode 								*/
#define ADC_ALIGN		ADC_RIGHT_ALIGNMENT		/* Data alignment			 								*/
#define ADC_JEXTSEL		ADC_JSWSTART			/* External event select for injected group					*/
#define ADC_JEXTTRIG	ADC_DISABLE				/* External trigger conversion mode for injected channels	*/
#define ADC_EXTSEL		ADC_SWSTART				/* External event select for regular group					*/
#define ADC_EXTTRIG		ADC_DISABLE				/* External trigger conversion mode for regular channels	*/
#define ADC_TSVREFE		ADC_DISABLE				/* Temperature sensor and V_REFINT enable					*/

/* SMPR2 */
#define ADC_SMP0		ADC_1_5_CYCLES			/* Channel 1 Sample time selection 							*/

#define ADC_REGULAR_SEQUENCE_LENGTH		ADC_1_CONVERSION			/* Regular channel sequence length 		*/

#endif 
