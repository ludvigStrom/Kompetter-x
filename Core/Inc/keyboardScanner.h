#ifndef KEYBOARD_SCANNER_H
#define KEYBOARD_SCANNER_H

#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "ImprovedKeylayouts.h"

#define NUM_ROWS 4
#define NUM_COLS 4
#define NUM_KEYS 16

enum KeyState { IDLE, PRESSED };


typedef struct {
    uint8_t keycode;
    uint8_t* macro;
    uint8_t macro_length;
    uint16_t mod;
} Key;

void keyboardScannerInit(void);
void keyboardScan(void);
void keyboardChangeLayout(Key new_layout[NUM_ROWS][NUM_COLS]);

extern uint32_t last_key_time[NUM_ROWS][NUM_COLS];
extern uint8_t hid_report[NUM_KEYS];
extern uint8_t hid_report_prev[NUM_KEYS];
extern char last_key[3];
extern enum KeyState key_state[NUM_ROWS][NUM_COLS];

extern GPIO_TypeDef* row_ports[NUM_ROWS];
extern uint16_t row_pins[NUM_ROWS];
extern GPIO_TypeDef* col_ports[NUM_COLS];
extern uint16_t col_pins[NUM_COLS];

#endif
