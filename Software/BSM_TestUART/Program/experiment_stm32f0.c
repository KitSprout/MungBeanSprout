/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f0_system.h"
#include "experiment_stm32f0.h"
#include "module_rs232.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
int main( void )
{
  int8_t RecvData = 0;

  SystemInit();
  RS232_Config();

  RS232_SendStr((int8_t*)"\r\nHello World!\r\n\r\n");

  while(1) {
    RS232_RecvData(&RecvData, 1);
    if(RecvData == 0x0D)  // if press enter
      RS232_SendStr((int8_t*)"\r\n");
    else
      RS232_SendData(&RecvData, 1);
  }
}
/*=====================================================================================================*/
/*=====================================================================================================*/
void GPIO_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Clk Init *************************************************************/
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0  | GPIO_Pin_1  | GPIO_Pin_2  | GPIO_Pin_3  | GPIO_Pin_4  |
                             GPIO_Pin_5  | GPIO_Pin_6  | GPIO_Pin_7  | GPIO_Pin_9  | GPIO_Pin_10;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
}
/*=====================================================================================================*/
/*=====================================================================================================*/
