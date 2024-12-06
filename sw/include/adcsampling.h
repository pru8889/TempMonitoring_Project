#ifndef ADCSAMPLING_H
#define ADCSAMPLING_H

// Include necessary headers
#include <stdint.h>
#include <read_hwvariation.h>

#define NO_OF_SAMPLES 10U
#define REINIT_INDEX 0U
#define ARRAY_INDEX 0U

// Declare function prototypes
float* processADCValue(float *adc_rawinput, hw_variation_enum_t hw_variation);
float* getADCValue(float *adc_rawinput);

#endif // ADCSAMPLING_H