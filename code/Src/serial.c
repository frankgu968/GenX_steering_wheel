/*
 * Serial communications library
 */

#include "FreeRTOS.h"
#include "usart.h"
#include "serial.h"

void send_data(uint8_t* buffer, uint8_t len) {
    HAL_UART_Transmit(&huart2, buffer, sizeof(len), UART_TRANSMIT_TIMEOUT);
}