#include <stdio.h>
#include <read_hwvariation.h>
#include <adcsampling.h>
#include <stdlib.h>
#include <tempMonitor.h>

float adc_value[10] = {10,11,12,13,14,15,16,17,18,19};
hw_variation_enum_t read_hwvariation(int hw_variation) {
    printf("HW Variation: %d\n", hw_variation);
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
    float average_temperature;
    printf("Enter HW Variation: ");
    scanf("%d", &hw_variation);
   // Read-HW variation and change adc sampling rate based on the HW variation
    read_hwvariation(hw_variation);
    average_temperature=processADCValue(&adc_value[0], hw_variation);
    temperature_RangeCheck(average_temperature);
    return 0;
}



