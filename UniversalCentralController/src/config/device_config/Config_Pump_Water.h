#ifndef WaterPump_Config_h
#define WaterPump_Config_h
#include "Arduino.h"

#define WATER_PUMP_CONNECTED

#ifdef WATER_PUMP_CONNECTED
/* WATER PUMP CONSTANTS */

// User Set Parameters
#define WATERPUMP_TIME_TURN_ON_HOUR 7
#define WATERPUMP_TIME_TURN_ON_MINUTE 1
#define WATERPUMP_TIME_TURN_OFF_HOUR 17
#define WATERPUMP_TIME_TURN_OFF_MINUTE 1
#define WATERPUMP_FREQUENCY_ON 60000  //(the amount of time to run the pump for during a cycle. In seconds)
#define WATERPUMP_FREQUENCY_OFF 60000 //(the amount of time to run the pump for during a cycle. In seconds)

// Necessary Constants
#define WATERPUMP_PIN 13 //(the pin the pump is currently connected to)
void InitializeWaterPump()
{
    // Water Pump(Relay)
    pinMode(WATERPUMP_PIN, OUTPUT);
    digitalWrite(WATERPUMP_PIN, LOW);
}
#endif

#endif