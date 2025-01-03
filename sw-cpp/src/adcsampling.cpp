#include <stdio.h>
#include <stdlib.h>
#include <adcsampling.hpp>


float* ADC::Sampling::getADCValue(float *adc_rawinput) {
    //In real implementation this function will read the ADC values from a specific adc channel
    while (g_index < NO_OF_SAMPLES) {
        g_adc_inputcollector[g_index] = adc_rawinput[g_index];
        g_index++;
    }
    return &g_adc_inputcollector[0];
}

float ADC::Sampling::processADCValue(float *adc_rawinput, hw_variation::hw_variation_enum_t hw_variation) {
    float temp_deg[10];
    float current_temperature = 0;
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
    g_index = REINIT_INDEX;
    // Calculate average temperature
    for (uint8_t i = 0; i < NO_OF_SAMPLES; i++) {
        current_temperature += temp_deg[i];
    }
    current_temperature = current_temperature / NO_OF_SAMPLES;
    printf("Current Temperature: %.2f\n", current_temperature);
    return current_temperature;
}
