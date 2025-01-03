#include <iostream>
#include <read_hwvariation.hpp>
#include <tempMonitor.hpp>

float adc_value[10] = {10,11,12,13,14,15,16,17,18,19};


hw_variation::hw_variation_enum_t hw_variation::read_hwvariation(int hw_variation) {
    std::cout << "HW Variation: " << hw_variation << std::endl;
    hw_variation::hw_variation_enum_t hw_variation_enum;
    //ToDO replace switch logic with simpler if else
    switch(hw_variation) {
        case 0:
            // Change ADC sampling rate to 1ms
            std::cout << "REV-A hw detected ADC sampling rate set to 1 degree" << std::endl;
            break;
        case 1:
            // Change ADC sampling rate to 2ms
            printf("REV-B Hw detected ADC sampling rate set to 0.1 degree\n");
            break;
        default:
            printf("Invalid HW Variation\n");
            break;
        }
    return hw_variation_enum = static_cast<hw_variation_enum_t>(hw_variation);
}


int main() {
    int hw_variation;
    float average_temperature;
    hw_variation::hw_variation_enum_t hw_variation_enum;
    printf("Enter HW Variation: ");
    scanf("%d", &hw_variation);
   // Read-HW variation and change adc sampling rate based on the HW variation
    hw_variation_enum = hw_variation::read_hwvariation(hw_variation);
    ADC::Sampling adcSamplingInstance;
    float *index = adcSamplingInstance.getADCValue(&adc_value[0]);
    average_temperature=adcSamplingInstance.processADCValue(&index[0], hw_variation_enum);
    TempMonitor::temperature_RangeCheck(average_temperature);
    return 0;
}



