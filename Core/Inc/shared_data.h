#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <stdint.h>

#define DATA_BUFFER_SIZE 64

extern uint8_t SharedDataBuffer[DATA_BUFFER_SIZE];
volatile extern uint8_t DataReceivedFlag;

#endif // SHARED_DATA_H
