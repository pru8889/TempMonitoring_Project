#ifndef TEMPMONITOR_H
#define TEMPMONITOR_H

#include <adcsampling.h>
class TempMonitor {
public:
    TempMonitor();
    ~TempMonitor();

    void startMonitoring();
    void stopMonitoring();
    double getCurrentTemperature() const;

private:
    bool isMonitoring;
    double currentTemperature;

    void updateTemperature();
};

#endif // TEMPMONITOR_H