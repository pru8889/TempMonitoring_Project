#ifndef ADCSAMPLING_H
#define ADCSAMPLING_H

// Include necessary headers
#include <stdint.h>

// Define constants and macros
#define ADC_MAX_VALUE 1023
#define ADC_MIN_VALUE 0

// Declare functions
void initADC();
uint16_t readADC(uint8_t channel);

#endif // ADCSAMPLING_H