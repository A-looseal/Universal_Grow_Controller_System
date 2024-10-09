#ifndef ExhaustFan_Config_h
#define ExhaustFan_Config_h
#include "Arduino.h"

/* EXHAUST FAN CONSTANTS */
// Necessary Constants
#define EXHAUSTFAN_PIN 48 //(the pin the pump is currently connected to)

void InitializeExhaustFan()
{
    // Exhaust Fan (Relay)
    pinMode(EXHAUSTFAN_PIN, OUTPUT);
    digitalWrite(EXHAUSTFAN_PIN, LOW);
}

#endif