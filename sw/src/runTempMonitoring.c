#include <stdio.h>
#include <read_hwvariation.h>
#include <stdlib.h>
#include <tempMonitor.h>

float adc_value[NO_OF_SAMPLES] = {0.0f}; //Init array to store ADC values

hw_variation_enum_t read_hwvariation(int hw_variation) {
    hw_variation_enum_t hw_variation_enum;
    //ToDO replace switch logic with simpler if else
    switch(hw_variation) {
        case 0:
            // Change ADC sampling rate to 1ms
            printf("REV-A hw detected ADC sampling rate set to 1 degree\n");
            break;
        case 1:
            // Change ADC sampling rate to 2ms
            printf("REV-B Hw detected ADC sampling rate set to 0.1 degree\n");
            break;
        default:
            printf("Invalid HW Variation\n");
            break;
    }
    return hw_variation_enum = hw_variation;    
}

int main() {
    int hw_variation;
    float* normalized_AdcValue;
    while (1){
        printf("Enter HW Variation either 0 or 1: ");
        scanf("%d", &hw_variation);

        // Read-HW variation and change adc sampling rate based on the HW variation
        read_hwvariation(hw_variation);
        
        printf("Provide an array of 10 ADC values: "); //Emulate ADC providing 10 values
        for (uint8_t i = 0; i < NO_OF_SAMPLES; i++) {
            printf("Enter ADC value %d: ", i);
            scanf("%f", &adc_value[i]);
        }
        
        // Get ADC values
        float *raw_AdcValue = getADCValue(&adc_value[ARRAY_INDEX]);

        // Process ADC values
        normalized_AdcValue = processADCValue(&raw_AdcValue[ARRAY_INDEX], hw_variation);
        
        // Check temperature range
        temperature_RangeCheck(&normalized_AdcValue[ARRAY_INDEX]);
    }
    return 0;
}



