#include <stdio.h>
#include <stdlib.h>
#include <adcsampling.hpp>


float* ADC::Sampling::getADCValue(float *adc_rawinput) {
   //In real implementation this function will read the ADC values from a specific adc channel
    while (index_handler < NO_OF_SAMPLES) {
        adc_inputcollector[index_handler] = adc_rawinput[index_handler];
        index_handler++;
    }
    return &adc_inputcollector[ARRAY_INDEX];
}

float* ADC::Sampling::processADCValue(float *adc_rawinput, hw_variation::hw_variation_enum_t hw_variation) {
    //Convert values based on the HW Rev-A or Rev-B
    if (hw_variation::hw_variation_enum_t::REV_A == hw_variation) {
        printf("ADC Value read for HW Rev-A\n");
        for (uint8_t i = 0; i < NO_OF_SAMPLES; i++) {
            temp_deg[i] = adc_rawinput[i]*hw_variation::REV_A_OFFSET;
        }
    } else if (hw_variation::hw_variation_enum_t::REV_B == hw_variation) {
        printf("ADC Value read for HW Rev-B\n");
        for (uint8_t i = 0; i < NO_OF_SAMPLES; i++) {
            temp_deg[i] = (adc_rawinput[i]*hw_variation::REV_B_OFFSET);
        }
    } else {
        printf("Invalid HW Variation\n");
    }
    index_handler = REINIT_INDEX;
    return &temp_deg[ARRAY_INDEX];
}
