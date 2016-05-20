/*=====================================================================================================*/
/*=====================================================================================================*/
#include "drivers\stm32f0_system.h"

#include "beanSproutM_bsp.h"
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

void BSM_GPIO_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Enable all GPIO Clk *******************************************************/
  __GPIOA_CLK_ENABLE();
  __GPIOB_CLK_ENABLE();

  /* GPIO all analog input *****************************************************/
  GPIO_InitStruct.Pin   = GPIO_PIN_All;
  GPIO_InitStruct.Mode  = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  GPIO_InitStruct.Pin   = GPIO_PIN_All & (~(GPIO_PIN_13 | GPIO_PIN_14));
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* GPIO Pin ******************************************************************/
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

  GPIO_InitStruct.Pin   = GPIO_A_PINs;
  HAL_GPIO_Init(GPIO_A_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin   = GPIO_B_PINs;
  HAL_GPIO_Init(GPIO_B_GPIO_PORT, &GPIO_InitStruct);

  /* GPIO Reset Pin ************************************************************/
  GPIO_A_Reset();
  GPIO_B_Reset();
}
/*=====================================================================================================*/
/*=====================================================================================================*/
