#ifndef OxygenPump_Config_h
#define OxygenPump_Config_h
#include "Arduino.h"


/* OXYGEN PUMP CONSTANTS */
// ON TIME SETTINGS
#define OXYGENPUMP_TIME_TURN_ON_HOUR 24 // 12
#define OXYGENPUMP_TIME_TURN_ON_MINUTE 30
#define OXYGENPUMP_TIME_TURN_ON_PERIOD 1    // PM

//OFF TIME SETTINGS
#define OXYGENPUMP_TIME_TURN_OFF_HOUR 5
#define OXYGENPUMP_TIME_TURN_OFF_MINUTE 30
#define OXYGEN_TIME_TURN_OFF_PERIOD 0 // AM

//FREQUENY SETTINGS
#define OXYGENPUMP_FREQUENCY_ON 6000  //(the amount of time to run the pump for during a cycle. In seconds)
#define OXYGENPUMP_FREQUENCY_OFF 120000 //(the amount of time to run the pump for during a cycle. In seconds)

// Necessary Constants
#define OXYGENPUMP_PIN 49 //(the pin the pump is currently connected to)
void InitializeOxygenPump()
{
    // Oxygen Pump (Relay)
    pinMode(OXYGENPUMP_PIN, OUTPUT);
    digitalWrite(OXYGENPUMP_PIN, LOW);
}


#endif