#ifndef ExhaustFan_Config_h
#define ExhaustFan_Config_h
#include "Arduino.h"

/* EXHAUST FAN CONSTANTS */
// User Set Parameters
#define EXHAUSTFAN_TIME_TURN_ON_HOUR 19
#define EXHAUSTFAN_TIME_TURN_ON_MINUTE 27
#define EXHAUSTFAN_TIME_TURN_OFF_HOUR 23
#define EXHAUSTFAN_TIME_TURN_OFF_MINUTE 0
#define EXHAUSTFAN_FREQUENCY_ON 1000  //(the amount of time to run the pump for during a cycle. In seconds)
#define EXHAUSTFAN_FREQUENCY_OFF 1000 //(the amount of time to run the pump for during a cycle. In seconds)

// Necessary Constants
#define EXHAUSTFAN_PIN 13 //(the pin the pump is currently connected to)

void InitializeExhaustFan()
{
    // Exhaust Fan (Relay)
    pinMode(EXHAUSTFAN_PIN, OUTPUT);
    digitalWrite(EXHAUSTFAN_PIN, LOW);
}

#endif