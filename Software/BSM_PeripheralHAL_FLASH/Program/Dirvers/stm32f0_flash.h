/* #include "stm32f0_flash.h" */

#ifndef __STM32F0_FLASH_H
#define __STM32F0_FLASH_H

#include "stm32f0xx_hal.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
// STM32F03x(16KB)  Page 0~15
#define FLASH_START_ADDR        ((uint32_t)0x08000000)
#define FLASH_PAGE_ADDR(PAGE)   ((uint32_t)(FLASH_START_ADDR + FLASH_PAGE_SIZE*(PAGE)))
/*=====================================================================================================*/
/*=====================================================================================================*/
HAL_StatusTypeDef Flash_WritePageU8( uint32_t WriteAddr, const uint8_t *WriteData, uint16_t DataLens );
HAL_StatusTypeDef Flash_WritePageU16( uint32_t WriteAddr, const uint16_t *WriteData, uint16_t DataLens );
HAL_StatusTypeDef Flash_WritePageU32( uint32_t WriteAddr, const uint32_t *WriteData, uint16_t DataLens );
void              Flash_ReadPageU8( uint32_t ReadAddr, uint8_t *ReadData, uint16_t DataLens );
void              Flash_ReadPageU16( uint32_t ReadAddr, uint16_t *ReadData, uint16_t DataLens );
void              Flash_ReadPageU32( uint32_t ReadAddr, uint32_t *ReadData, uint16_t DataLens );
HAL_StatusTypeDef Flash_ErasePages( uint32_t ErasePageStart, uint32_t NumPages );
/*=====================================================================================================*/
/*=====================================================================================================*/
#endif	 
