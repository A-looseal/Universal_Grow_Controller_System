#ifndef SunLight_Config_h
#define SunLight_Config_h
#include "Arduino.h"

/* SUN LIGHT CONSTANTS */
// User Set Parameters
#define SUNLIGHT_TIME_TURN_ON_HOUR 7
#define SUNLIGHT_TIME_TURN_ON_MINUTE 1
#define SUNLIGHT_TIME_TURN_OFF_HOUR 23
#define SUNLIGHT_TIME_TURN_OFF_MINUTE 1

// Necessary Constants
#define SUNLIGHT_PIN 13 //(the pin the pump is currently connected to)

void InitializeSunLight()
{
    // Sun Light (Relay)
    pinMode(SUNLIGHT_PIN, OUTPUT);
    digitalWrite(SUNLIGHT_PIN, LOW);
}

#endif