/*
 * Serial communications library
 */

#include "FreeRTOS.h"
#include "usart.h"
#include "serial.h"
#include "string.h"

void send_data(uint8_t* buf, uint8_t bufLen) {
    HAL_UART_Transmit(&huart2, buf, bufLen, UART_TRANSMIT_TIMEOUT);
}