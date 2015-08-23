/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f0_system.h"
#include "stm32f0_flash.h"
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_WritePageU8
**功能 : U8 Write FLASH
**輸入 : WritePage, *WriteData, DataLen
**輸出 : None
**使用 : Flash_WritePageU8(FLASH_PAGE_ADDR(12), WriteData, 1024);
**=====================================================================================================*/
/*=====================================================================================================*/
HAL_StatusTypeDef Flash_WritePageU8( uint32_t WriteAddr, const uint8_t *WriteData, uint16_t DataLens )
{
  HAL_StatusTypeDef status = HAL_ERROR;

  uint16_t count = 0;

  HAL_FLASH_Unlock();
  do {
    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, WriteAddr + count, Byte16(uint16_t, WriteData[count+1], WriteData[count]));
    count += 2;
  } while((count < DataLens) && (status == HAL_OK));
  HAL_FLASH_Lock();

  return status;
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_WritePageU16
**功能 : U16 Write FLASH
**輸入 : WritePage, *WriteData, DataLen
**輸出 : None
**使用 : Flash_WritePageU16(FLASH_PAGE_ADDR(12), WriteData, 512);
**=====================================================================================================*/
/*=====================================================================================================*/
HAL_StatusTypeDef Flash_WritePageU16( uint32_t WriteAddr, const uint16_t *WriteData, uint16_t DataLens )
{
  HAL_StatusTypeDef status = HAL_ERROR;

  uint16_t count = 0;

  HAL_FLASH_Unlock();
  do {
    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, WriteAddr + (count << 1), WriteData[count]);
  } while((++count < DataLens) && (status == HAL_OK));
  HAL_FLASH_Lock();

  return status;
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_WritePageU32
**功能 : U32 Write Flash
**輸入 : WritePage, *WriteData, DataLen
**輸出 : None
**使用 : Flash_WritePageU32(FLASH_PAGE_ADDR(12), WriteData, 256);
**=====================================================================================================*/
/*=====================================================================================================*/
HAL_StatusTypeDef Flash_WritePageU32( uint32_t WriteAddr, const uint32_t *WriteData, uint16_t DataLens )
{
  HAL_StatusTypeDef status = HAL_ERROR;

  uint16_t count = 0;

  HAL_FLASH_Unlock();
  do {
    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, WriteAddr + (count << 2), WriteData[count]);
  } while((++count < DataLens) && (status == HAL_OK));
  HAL_FLASH_Lock();

  return status;
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ReadPageU8
**功能 : U8 Read FLASH
**輸入 : ReadPage, *ReadData, DataLen
**輸出 : None
**使用 : Flash_ReadPageU8(FLASH_PAGE_ADDR(12), ReadData, 1024);
**=====================================================================================================*/
/*=====================================================================================================*/
void Flash_ReadPageU8( uint32_t ReadAddr, uint8_t *ReadData, uint16_t DataLens )
{
  Flash_ReadPageU32(ReadAddr, (uint32_t*)ReadData, DataLens >> 2);
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ReadPageU16
**功能 : U16 Read FLASH
**輸入 : ReadPage, *ReadData, DataLen
**輸出 : None
**使用 : Flash_ReadPageU16(FLASH_PAGE_ADDR(12), ReadData, 512);
**=====================================================================================================*/
/*=====================================================================================================*/
//void Flash_ReadPageU16( uint32_t ReadAddr, uint16_t *ReadData, uint16_t DataLens )
//{
//  uint16_t count = 0;

//  do {
//    ReadData[count] = (uint16_t)(*(__IO uint32_t*)(ReadAddr + (count << 1)));
//  } while(++count < DataLens);
//}
void Flash_ReadPageU16( uint32_t ReadAddr, uint16_t *ReadData, uint16_t DataLens )
{
  Flash_ReadPageU32(ReadAddr, (uint32_t*)ReadData, DataLens >> 1);
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ReadPageU32
**功能 : U32 Read Flash
**輸入 : ReadPage, *ReadData, DataLen
**輸出 : None
**使用 : Flash_ReadPageU32(FLASH_PAGE_ADDR(12), ReadData, 256);
**=====================================================================================================*/
/*=====================================================================================================*/
void Flash_ReadPageU32( uint32_t ReadAddr, uint32_t *ReadData, uint16_t DataLens )
{
  uint16_t count = 0;

  do {
    ReadData[count] = (uint32_t)(*(__IO uint32_t*)(ReadAddr + (count << 2)));
  } while(++count < DataLens);
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : Flash_ErasePages
**功能 : Erase Flash Memory
**輸入 : ErasePageStart, NumPages
**輸出 : status
**使用 : Flash_ErasePages(FLASH_PAGE_ADDR(16), 8);
**=====================================================================================================*/
/*=====================================================================================================*/
HAL_StatusTypeDef Flash_ErasePages( uint32_t ErasePageStart, uint32_t NumPages )
{
  FLASH_EraseInitTypeDef EraseInitStruct;
  HAL_StatusTypeDef status = HAL_ERROR;

  uint32_t PageError = 0;

  HAL_FLASH_Unlock();
  EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
  EraseInitStruct.PageAddress = ErasePageStart;
  EraseInitStruct.NbPages     = NumPages;
  status = HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);
  HAL_FLASH_Lock();

  return status;
}
/*=====================================================================================================*/
/*=====================================================================================================*/
