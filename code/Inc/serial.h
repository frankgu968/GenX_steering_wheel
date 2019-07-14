#ifndef __serial_H
#define __serial_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "FreeRTOS.h"

#define UART_TRANSMIT_TIMEOUT 3 // ms

void send_data(uint8_t* bytes, uint8_t len);

#ifdef __cplusplus
}
#endif
#endif 