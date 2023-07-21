#include "keyboardScanner.h"
#include "main.h" // Include this if necessary for GPIO functions

void keyboardScanner(void)
{
	HAL_GPIO_TogglePin(LED_STATUS_GPIO_Port, LED_STATUS_Pin);
	HAL_Delay(10);
	HAL_GPIO_TogglePin(LED_STATUS_GPIO_Port, LED_STATUS_Pin);
	HAL_Delay(10);
}
