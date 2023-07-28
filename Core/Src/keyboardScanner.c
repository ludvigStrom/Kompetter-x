#include "keyboardScanner.h"
#include "main.h" // Include this if necessary for GPIO functions
#include "ImprovedKeylayouts.h"
#include <stdio.h>
#include "usbHidReport.h"

#define DEBOUNCE_DELAY 10 // Debounce delay in milliseconds

Key keycode_map[NUM_ROWS][NUM_COLS] = {
    {
        {KEY_A, NULL, 0, 0},
        {KEY_B, NULL, 0, 0},
        {KEY_C, NULL, 0, 0},
        {KEY_D, NULL, 0, 0}
    },
    {
        {KEY_E, NULL, 0, 0},
        {KEY_F, NULL, 0, 0},
        {KEY_G, NULL, 0, 0},
        {KEY_H, NULL, 0, 0}
    },
    {
        {KEY_I, NULL, 0, 0},
        {KEY_J, NULL, 0, 0},
        {KEY_K, NULL, 0, 0},
        {KEY_L, NULL, 0, 0}
    },
    {
        {KEY_M, NULL, 0, 0},
        {KEY_N, NULL, 0, MOD_LEFT_SHIFT},
        {KEY_O, (uint8_t[]){KEY_A, KEY_B}, 2, 0},
        {KEY_D, NULL, 0, MOD_LEFT_CTRL | MOD_LEFT_SHIFT}
    }
};

uint32_t last_key_time[NUM_ROWS][NUM_COLS] = {0};
uint8_t hid_report[NUM_KEYS] = {0};
uint8_t hid_report_prev[NUM_KEYS] = {0};
char last_key[3] = {0};
enum KeyState key_state[NUM_ROWS][NUM_COLS];

void keyboardScannerInit(void)
{
  // Initialize each state to IDLE
  for(int i = 0; i < NUM_ROWS; i++) {
    for(int j = 0; j < NUM_COLS; j++) {
      key_state[i][j] = IDLE;
    }
  }
}

void keyboardScan(void)
{
    for(int i = 0; i < NUM_ROWS; i++) {
        uint32_t current_tick = HAL_GetTick();
        HAL_GPIO_WritePin(row_ports[i], row_pins[i], GPIO_PIN_SET);
        HAL_Delay(1); // delay after setting row high

        for(int j = 0; j < NUM_COLS; j++) {
            uint8_t is_pressed = HAL_GPIO_ReadPin(col_ports[j], col_pins[j]) == GPIO_PIN_SET;

            if (is_pressed && key_state[i][j] == IDLE) {
                // Key has been pressed from an idle state
                if (keycode_map[i][j].macro != NULL) {
                    // Handle macro key press
                    usbHidHandleMacro(keycode_map[i][j].macro, keycode_map[i][j].macro_length);
                } else {
                    // Handle normal key press
                    usbHidAddKey(keycode_map[i][j].keycode, keycode_map[i][j].mod);  // Add the key to the HID report
                }
                key_state[i][j] = PRESSED;
                last_key_time[i][j] = current_tick;

                sprintf(last_key, "%d%d", i+1, j+1);  // Save the last key pressed

            } else if (!is_pressed && key_state[i][j] == PRESSED && current_tick - last_key_time[i][j] > DEBOUNCE_DELAY) {
                // Key has been released
                if (keycode_map[i][j].macro != NULL) {
                    // Handle macro key release
                    for(int k = 0; k < keycode_map[i][j].macro_length; k++) {
                        usbHidRemoveKey(keycode_map[i][j].macro[k], 0);
                    }
                } else {
                    // Handle normal key release
                    usbHidRemoveKey(keycode_map[i][j].keycode, keycode_map[i][j].mod); // Remove the key from the HID report
                }
                key_state[i][j] = IDLE;
            }
        }

        HAL_GPIO_WritePin(row_ports[i], row_pins[i], GPIO_PIN_RESET);
        HAL_Delay(1); // delay after setting row low
    }
}

void keyboardChangeLayout(Key new_layout[NUM_ROWS][NUM_COLS]) {
    memcpy(keycode_map, new_layout, sizeof(keycode_map));
}
