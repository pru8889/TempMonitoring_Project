#include <iostream>
#include <read_hwvariation.hpp>
#include <tempMonitor.hpp>

// Create an instance of ADC::Sampling
ADC::Sampling adcSamplingInstance;
float adc_value[adcSamplingInstance.NO_OF_SAMPLES] = {0.0f}; //Init array to store ADC values


hw_variation::hw_variation_enum_t hw_variation::read_hwvariation(int hw_variation) {
    hw_variation::hw_variation_enum_t hw_variation_enum;
    switch(hw_variation) {
        case 0:
            // Change ADC sampling rate to 1ms
            std::cout << "REV-A hw detected ADC normalizing rate shall be set to 1 degree" << std::endl;
            break;
        case 1:
            // Change ADC sampling rate to 2ms
            std::cout << "REV-B Hw detected ADC normalizing rate shall be set to 0.1 degree" << std::endl;
            break;
        default:
            std::cout << "Invalid HW Variation provided\n" << std::endl;
            break;
        }
    return hw_variation_enum = static_cast<hw_variation_enum_t>(hw_variation);
}


int main() {
    int hw_variation;
    float* normalized_AdcValue;

    while (1)
    {
        std::cout << "Enter HW Variation either 0 or 1: ";
        std::cin >> hw_variation;

        // Read-HW variation and change adc sampling rate based on the HW variation
        hw_variation::hw_variation_enum_t hw_variation_enum = hw_variation::read_hwvariation(hw_variation);

        std::cout << "Provide an array of 10 ADC values: "; //Emulate ADC providing 10 values
        for (uint8_t i = 0; i < adcSamplingInstance.NO_OF_SAMPLES; i++) {
            std::cout << "Enter ADC value " << static_cast<int>(i) << ": ";
            std::cin >> adc_value[i];
        }

        // Get ADC values
        float *raw_AdcValue = adcSamplingInstance.getADCValue(adc_value);

        // Process ADC values
        normalized_AdcValue = adcSamplingInstance.processADCValue(raw_AdcValue, hw_variation_enum);

        // Check temperature range
        TempMonitor::temperature_RangeCheck(&normalized_AdcValue[adcSamplingInstance.ARRAY_INDEX]);

    }
    return 0;
}
