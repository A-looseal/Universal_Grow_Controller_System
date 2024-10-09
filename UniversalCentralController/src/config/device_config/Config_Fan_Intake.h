#ifndef IntakeFan_Config_h
#define IntakeFan_Config_h
#include "Arduino.h"

/* INTAKE FAN CONSTANTS */
// Necessary Constants
#define INTAKEFAN_PIN 50 //(the pin the pump is currently connected to)

void InitializeIntakeFan()
{
    // Intake Fan (Relay)
    pinMode(INTAKEFAN_PIN, OUTPUT);
    digitalWrite(INTAKEFAN_PIN, LOW);
}
#endif
