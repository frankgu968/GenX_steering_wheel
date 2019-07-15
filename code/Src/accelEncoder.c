#include "accelEncoder.h"
#include "gpio.h"

const uint8_t aceMap[] = {0x7F,0x3F,0x3A};

uint8_t readAccelEncoder(){
    uint8_t pinVals = 0x0;
    // Assemble pinVals byte using HAL pin-wise read
    // This design choice ensures HAL and LL are not mixed
    pinVals |= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8) << 7;
    pinVals |= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9) << 6;
    pinVals |= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_10) << 5;
    pinVals |= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11) << 4;
    pinVals |= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12) << 3;
    pinVals |= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) << 2;
    pinVals |= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14) << 1;
    pinVals |= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);

    
//    return aceMap[pinVals];
    return pinVals;
}
