#ifndef AS5600_H
#define AS5600_H

#include "stm32f4xx_hal.h"
#include "fonts.h"

#define AS5600_ADDRESS 0x36

extern int16_t lastEncoderVal;
extern int32_t encoderAccumulator;
extern int32_t smoothedAccumulator;
extern int32_t lastSmoothedAccumulator;

void angleSensorInit(I2C_HandleTypeDef *hi2c);
uint16_t angleSensorReadAngle(I2C_HandleTypeDef *hi2c);
uint8_t angleSensorReadStatus(I2C_HandleTypeDef *hi2c);
uint8_t angleSensorIsMagnetPresent(I2C_HandleTypeDef *hi2c);
int32_t encoderValueFunction(int16_t currentValue, int16_t previousValue, int32_t accumulator);
void angleSensorScrollScan(I2C_HandleTypeDef *hi2c);


#endif /* AS5600_H */
