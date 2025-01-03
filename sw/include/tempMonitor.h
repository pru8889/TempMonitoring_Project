#ifndef TEMPMONITOR_H
#define TEMPMONITOR_H

// Include standard libraries
#include <stdio.h>
#include <stdlib.h>

#include <adcsampling.h>

// Define constants
#define MAX_TEMP_SENSORS 10
#define OPTIMAL_TEMP 85
#define WARNING_TEMP 105

// Declare function prototypes
void temperature_RangeCheck(float temperature);


#ifdef __cplusplus
}
#endif

#endif // TEMPMONITOR_H