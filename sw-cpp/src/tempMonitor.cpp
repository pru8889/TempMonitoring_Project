#include <iostream>
#include <tempMonitor.hpp>


void TempMonitor::temperature_RangeCheck(float temperature){
    if (temperature < OPTIMAL_TEMP) {
        printf("\033[0;32m"); // Set text color to green
        printf("Temperature is normal.\n");
        printf("\033[0m"); // Reset text color
    } 
    else if (temperature >= OPTIMAL_TEMP && temperature < WARNING_TEMP) {
        printf("\033[0;33m"); // Set text color to yellow
        printf("Temperature reached warning level.\n");
        printf("\033[0m"); // Reset text color
    } 
    else if (temperature >= WARNING_TEMP) {
        printf("\033[0;31m"); // Set text color to red
        printf("Temperature is at critical level.\n");
        printf("\033[0m"); // Reset text color
    }
    else {
        printf("Invalid Temperature Zone\n");
    }
}

