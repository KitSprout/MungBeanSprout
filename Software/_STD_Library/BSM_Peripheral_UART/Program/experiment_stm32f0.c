/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f0_system.h"
#include "experiment_stm32f0.h"
#include "module_rs232.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
#define RECV_DATA_SIZE    1
#define RECV_DATA_TIMEOUT 500

int main( void )
{
  int8_t State = ERROR;
  int8_t RecvData = 0;

  RS232_Config();

  RS232_SendStr((int8_t*)"\r\nHello World!\r\n\r\n");

  while(1) {
    State = RS232_RecvDataWTO(&RecvData, RECV_DATA_SIZE, RECV_DATA_TIMEOUT);
    if(State == ERROR)
      RS232_SendStr((int8_t*)"Timeout ... \r\n");
    else if(RecvData == 0x0D)  // if press enter
      RS232_SendStr((int8_t*)"\r\n");
    else
      RS232_SendData(&RecvData, RECV_DATA_SIZE);
  }
}
/*=====================================================================================================*/
/*=====================================================================================================*/
