#ifndef __serial_H
#define __serial_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "FreeRTOS.h"

#define UART_TRANSMIT_TIMEOUT 3 // ms

void send_data(uint8_t* buf, uint8_t bufLen);

#ifdef __cplusplus
}
#endif
#endif 