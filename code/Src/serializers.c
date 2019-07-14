/*
 *  Serializers to convert data into UART bytes
 */

#include "serializers.h"
#include "string.h"
#include "crc.h"

void serializeNavPad(uint8_t * buf, uint8_t nav_btn, uint8_t nav_enc) {
    buf[0] = '{';
    buf[1] = MODULE_CODE;
    buf[2] = ',';
    buf[3] = TEMP_CODE;
    buf[4] = ',';
    buf[5] = nav_btn;
    buf[6] = ',';
    buf[7] = nav_enc;
    buf[8] = ',';
    *((uint32_t *)(&(buf[9]))) = HAL_CRC_Calculate(&hcrc, &(buf[1]), 7); // CRC of buf[1] to buf[7]
    buf[13] = '}';
    buf[14] = '\n';
}

void serializeEncoder(uint8_t * buf, uint8_t pos) {
    buf[0] = '{';
    buf[1] = MODULE_CODE;
    buf[2] = ',';
    buf[3] = TEMP_CODE;
    buf[4] = ',';
    buf[5] = pos;
    buf[6] = ',';
    *((uint32_t *)(&(buf[7])))  = HAL_CRC_Calculate(&hcrc, &(buf[1]), 5); // CRC of buf[1] to buf[5]
    buf[11] = '}';
    buf[12] = '\n';
}

void serializeRHTemp(uint8_t * buf, uint16_t temp, uint16_t rh) {
    buf[0] = '{';
    buf[1] = MODULE_CODE;
    buf[2] = ',';
    buf[3] = TEMP_CODE;
    buf[4] = ',';
    *((uint16_t *)(&(buf[5])))  = temp;
    buf[7] = ',';
    *((uint16_t *)(&(buf[8])))  = rh;
    buf[10] = ',';
    *((uint32_t *)(&(buf[11])))  = HAL_CRC_Calculate(&hcrc, &(buf[1]), 9); // CRC of buf[1] to buf[9]
    buf[15] = '}';
    buf[16] = '\n';
}
