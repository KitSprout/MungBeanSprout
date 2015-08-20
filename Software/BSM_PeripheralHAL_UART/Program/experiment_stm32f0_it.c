/*====================================================================================================*/
/*====================================================================================================*/
#include "Dirvers\stm32f0_system.h"
/*====================================================================================================*/
/*====================================================================================================*/
void NMI_Handler( void ) {}
void HardFault_Handler( void ) { while(1); }
void SVC_Handler( void ) {}
void PendSV_Handler( void ) {}
void SysTick_Handler( void ) { HAL_IncTick(); }
/*====================================================================================================*/
/*====================================================================================================*/
//void WWDG_IRQHandler(void);
//void RTC_IRQHandler(void);
//void FLASH_IRQHandler(void);
//void RCC_IRQHandler(void);
//void EXTI0_1_IRQHandler(void);
//void EXTI2_3_IRQHandler(void);
//void EXTI4_15_IRQHandler(void);
//void DMA1_Channel1_IRQHandler(void);
//void DMA1_Channel2_3_IRQHandler(void);
//void DMA1_Channel4_5_IRQHandler(void);
//void ADC1_IRQHandler(void);
//void TIM1_BRK_UP_TRG_COM_IRQHandler(void);
//void TIM1_CC_IRQHandler(void);
//void TIM3_IRQHandler(void);
//void TIM14_IRQHandler(void);
//void TIM16_IRQHandler(void);
//void TIM17_IRQHandler(void);
//void I2C1_IRQHandler(void);
//void SPI1_IRQHandler(void);
//void USART1_IRQHandler(void);
/*====================================================================================================*/
/*====================================================================================================*/
