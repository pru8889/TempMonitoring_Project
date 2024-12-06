#ifndef ADCSAMPLING_H
#define ADCSAMPLING_H

// Include necessary headers
#include <iostream>
#include "read_hwvariation.hpp" // Include the header file where hw_variation_enum_t is defined


namespace ADC {
class Sampling {
public:
    static const uint8_t NO_OF_SAMPLES = 10U;
    static const uint8_t REINIT_INDEX = 0U;
    static const uint8_t ARRAY_INDEX = 0U;
    float temp_deg[10] = {0.0f};
    // Function to process ADC value based on hardware variation
    float* processADCValue(float *adc_rawinput, hw_variation::hw_variation_enum_t hw_variation);
    // Function to get ADC value
    float* getADCValue(float *adc_rawinput);
private:
    uint8_t index_handler = 0U; //Index to handle array of ADC values
    float adc_inputcollector[NO_OF_SAMPLES]={0.0f};
   };
}


#endif // ADCSAMPLING_H