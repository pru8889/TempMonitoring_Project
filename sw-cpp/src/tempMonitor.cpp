#include <iostream>
#include <tempMonitor.hpp>


void TempMonitor::temperature_RangeCheck(float* temperature){
    float current_temperature = 0.0f;
    
    for (uint8_t i = 0; i < ADC::Sampling::NO_OF_SAMPLES; i++) {
        current_temperature += temperature[i];
    }
    current_temperature = current_temperature / ADC::Sampling::NO_OF_SAMPLES;
    std::cout << "Current Temperature: " << current_temperature << "\n";
    if (current_temperature < OPTIMAL_TEMP) {
        printf("\033[0;32m"); // Set text color to green
        printf("Temperature is normal.\n");
        printf("\033[0m"); // Reset text color
    } 
    else if (current_temperature >= OPTIMAL_TEMP && current_temperature < WARNING_TEMP) {
        printf("\033[0;33m"); // Set text color to yellow
        printf("Temperature reached warning level.\n");
        printf("\033[0m"); // Reset text color
    } 
    else if (current_temperature >= WARNING_TEMP) {
        printf("\033[0;31m"); // Set text color to red
        printf("Temperature is at critical level.\n");
        printf("\033[0m"); // Reset text color
    }
    else {
        printf("Invalid Temperature Zone\n");
    }
}

