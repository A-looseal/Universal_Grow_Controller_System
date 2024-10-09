#ifndef WaterPump_Config_h
#define WaterPump_Config_h
#include "Arduino.h"

#define WATER_PUMP_CONNECTED

#ifdef WATER_PUMP_CONNECTED
/* WATER PUMP CONSTANTS */

// ON TIME SETTINGS
#define WATERPUMP_TIME_TURN_ON_HOUR 21
#define WATERPUMP_TIME_TURN_ON_MINUTE 30
#define WATERPUMP_TIME_TURN_ON_PERIOD 1    // PM

// OFF TIME SETTINGS
#define WATERPUMP_TIME_TURN_OFF_HOUR 11
#define WATERPUMP_TIME_TURN_OFF_MINUTE 30
#define WATERPUMP_TIME_TURN_OFF_PERIOD 0   // AM

// FREQUENCY SETTINGS
#define WATERPUMP_FREQUENCY_ON 60000  //(the amount of time to run the pump for during a cycle. In seconds)
#define WATERPUMP_FREQUENCY_OFF 60000 //(the amount of time to run the pump for during a cycle. In seconds)

// Necessary Constants
#define WATERPUMP_PIN 47 //(the pin the pump is currently connected to)

void InitializeWaterPump()
{
    // Water Pump(Relay)
    pinMode(WATERPUMP_PIN, OUTPUT);
    digitalWrite(WATERPUMP_PIN, LOW);
}
#endif

#endif