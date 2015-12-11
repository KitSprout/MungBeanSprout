/* #include "module_mpu6050.h" */

#ifndef __MODULE_MPU6050_H
#define __MODULE_MPU6050_H

#include "stm32f0xx_hal.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
typedef enum {
  MPU_GyrLPS_250Hz   = 0x00,
  MPU_GyrLPS_184Hz   = 0x01,
  MPU_GyrLPS_92Hz    = 0x02,
  MPU_GyrLPS_41Hz    = 0x03,
  MPU_GyrLPS_20Hz    = 0x04,
  MPU_GyrLPS_10Hz    = 0x05,
  MPU_GyrLPS_5Hz     = 0x06,
  MPU_GyrLPS_3600Hz  = 0x07,
} MPU_GyrLPF_TypeDef;
typedef enum {
  MPU_AccLPS_460Hz   = 0x00,
  MPU_AccLPS_184Hz   = 0x01,
  MPU_AccLPS_92Hz    = 0x02,
  MPU_AccLPS_41Hz    = 0x03,
  MPU_AccLPS_20Hz    = 0x04,
  MPU_AccLPS_10Hz    = 0x05,
  MPU_AccLPS_5Hz     = 0x06,
  MPU_AccLPS_Disable = 0x07,
} MPU_AccLPF_TypeDef;
typedef enum {
  MPU_GyrFS_250dps  = 0x00,
  MPU_GyrFS_500dps  = 0x08,
  MPU_GyrFS_1000dps = 0x10,
  MPU_GyrFS_2000dps = 0x18
} MPU_GyrFS_TypeDef;
typedef enum {
  MPU_AccFS_2g  = 0x00,
  MPU_AccFS_4g  = 0x08,
  MPU_AccFS_8g  = 0x10,
  MPU_AccFS_16g = 0x18
} MPU_AccFS_TypeDef;
typedef enum {
  MPU_MagFS_14b = 0x00,
  MPU_MagFS_16b = 0x10
} MPU_MagFS_TypeDef;

typedef struct {
  MPU_GyrFS_TypeDef  MPU_Gyr_FullScale;
  MPU_GyrLPF_TypeDef MPU_Gyr_LowPassFilter;
  MPU_AccFS_TypeDef  MPU_Acc_FullScale;
  MPU_AccLPF_TypeDef MPU_Acc_LowPassFilter;
  MPU_MagFS_TypeDef  MPU_Mag_FullScale;
} MPU_InitTypeDef;
/*=====================================================================================================*/
/*=====================================================================================================*/
/* ---- Sensitivity --------------------------------------------------------- */

#define MPU6050A_2g       ((float)0.0000610352f)    // 0.0000610352 g/LSB
#define MPU6050A_4g       ((float)0.0001220703f)    // 0.0001220703 g/LSB
#define MPU6050A_8g       ((float)0.0002441406f)    // 0.0002441406 g/LSB
#define MPU6050A_16g      ((float)0.0004882813f)    // 0.0004882813 g/LSB

#define MPU6050G_250dps   ((float)0.007633587786f)  // 0.007633587786 dps/LSB
#define MPU6050G_500dps   ((float)0.015267175572f)  // 0.015267175572 dps/LSB
#define MPU6050G_1000dps  ((float)0.030487804878f)  // 0.030487804878 dps/LSB
#define MPU6050G_2000dps  ((float)0.060975609756f)  // 0.060975609756 dps/LSB

#define MPU6050T_85degC   ((float)0.00294f)         // 0.00294 degC/LSB

/* ---- MPU6050 Reg --------------------------------------------------------- */

#define MPU6050_I2C_ADDR            ((uint8_t)0xD0)
#define MPU6050_Device_ID           ((uint8_t)0x68)

