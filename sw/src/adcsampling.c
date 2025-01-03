#include <stdio.h>
#include <stdlib.h>
#include <adcsampling.h>


void initializeADC() {
    // Code to initialize the ADC
    printf("ADC Initialized.\n");
}

float processADCValue(float *adc_rawinput, hw_variation_enum_t hw_variation) {
    float temp_deg[10];
    float current_temperature = 0;
    //Convert values based on the HW Rev-A or Rev-B
    if (REV_A == hw_variation) {
        printf("ADC Value read for HW Rev-A\n");
        for (int i = 0; i < 10; i++) {
            temp_deg[i] = adc_rawinput[i]*REV_A_OFFSET;
        }
    } else if (REV_B == hw_variation) {
        printf("ADC Value read for HW Rev-B\n");
        for (int i = 0; i < 10; i++) {
            temp_deg[i] = (adc_rawinput[i]*REV_B_OFFSET);
        }
    } else {
        printf("Invalid HW Variation\n");
    }
    // Calculate average temperature
    for (int i = 0; i < 10; i++) {
        current_temperature += temp_deg[i];
    }
    current_temperature = current_temperature / 10;
    printf("Current Temperature: %.2f\n", current_temperature);
    return current_temperature;
}
