#include "angleSensor.h"

uint16_t AS5600_ReadAngle(I2C_HandleTypeDef *hi2c)
{
    uint8_t buffer[2];
    uint16_t angle;

    // Read the angle from the AS5600 chip
    HAL_I2C_Mem_Read(hi2c, AS5600_ADDRESS<<1, 0x0E, I2C_MEMADD_SIZE_8BIT, buffer, 2, 100);

    // Combine the two bytes to get the angle
    angle = (buffer[0] << 8) | buffer[1];

    return angle;
}