#define MPU6050_SELF_TEST_X         ((uint8_t)0x0D)
#define MPU6050_SELF_TEST_Y         ((uint8_t)0x0E)
#define MPU6050_SELF_TEST_Z         ((uint8_t)0x0F)
#define MPU6050_SELF_TEST_A         ((uint8_t)0x10)
#define MPU6050_SMPLRT_DIV          ((uint8_t)0x19)
#define MPU6050_CONFIG              ((uint8_t)0x1A)
#define MPU6050_GYRO_CONFIG         ((uint8_t)0x1B)
#define MPU6050_ACCEL_CONFIG        ((uint8_t)0x1C)
#define MPU6050_MOT_THR             ((uint8_t)0x1F)
#define MPU6050_FIFO_EN             ((uint8_t)0x23)
#define MPU6050_I2C_MST_CTRL        ((uint8_t)0x24)
#define MPU6050_I2C_SLV0_ADDR       ((uint8_t)0x25)
#define MPU6050_I2C_SLV0_REG        ((uint8_t)0x26)
#define MPU6050_I2C_SLV0_CTRL       ((uint8_t)0x27)
#define MPU6050_I2C_SLV1_ADDR       ((uint8_t)0x28)
#define MPU6050_I2C_SLV1_REG        ((uint8_t)0x29)
#define MPU6050_I2C_SLV1_CTRL       ((uint8_t)0x2A)
#define MPU6050_I2C_SLV2_ADDR       ((uint8_t)0x2B)
#define MPU6050_I2C_SLV2_REG        ((uint8_t)0x2C)
#define MPU6050_I2C_SLV2_CTRL       ((uint8_t)0x2D)
#define MPU6050_I2C_SLV3_ADDR       ((uint8_t)0x2E)
#define MPU6050_I2C_SLV3_REG        ((uint8_t)0x2F)
#define MPU6050_I2C_SLV3_CTRL       ((uint8_t)0x30)
#define MPU6050_I2C_SLV4_ADDR       ((uint8_t)0x31)
#define MPU6050_I2C_SLV4_REG        ((uint8_t)0x32)
#define MPU6050_I2C_SLV4_DO         ((uint8_t)0x33)
#define MPU6050_I2C_SLV4_CTRL       ((uint8_t)0x34)
#define MPU6050_I2C_SLV4_DI         ((uint8_t)0x35)
#define MPU6050_I2C_MST_STATUS      ((uint8_t)0x36)
#define MPU6050_INT_PIN_CFG         ((uint8_t)0x37)
#define MPU6050_INT_ENABLE          ((uint8_t)0x38)
#define MPU6050_INT_STATUS          ((uint8_t)0x3A)
#define MPU6050_ACCEL_XOUT_H        ((uint8_t)0x3B)
#define MPU6050_ACCEL_XOUT_L        ((uint8_t)0x3C)
#define MPU6050_ACCEL_YOUT_H        ((uint8_t)0x3D)
#define MPU6050_ACCEL_YOUT_L        ((uint8_t)0x3E)
#define MPU6050_ACCEL_ZOUT_H        ((uint8_t)0x3F)
#define MPU6050_ACCEL_ZOUT_L        ((uint8_t)0x40)
#define MPU6050_TEMP_OUT_H          ((uint8_t)0x41)
#define MPU6050_TEMP_OUT_L          ((uint8_t)0x42)
#define MPU6050_GYRO_XOUT_H         ((uint8_t)0x43)
#define MPU6050_GYRO_XOUT_L         ((uint8_t)0x44)
#define MPU6050_GYRO_YOUT_H         ((uint8_t)0x45)
#define MPU6050_GYRO_YOUT_L         ((uint8_t)0x46)
#define MPU6050_GYRO_ZOUT_H         ((uint8_t)0x47)
#define MPU6050_GYRO_ZOUT_L         ((uint8_t)0x48)
#define MPU6050_EXT_SENS_DATA_00    ((uint8_t)0x49)
#define MPU6050_EXT_SENS_DATA_01    ((uint8_t)0x4A)
#define MPU6050_EXT_SENS_DATA_02    ((uint8_t)0x4B)
#define MPU6050_EXT_SENS_DATA_03    ((uint8_t)0x4C)
#define MPU6050_EXT_SENS_DATA_04    ((uint8_t)0x4D)
#define MPU6050_EXT_SENS_DATA_05    ((uint8_t)0x4E)
#define MPU6050_EXT_SENS_DATA_06    ((uint8_t)0x4F)
#define MPU6050_EXT_SENS_DATA_07    ((uint8_t)0x50)
#define MPU6050_EXT_SENS_DATA_08    ((uint8_t)0x51)
#define MPU6050_EXT_SENS_DATA_09    ((uint8_t)0x52)
#define MPU6050_EXT_SENS_DATA_10    ((uint8_t)0x53)
#define MPU6050_EXT_SENS_DATA_11    ((uint8_t)0x54)
#define MPU6050_EXT_SENS_DATA_12    ((uint8_t)0x55)
#define MPU6050_EXT_SENS_DATA_13    ((uint8_t)0x56)
#define MPU6050_EXT_SENS_DATA_14    ((uint8_t)0x57)
#define MPU6050_EXT_SENS_DATA_15    ((uint8_t)0x58)
#define MPU6050_EXT_SENS_DATA_16    ((uint8_t)0x59)
#define MPU6050_EXT_SENS_DATA_17    ((uint8_t)0x5A)
#define MPU6050_EXT_SENS_DATA_18    ((uint8_t)0x5B)
#define MPU6050_EXT_SENS_DATA_19    ((uint8_t)0x5C)
#define MPU6050_EXT_SENS_DATA_20    ((uint8_t)0x5D)
#define MPU6050_EXT_SENS_DATA_21    ((uint8_t)0x5E)
#define MPU6050_EXT_SENS_DATA_22    ((uint8_t)0x5F)
#define MPU6050_EXT_SENS_DATA_23    ((uint8_t)0x60)
#define MPU6050_I2C_SLV0_DO         ((uint8_t)0x63)
#define MPU6050_I2C_SLV1_DO         ((uint8_t)0x64)
#define MPU6050_I2C_SLV2_DO         ((uint8_t)0x65)
#define MPU6050_I2C_SLV3_DO         ((uint8_t)0x66)
#define MPU6050_I2C_MST_DELAY_CTRL  ((uint8_t)0x67)
#define MPU6050_SIGNAL_PATH_RESET   ((uint8_t)0x68)
#define MPU6050_MOT_DETECT_CTRL     ((uint8_t)0x69)
#define MPU6050_USER_CTRL           ((uint8_t)0x6A)
#define MPU6050_PWR_MGMT_1          ((uint8_t)0x6B)
#define MPU6050_PWR_MGMT_2          ((uint8_t)0x6C)
#define MPU6050_FIFO_COUNTH         ((uint8_t)0x72)
#define MPU6050_FIFO_COUNTL         ((uint8_t)0x73)
#define MPU6050_FIFO_R_W            ((uint8_t)0x74)
#define MPU6050_WHO_AM_I            ((uint8_t)0x75)	// 0x68
/*=====================================================================================================*/
/*=====================================================================================================*/
void MPU6050_Config( void );
int8_t MPU6050_Init( MPU_InitTypeDef *MPUx );
int8_t MPU6050_Check( void );
void MPU6050_getData( int16_t *dataIMU );
/*=====================================================================================================*/
/*=====================================================================================================*/
#endif
