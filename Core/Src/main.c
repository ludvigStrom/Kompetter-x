/* USER CODE BEGIN Header */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "fonts.h"
#include "ssd1306.h"
#include "angleSensor.h"
#include <string.h>
#include "stdio.h"
#include "usbd_hid.h"
#include <stdint.h>
#include "utils.h"
#include "ImprovedKeylayouts.h"
#include "keyboardScanner.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

typedef struct
{
    uint8_t REPORT_ID;
    uint8_t MODIFIER;
    uint8_t RESERVED;
    uint8_t KEYCODE1;
    uint8_t KEYCODE2;
    uint8_t KEYCODE3;
    uint8_t KEYCODE4;
    uint8_t KEYCODE5;
    uint8_t KEYCODE6;
} keyboardHID;

keyboardHID keyboardhid = {0x01,0,0,0,0,0,0,0,0};

typedef struct {
    uint8_t REPORT_ID;    		// REPORT_ID
    uint8_t BUTTONS;     		// Button states - bitmapped
    int8_t  X;           		// X-axis movement
    int8_t  Y;           		// Y-axis movement
    int8_t  WHEEL;       		// Wheel movement
    uint8_t VENDOR_DEFINED[2];  // Vendor-defined usage
} mouseHID;

mouseHID mousehid = {0x02,0,0,0,0,0};

uint8_t screenNotUpdated = 1;

GPIO_TypeDef* row_ports[NUM_ROWS] = {KEY_ROW_1_GPIO_Port, KEY_ROW_2_GPIO_Port, KEY_ROW_3_GPIO_Port, KEY_ROW_4_GPIO_Port};
uint16_t row_pins[NUM_ROWS] = {KEY_ROW_1_Pin, KEY_ROW_2_Pin, KEY_ROW_3_Pin, KEY_ROW_4_Pin};
GPIO_TypeDef* col_ports[NUM_COLS] = {KEY_COL_1_GPIO_Port, KEY_COL_2_GPIO_Port, KEY_COL_3_GPIO_Port, KEY_COL_4_GPIO_Port};
uint16_t col_pins[NUM_COLS] = {KEY_COL_1_Pin, KEY_COL_2_Pin, KEY_COL_3_Pin, KEY_COL_4_Pin};

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

SPI_HandleTypeDef hspi2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C2_Init(void);
static void MX_SPI2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_USB_DEVICE_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */

  HAL_GPIO_TogglePin(LED_STATUS_GPIO_Port, LED_STATUS_Pin); // Toggle state of LED

  HAL_Delay(50);

  SSD1306_Init (); // initialize the display

  HAL_Delay(50);

  SSD1306_GotoXY (0,0);
  SSD1306_Puts ("Kompetter-X", &Font_11x18, 1);
  SSD1306_GotoXY (0, 20);
  SSD1306_Puts ("v.02", &Font_7x10, 1);
  SSD1306_UpdateScreen();

  HAL_Delay(1500);

  SSD1306_Clear();
  HAL_GPIO_TogglePin(LED_STATUS_GPIO_Port, LED_STATUS_Pin); // Toggle state of LED
  SSD1306_GotoXY(0, 30);
  SSD1306_Puts("Key: ", &Font_7x10, 1);
  SSD1306_GotoXY(0, 40);
  SSD1306_Puts("--  ", &Font_11x18, 1);

  SSD1306_GotoXY(40, 30);
  SSD1306_Puts("Magnet: ", &Font_7x10, 1);
  SSD1306_GotoXY(40, 40);
  SSD1306_Puts("--  ", &Font_11x18, 1);
  SSD1306_UpdateScreen();

  keyboardScannerInit();

  //lastEncoderVal = AS5600_ReadAngle(&hi2c2);
  HAL_GPIO_TogglePin(LED_STATUS_GPIO_Port, LED_STATUS_Pin);
  angleSensorInit(&hi2c2);
  HAL_GPIO_TogglePin(LED_STATUS_GPIO_Port, LED_STATUS_Pin);


  /* USER CODE END 2 */


  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	angleSensorScrollScan(&hi2c2);
	keyboardScan();

	// Check if the HID report has changed for the keyboard
	uint8_t report_changed = 0;
	for (int i = 0; i < NUM_KEYS; i++) {
	    if (hid_report[i] != hid_report_prev[i]) {
	        report_changed = 1;
	        break;
	    }
	}

	//Send Keyboard HID report over USB
	if (report_changed) {
	    // Update the Keyboard HID report
	    keyboardhid.KEYCODE1 = hid_report[0];
	    keyboardhid.KEYCODE2 = hid_report[1];
	    keyboardhid.KEYCODE3 = hid_report[2];
	    keyboardhid.KEYCODE4 = hid_report[3];
	    keyboardhid.KEYCODE5 = hid_report[4];
	    keyboardhid.KEYCODE6 = hid_report[5];

	    // Send the Keyboard HID report
	    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&keyboardhid, sizeof(keyboardhid));

	    // Update the previous report state
	    memcpy(hid_report_prev, hid_report, NUM_KEYS);

	    // Update the OLED display
	    SSD1306_GotoXY(0, 40);
	    SSD1306_Puts(last_key, &Font_11x18, 1);
	    screenNotUpdated = 1;
	}

	//Send Mouse HID report over USB
	if(smoothedAccumulator != 0){
		// Update the Mouse HID report
		mousehid.WHEEL = (int8_t)smoothedAccumulator / 35;

		// Remember the last value of smoothedAccumulator for the next loop
		lastSmoothedAccumulator = smoothedAccumulator;

		// Send the Mouse HID report
		USBD_HID_SendReport(&hUsbDeviceFS, (int8_t*)&mousehid, sizeof(mousehid));

		// Update the OLED display
		screenNotUpdated = 1;
	}

	if(screenNotUpdated == 1){
		  SSD1306_UpdateScreen();
		  screenNotUpdated = 0;
	}
  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_STATUS_Pin|KEY_ROW_1_Pin|KEY_ROW_2_Pin|KEY_ROW_3_Pin
                          |KEY_ROW_4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : KEY_COL_1_Pin KEY_COL_2_Pin KEY_COL_3_Pin KEY_COL_4_Pin */
  GPIO_InitStruct.Pin = KEY_COL_1_Pin|KEY_COL_2_Pin|KEY_COL_3_Pin|KEY_COL_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_STATUS_Pin KEY_ROW_1_Pin KEY_ROW_2_Pin KEY_ROW_3_Pin
                           KEY_ROW_4_Pin */
  GPIO_InitStruct.Pin = LED_STATUS_Pin|KEY_ROW_1_Pin|KEY_ROW_2_Pin|KEY_ROW_3_Pin
                          |KEY_ROW_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
