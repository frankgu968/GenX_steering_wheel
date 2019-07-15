#include "accelEncoder.h"
#include "gpio.h"

uint8_t readAccelEncoder(){
    uint8_t pinVals;
    // Assemble pinVals byte using HAL pin-wise read
    // This design choice ensures HAL and LL are not mixed
    for(uint8_t i = 7; i < 15; i++) {
        pinVals |= HAL_GPIO_ReadPin(GPIOC, i) << (i - 7);
    }
    
    return ACEMap[pinVals];
}
