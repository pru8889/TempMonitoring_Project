#include <stdio.h>
#include <stdlib.h>
#include <adcsampling.h>

uint8_t g_index = 0U; // Index to handle array of ADC values
float g_adc_inputcollector[NO_OF_SAMPLES]={0.0f};
float temp_deg[NO_OF_SAMPLES]={0.0f};
float* getADCValue(float *adc_rawinput) {
    //In real implementation this function will read the ADC values from a specific adc channel
    while (g_index < NO_OF_SAMPLES) {
        g_adc_inputcollector[g_index] = adc_rawinput[g_index];
        g_index++;
    }
    return &g_adc_inputcollector[ARRAY_INDEX];
}

float* processADCValue(float *adc_rawinput, hw_variation_enum_t hw_variation) {
    //Convert values based on the HW Rev-A or Rev-B
    if (REV_A == hw_variation) {
        printf("ADC Value read for HW Rev-A\n");
        for (uint8_t i = 0; i < NO_OF_SAMPLES; i++) {
            temp_deg[i] = adc_rawinput[i]*REV_A_OFFSET;
        }
    } else if (REV_B == hw_variation) {
        printf("ADC Value read for HW Rev-B\n");
        for (uint8_t i = 0; i < NO_OF_SAMPLES; i++) {
            temp_deg[i] = (adc_rawinput[i]*REV_B_OFFSET);
        }
    } else {
        printf("Invalid HW Variation\n");
    }
    g_index = REINIT_INDEX;
    return &temp_deg[ARRAY_INDEX];
}
