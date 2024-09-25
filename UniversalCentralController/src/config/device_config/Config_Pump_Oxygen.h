#ifndef OxygenPump_Config_h
#define OxygenPump_Config_h
#include "Arduino.h"


/* OXYGEN PUMP CONSTANTS */
// User Set Parameters
#define OXYGENPUMP_TIME_TURN_ON_HOUR 19
#define OXYGENPUMP_TIME_TURN_ON_MINUTE 27
#define OXYGENPUMP_TIME_TURN_OFF_HOUR 23
#define OXYGENPUMP_TIME_TURN_OFF_MINUTE 0
#define OXYGENPUMP_FREQUENCY_ON 1000  //(the amount of time to run the pump for during a cycle. In seconds)
#define OXYGENPUMP_FREQUENCY_OFF 1000 //(the amount of time to run the pump for during a cycle. In seconds)

// Necessary Constants
#define OXYGENPUMP_PIN 13 //(the pin the pump is currently connected to)
void InitializeOxygenPump()
{
    // Oxygen Pump (Relay)
    pinMode(OXYGENPUMP_PIN, OUTPUT);
    digitalWrite(OXYGENPUMP_PIN, LOW);
}


#endif