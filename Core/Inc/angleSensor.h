#ifndef AS5600_H
#define AS5600_H

#include "stm32f4xx_hal.h"

#define AS5600_ADDRESS 0x36

uint16_t AS5600_ReadAngle(I2C_HandleTypeDef *hi2c);

#endif /* AS5600_H */
