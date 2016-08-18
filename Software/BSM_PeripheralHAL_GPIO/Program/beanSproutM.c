/*=====================================================================================================*/
/*=====================================================================================================*/
#include "drivers\stm32f0_system.h"

#include "beanSproutM.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
void BSM_Init( void )
{
  BSM_GPIO_Config();
}
/*=====================================================================================================*/
/*=====================================================================================================*/
#define GPIO_A_PINs       GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_9 | GPIO_PIN_10
#define GPIO_A_GPIO_PORT  GPIOA
#define GPIO_A_Set()      HAL_GPIO_WritePin(GPIO_A_GPIO_PORT, GPIO_A_PINs, GPIO_PIN_SET)
#define GPIO_A_Reset()    HAL_GPIO_WritePin(GPIO_A_GPIO_PORT, GPIO_A_PINs, GPIO_PIN_RESET)
#define GPIO_A_Toggle()   HAL_GPIO_TogglePin(GPIO_A_GPIO_PORT, GPIO_A_PINs)

#define GPIO_B_PINs       GPIO_PIN_1
#define GPIO_B_GPIO_PORT  GPIOB
#define GPIO_B_Set()      HAL_GPIO_WritePin(GPIO_B_GPIO_PORT, GPIO_B_PINs, GPIO_PIN_SET)
#define GPIO_B_Reset()    HAL_GPIO_WritePin(GPIO_B_GPIO_PORT, GPIO_B_PINs, GPIO_PIN_RESET)
#define GPIO_B_Toggle()   HAL_GPIO_TogglePin(GPIO_B_GPIO_PORT, GPIO_B_PINs)

void BSM_Loop( void )
{
  while(1) {
    GPIO_A_Toggle();
    GPIO_B_Toggle();
    delay_ms(100);
  }
}
/*=====================================================================================================*/
/*=====================================================================================================*/
