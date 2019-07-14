#ifndef __serializers_H
#define __serializers_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "FreeRTOS.h"
#include "string.h"
#include "stdbool.h"

#define MODULE_CODE  0xa5  // Module ID

#define TEMP_CODE    0x01
#define ENCODER_CODE 0x02
#define BUTTOM_CODE  0x03

// All lengths are the actual char len +1 for string null terminator
#define MSG_LEN_TEMP 17  
#define MSG_LEN_ENC  13
#define MSG_LEN_NAV  15

void serializeNavPad(uint8_t * buf, uint8_t nav_btn, uint8_t nav_enc);
void serializeEncoder(uint8_t * buf, uint8_t pos);
void serializeRHTemp(uint8_t * buf, uint16_t temp, uint16_t rh);

#ifdef __cplusplus
}
#endif
#endif 