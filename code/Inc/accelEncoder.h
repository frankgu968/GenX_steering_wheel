#ifndef __accelEncoder_H
#define __accelEncoder_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "FreeRTOS.h"

const uint8_t aceMap[] = {0x7F,0x3F,0x3A};

uint8_t readAccelEncoder();

#ifdef __cplusplus
}
#endif
#endif 