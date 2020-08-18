/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 8 Aug 2020                                                        */
/*********************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/* RCC Buses */
#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2

/* AHP1 peripherals id bits */
#define DMA1_PER     0
#define DMA2_PER     1
#define SRAM_PER     2
#define FLITF_PER    4
#define CRCE_PER     6
#define FSMC_PER     8
#define SDIO_PER     10

/* APB1 peripherals id bits */
#define TIM2_PER     0
#define TIM3_PER     1
#define TIM4_PER     2
#define TIM5_PER     3
#define TIM6_PER     4
#define TIM7_PER     5
#define TIM12_PER    6
#define TIM13_PER    7
#define TIM14_PER    8
#define WWD_PER      11 
#define SPI2_PER     14
#define SPI3_PER     15
#define USART2_PER   17
#define USART3_PER   18
#define USART4_PER   19
#define USART5_PER   20
#define I2C1_PER     21
#define I2C2_PER     22
#define USB_PER      23
#define CAN_PER      25
#define BKP_PER      27
#define PWR_PER      28
#define DAC_PER      29

/* APB2 peripherals id bits */
#define AFIO_PER     0
#define IOPA_PER     2
#define IOPB_PER     3
#define IOPC_PER     4
#define IOPD_PER     5
#define IOPE_PER     6
#define IOPF_PER     7  
#define IOPG_PER     8
#define ADC1_PER     9
#define ADC2_PER     10
#define TIM1_PER     11
#define SPI1_PER     12
#define TIM8_PER     13
#define USART1_PER   14
#define ADC3_PER     15
#define TIM9_PER     19
#define TIM10_PER    20
#define TIM11_PER    21

/* public functions prototypes */

/******************************************************************************
* Description : initializing the system clock
* Parameters  : void
* Return type : void
******************************************************************************/
void RCC_voidInitSysClock(void);

/******************************************************************************
* Description : Enabling the RCC for a perphiral
* Parameters  : BusId, PerId
* Return type : void
******************************************************************************/
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

/******************************************************************************
* Description : disabling the RCC for a perphiral
* Parameters  : BusId, PerId
* Return type : void
******************************************************************************/
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif
