/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f0_system.h"
#include "modules\module_serial.h"
#include "modules\module_mpu6050.h"

#include "experiment_stm32f0.h"
/*====================================================================================================*/
/*====================================================================================================*/
void Serial_SendDataMATLAB( int16_t *sendData, uint8_t lens );
void XIO_SerialQscilloscope( int16_t *sendData, uint8_t lens );
/*====================================================================================================*/
/*====================================================================================================*/
void System_Init( void )
{
  MPU_InitTypeDef MPU_InitStruct;

  HAL_Init();
  Serial_Config();
  MPU6050_Config();

  Delay_100ms(1);
  printf("\r\nHello World!\r\n\r\n");

  printf("MPU6050_Init ... ");
  MPU_InitStruct.MPU_Gyr_FullScale     = MPU_GyrFS_2000dps;
  MPU_InitStruct.MPU_Gyr_LowPassFilter = MPU_GyrLPS_41Hz;
  MPU_InitStruct.MPU_Acc_FullScale     = MPU_AccFS_4g;
  MPU_InitStruct.MPU_Acc_LowPassFilter = MPU_AccLPS_41Hz;
  while(MPU6050_Init(&MPU_InitStruct) != SUCCESS) {
    printf("ERROR\r\n");
    Delay_100ms(10);
  }
  printf("SUCCESS\r\n");
}

int main( void )
{
  int16_t IMU_Buf[10] = {0};

  System_Init();

  while(1) {
    MPU6050_getData(IMU_Buf);
    XIO_SerialQscilloscope(IMU_Buf+1, 6);
//    printf("Acc.X = %d\tAcc.Y = %d\tAcc.Z = %d\tGyr.X = %d\tGyr.Y = %d\tGyr.Z = %d\tTemp = %d\r\n", IMU_Buf[1], IMU_Buf[2], IMU_Buf[3], IMU_Buf[4], IMU_Buf[5], IMU_Buf[6], IMU_Buf[0]);
//    Serial_SendDataMATLAB(IMU_Buf, 7);
    Delay_10ms(1);
  }
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : Serial_SendDataMATLAB
**功能 : Send Data to MATLAB 
**輸入 : *sendData, lens
**輸出 : None
**使用 : Serial_SendDataMATLAB(sendData, 7); // int16 * 7 data
**====================================================================================================*/
/*====================================================================================================*/
void Serial_SendDataMATLAB( int16_t *sendData, uint8_t lens )
{
  uint8_t tmpData[32] = {0};  // tmpData lens >= 2 * lens + 4
  uint8_t *ptrData = tmpData;
  uint8_t dataBytes = lens << 1;
  uint8_t dataLens = dataBytes + 4;
  uint8_t count = 0;
  uint16_t tmpSum = 0;

  tmpData[0] = 'S';
  while(count < dataBytes) {
    tmpData[count+1] = Byte8H(sendData[count >> 1]);
    tmpData[count+2] = Byte8L(sendData[count >> 1]);
    count = count + 2;
  }
  for(uint8_t i = 0; i < dataBytes; i++)
    tmpSum += tmpData[i+1];
  tmpData[dataLens - 3] = (uint8_t)(tmpSum & 0x00FF);
  tmpData[dataLens - 2] = '\r';
  tmpData[dataLens - 1] = '\n';

  do {
    Serial_SendByte(*ptrData++);
  } while(--dataLens);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : XIO_SerialQscilloscope
**功能 : Send Data to SerialOsc 
**輸入 : *sendData, lens
**輸出 : None
**使用 : XIO_SerialQscilloscope(sendData, 6); // int16 * 6 data
**====================================================================================================*/
/*====================================================================================================*/
void XIO_SerialQscilloscope( int16_t *sendData, uint8_t lens )
{
  while(lens--) {
    printf("%d", *sendData++);
    if(lens == 0)
      Serial_SendByte('\r');
    else
      Serial_SendByte(',');
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
