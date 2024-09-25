#ifndef WindFan_Config_h
#define WindFan_Config_h
#include "Arduino.h"

/* WIND FAN CONSTANTS */
// Necessary Constants
#define WINDFAN_1_PIN 13 //(the pin the pump is currently connected to)
#define WINDFAN_2_PIN 13 //(the pin the pump is currently connected to)
#define WINDFAN_3_PIN 13 //(the pin the pump is currently connected to)
#define WINDFAN_4_PIN 13 //(the pin the pump is currently connected to)
#define WINDFAN_5_PIN 13 //(the pin the pump is currently connected to)
#define WINDFAN_6_PIN 13 //(the pin the pump is currently connected to)

byte windFansArray[] = {WINDFAN_1_PIN, WINDFAN_2_PIN, WINDFAN_3_PIN, WINDFAN_4_PIN, WINDFAN_5_PIN, WINDFAN_6_PIN};

void InitializeWindFans(byte _amountOfFans)
{
    // Wind Fan (PWM)
    for (byte i = 0; i < _amountOfFans; i++)
    {
        pinMode(windFansArray[i], OUTPUT);
        digitalWrite(windFansArray[i], LOW);
    }
}
#endif
