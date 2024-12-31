#include <stdio.h>
#include <stdlib.h>
#include <adcsampling.h>

// int main() {
//     // Initialize the ADC
//     initializeADC();

//     // Read ADC value
//     int adcValue = readADCValue();

//     // Process the ADC value
//     processADCValue(adcValue);

//     return 0;
// }

void initializeADC() {
    // Code to initialize the ADC
    printf("ADC Initialized.\n");
}

float processADCValue(uint8_t *adc_rawinput, hw_variation_enum_t hw_variation) {
    float temp_deg[10];
    float sum = 0;
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
    // Code to process the ADC value
    for (int i = 0; i < 10; i++) {
        sum += temp_deg[i];
    }
    float average = sum / 10;
    return average;
}
