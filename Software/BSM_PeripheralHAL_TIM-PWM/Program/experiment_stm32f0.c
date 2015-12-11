/*=====================================================================================================*/
/*=====================================================================================================*/
#include "drivers\stm32f0_system.h"

#include "experiment_stm32f0.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
#define PWM_MIN 0
#define PWM_MED 50
#define PWM_MAX 100

#define PWM TIM3->CCR1  // PA6
/*=====================================================================================================*/
/*=====================================================================================================*/
void System_Init( void )
{
  HAL_Init();
  TIM_PWM_Config();
}

int main( void )
{
  uint8_t state = 0;
  uint32_t i = PWM_MIN;

  System_Init();

  while(1) {
    
    i = (state) ? (i - 1) : (i + 1);
    PWM = i;
    if(i == PWM_MAX){ state = 1; }
    if(i == PWM_MIN){ state = 0; Delay_1ms(1000);}
    Delay_10ms(4);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void TIM_PWM_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;
  TIM_HandleTypeDef TIM_HandleStruct;
  TIM_OC_InitTypeDef TIM_OC_InitStruct;

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_TIM3_CLK_ENABLE();

  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;

  GPIO_InitStruct.Alternate = GPIO_AF1_TIM3;
  GPIO_InitStruct.Pin       = GPIO_PIN_6;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* TIM1 use APB1 = 48 MHz */
  TIM_HandleStruct.Instance               = TIM3;
  TIM_HandleStruct.Init.Prescaler         = 480 - 1;
  TIM_HandleStruct.Init.Period            = PWM_MAX - 1;
  TIM_HandleStruct.Init.ClockDivision     = 0;
  TIM_HandleStruct.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TIM_HandleStruct.Init.RepetitionCounter = 0;
  HAL_TIM_PWM_Init(&TIM_HandleStruct);

  TIM_OC_InitStruct.OCMode       = TIM_OCMODE_PWM2;
  TIM_OC_InitStruct.OCFastMode   = TIM_OCFAST_DISABLE;
  TIM_OC_InitStruct.OCPolarity   = TIM_OCPOLARITY_LOW;
  TIM_OC_InitStruct.OCNPolarity  = TIM_OCNPOLARITY_HIGH;
  TIM_OC_InitStruct.OCIdleState  = TIM_OCIDLESTATE_SET;
  TIM_OC_InitStruct.OCNIdleState = TIM_OCNIDLESTATE_RESET;

  TIM_OC_InitStruct.Pulse = PWM_MED;
  HAL_TIM_PWM_ConfigChannel(&TIM_HandleStruct, &TIM_OC_InitStruct, TIM_CHANNEL_1);

  HAL_TIM_PWM_Start(&TIM_HandleStruct, TIM_CHANNEL_1);
}
/*=====================================================================================================*/
/*=====================================================================================================*/
