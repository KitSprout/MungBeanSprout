/*=====================================================================================================*/
/*=====================================================================================================*/
#include "drivers\stm32f0_system.h"
#include "modules\module_serial.h"

#include "experiment_stm32f0.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
void System_Init( void )
{
  HAL_Init();
  Serial_Config();

  Delay_100ms(1);
  printf("\r\nHello World!\r\n\r\n");
}

int main( void )
{
  static uint8_t i = 0;
  static uint8_t recvData = 0;
  static int8_t state = ERROR;

  System_Init();

  while(1) {
    state = Serial_RecvDataWTO(&recvData, 1, 500);
    if(state == ERROR) {
      printf("timeout ... %d\r\n", i);
      i = (i == 255) ? 0 : i + 1;
    }
    else if(recvData == 0x0D)  // if press enter
      printf("\r\n");
    else
      Serial_SendData(&recvData, 1);
  }
}
/*=====================================================================================================*/
/*=====================================================================================================*/
