#ifndef TEMPMONITOR_H
#define TEMPMONITOR_H

// Include necessary standard libraries
#include <adcsampling.hpp>

namespace TempMonitor {
    // Define any constants
    const float OPTIMAL_TEMP = 85.0f;
    const float WARNING_TEMP = 105.0f;

    // Declare any function prototypes
     void temperature_RangeCheck(float* temperature);
}

#endif