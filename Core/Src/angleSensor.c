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

uint8_t AS5600_ReadStatus(I2C_HandleTypeDef *hi2c)
{
    uint8_t status;

    // Read the status from the AS5600 chip
    HAL_I2C_Mem_Read(hi2c, AS5600_ADDRESS<<1, 0x0B, I2C_MEMADD_SIZE_8BIT, &status, 1, 100);

    return status;
}

uint8_t AS5600_IsMagnetPresent(I2C_HandleTypeDef *hi2c)
{
    uint8_t status = AS5600_ReadStatus(hi2c);

    // Check if the magnet is too high or too low
    if((status & 0x08) || (status & 0x10)) {
        // Magnet is not present or not properly placed
        return 0; // returning 0 for false
    } else {
        // Magnet is present and properly placed
        return 1; // returning 1 for true
    }
}
