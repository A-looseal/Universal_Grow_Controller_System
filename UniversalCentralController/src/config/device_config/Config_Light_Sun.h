#ifndef SunLight_Config_h
#define SunLight_Config_h
#include "Arduino.h"

/* SUN LIGHT CONSTANTS */
// User Set Parameters
#define SUNLIGHT_TIME_TURN_ON_HOUR 22   // 10
#define SUNLIGHT_TIME_TURN_ON_MINUTE 30
#define SUNLIGHT_TIME_TURN_ON_PERIOD 1  // PM
#define SUNLIGHT_TIME_TURN_OFF_HOUR 6
#define SUNLIGHT_TIME_TURN_OFF_MINUTE 30
#define SUNLIGHT_TIME_TURN_OFF_PERIOD 0 // AM

// Necessary Constants
#define SUNLIGHT_PIN 52  //(the pin the pump is currently connected to)

void InitializeSunLight()
{
    // Sun Light (Relay)
    pinMode(SUNLIGHT_PIN, OUTPUT);
    digitalWrite(SUNLIGHT_PIN, LOW);
}

#endif