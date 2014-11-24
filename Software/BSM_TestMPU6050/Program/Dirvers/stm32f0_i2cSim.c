/*====================================================================================================*/
/*====================================================================================================*/
#include "stm32f0_system.h"
#include "stm32f0_i2cSim.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define I2Cx                USART1
#define I2Cx_CLK            RCC_APB2Periph_USART1

#define I2Cx_SCL_PIN        GPIO_Pin_9
#define I2Cx_SCL_GPIO_PORT  GPIOA
#define I2Cx_SCL_GPIO_CLK   RCC_AHBPeriph_GPIOA

#define I2Cx_SDA_PIN        GPIO_Pin_10
#define I2Cx_SDA_GPIO_PORT  GPIOA
#define I2Cx_SDA_GPIO_CLK   RCC_AHBPeriph_GPIOA

#define SCL_L     (GPIO_ResetBits(I2Cx_SCL_GPIO_PORT, I2Cx_SCL_PIN))
#define SCL_H     (GPIO_SetBits(I2Cx_SCL_GPIO_PORT, I2Cx_SCL_PIN))
#define SDA_L     (GPIO_ResetBits(I2Cx_SDA_GPIO_PORT, I2Cx_SDA_PIN))
#define SDA_H     (GPIO_SetBits(I2Cx_SDA_GPIO_PORT, I2Cx_SDA_PIN))
#define SDA_READ  (GPIO_ReadInputDataBit(I2Cx_SDA_GPIO_PORT, I2Cx_SDA_PIN))
/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_Config
**功能 : Wait Signal Write/Read
**輸入 : None
**輸出 : None
**使用 : I2C_Config();
**====================================================================================================*/
/*====================================================================================================*/
void I2C_Config( void )
{
  GPIO_InitTypeDef  GPIO_InitStruct; 

  /* GPIO Clk Init *************************************************************/
  RCC_AHBPeriphClockCmd(I2Cx_SCL_GPIO_CLK, ENABLE);
  RCC_AHBPeriphClockCmd(I2Cx_SDA_GPIO_CLK, ENABLE);

  GPIO_InitStruct.GPIO_Pin =  I2Cx_SCL_PIN;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(I2Cx_SCL_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin =  I2Cx_SDA_PIN;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(I2Cx_SDA_GPIO_PORT, &GPIO_InitStruct);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_Delay
**功能 : Wait Signal Write/Read
**輸入 : None
**輸出 : None
**使用 : I2C_Delay();
**====================================================================================================*/
/*====================================================================================================*/
static void I2C_Delay( void )
{
  uint8_t i = 20;

  while(i) {
    i--;
  }
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_Start
**功能 : I2C Start Signal
**輸入 : None
**輸出 : None
**使用 : I2C_Start();
**====================================================================================================*/
/*====================================================================================================*/
static void I2C_Start( void )
{
  SDA_H;
  SCL_H;
  I2C_Delay();
  SDA_L;
  I2C_Delay();
}

/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_Stop
**功能 : I2C Stop Signal
**輸入 : None
**輸出 : None
**使用 : I2C_Stop();
**====================================================================================================*/
/*====================================================================================================*/
static void I2C_Stop( void )
{
  SDA_L;
  SCL_H;
  I2C_Delay();
  SDA_H;
  I2C_Delay();
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_SendACK
**功能 : I2C Send Acknowledge Signal
**輸入 : Ack
**輸出 : None
**使用 : I2C_SendACK(1);
**====================================================================================================*/
/*====================================================================================================*/
static void I2C_SendACK( uint8_t SendACK )
{
  SCL_L;
  if(SendACK)
    SDA_H;
  else
    SDA_L;
  I2C_Delay();
  SCL_H;
  I2C_Delay();
  SCL_L;
  I2C_Delay();
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_RecvACK
**功能 : I2C Recv Acknowledge Signal
**輸入 : None
**輸出 : RecvACK
**使用 : RecvACK = I2C_RecvACK();
**====================================================================================================*/
/*====================================================================================================*/
static uint8_t I2C_RecvACK( void )
{
  uint8_t RecvACK = 0;

  SCL_L;
  SDA_H;
  I2C_Delay();
	SCL_H;
	I2C_Delay();
  RecvACK = SDA_READ;
	SCL_L;
	I2C_Delay();

  return RecvACK;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_SendByte
**功能 : I2C Send Byte
**輸入 : SendByte
**輸出 : None
**使用 : I2C_SendByte(SendByte);
**====================================================================================================*/
/*====================================================================================================*/
void I2C_SendByte( uint8_t SendByte )
{
  uint8_t i = 8;

  while(i--) {
    SCL_L;
    I2C_Delay();
    if(SendByte & 0x80) // MSB First
      SDA_H;
    else 
      SDA_L;
    SendByte = SendByte << 1;
    I2C_Delay();
    SCL_H;
    I2C_Delay();
  }
  SCL_L;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_RecvByte
**功能 : I2C Recv Byte
**輸入 : None
**輸出 : RecvByte
**使用 : RecvByte = I2C_RecvByte();
**====================================================================================================*/
/*====================================================================================================*/
uint8_t I2C_RecvByte( void )
{
  uint8_t i = 8;
  uint8_t RecvByte = 0;

  SDA_H;
  while(i--) {
    RecvByte = RecvByte << 1;
    SCL_L;
    I2C_Delay();
    SCL_H;
    I2C_Delay();
    if(SDA_READ) {
      RecvByte |= 0x01;
    }
  }
  SCL_L;

  return RecvByte;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_WriteReg
**功能 : I2C Write Register
**輸入 : SlaveAddr, RegisterAddr, WriteData
**輸出 : None
**使用 : I2C_WriteReg(SlaveAddr, RegisterAddr, WriteData);
**====================================================================================================*/
/*====================================================================================================*/
void I2C_WriteReg( uint8_t SlaveAddr, uint8_t RegisterAddr, uint8_t WriteData )
{
  I2C_Start();
  I2C_SendByte(SlaveAddr);
  I2C_RecvACK();
  I2C_SendByte(RegisterAddr);
  I2C_RecvACK();
  I2C_SendByte(WriteData);
  I2C_RecvACK();
  I2C_Stop();
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_ReadReg
**功能 : I2C Read Register
**輸入 : SlaveAddr, RegisterAddr, *ReadData
**輸出 : None
**使用 : I2C_ReadReg(SlaveAddr, RegisterAddr, &ReadData);
**====================================================================================================*/
/*====================================================================================================*/
void I2C_ReadReg( uint8_t SlaveAddr, uint8_t RegisterAddr, uint8_t *ReadData )
{
  I2C_Start();
  I2C_SendByte(SlaveAddr);
  I2C_RecvACK();
  I2C_SendByte(RegisterAddr);
  I2C_RecvACK();
  I2C_Start();
  I2C_SendByte(SlaveAddr | 0x01);
  I2C_RecvACK();
  *ReadData = I2C_RecvByte();
  I2C_SendACK(1);
  I2C_Stop();
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : I2C_ReadRegs
**功能 : I2C Read Multiple Register
**輸入 : SlaveAddr, RegisterAddr, *ReadData, NumByte
**輸出 : None
**使用 : I2C_ReadRegs(SlaveAddr, RegisterAddr, ReadData, NumByte);
**====================================================================================================*/
/*====================================================================================================*/
void I2C_ReadRegs( uint8_t SlaveAddr, uint8_t RegisterAddr, uint8_t *ReadData, uint8_t NumByte )
{
  uint8_t i = 0;

  I2C_Start();
  I2C_SendByte(SlaveAddr);
  I2C_RecvACK();
  I2C_SendByte(RegisterAddr);
  I2C_RecvACK();
  I2C_Start();
  I2C_SendByte(SlaveAddr | 0x01);
  I2C_RecvACK();
  for(i=0; i<NumByte; i++) {
    ReadData[i] = I2C_RecvByte();
    if(i == NumByte-1)
      I2C_SendACK(1);
    else
      I2C_SendACK(0);
  }
  I2C_Stop();
}
/*====================================================================================================*/
/*====================================================================================================*/
