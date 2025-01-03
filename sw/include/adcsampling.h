#ifndef ADCSAMPLING_H
#define ADCSAMPLING_H

// Include necessary headers
#include <stdint.h>
#include <read_hwvariation.h>

// Declare function prototypes
float processADCValue(float *adc_rawinput, hw_variation_enum_t hw_variation);

#endif // ADCSAMPLING_H