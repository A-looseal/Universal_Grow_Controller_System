#ifndef Device_Config_h
#define Device_Config_h
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


/* INTAKE FAN CONSTANTS */
// User Set Parameters
#define INTAKEFAN_TIME_TURN_ON_HOUR 19
#define INTAKEFAN_TIME_TURN_ON_MINUTE 27
#define INTAKEFAN_TIME_TURN_OFF_HOUR 23
#define INTAKEFAN_TIME_TURN_OFF_MINUTE 0
#define INTAKEFAN_FREQUENCY_ON 1000  //(the amount of time to run the pump for during a cycle. In seconds)
#define INTAKEFAN_FREQUENCY_OFF 1000 //(the amount of time to run the pump for during a cycle. In seconds)

// Necessary Constants
#define INTAKEFAN_PIN 13 //(the pin the pump is currently connected to)


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


/* SUN LIGHT CONSTANTS */

// User Set Parameters
#define SUNLIGHT_TIME_TURN_ON_HOUR 7
#define SUNLIGHT_TIME_TURN_ON_MINUTE 1
#define SUNLIGHT_TIME_TURN_OFF_HOUR 18
#define SUNLIGHT_TIME_TURN_OFF_MINUTE 1
#define SUNLIGHT_FREQUENCY_ON 1000  //(the amount of time to run the pump for during a cycle. In seconds)
#define SUNLIGHT_FREQUENCY_OFF 1000 //(the amount of time to run the pump for during a cycle. In seconds)

// Necessary Constants
#define SUNLIGHT_PIN 13 //(the pin the pump is currently connected to)


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

/* WIND FAN CONSTANTS */

// User Set Parameters
#define WINDFAN_TIME_TURN_ON_HOUR 19
#define WINDFAN_TIME_TURN_ON_MINUTE 27
#define WINDFAN_TIME_TURN_OFF_HOUR 23
#define WINDFAN_TIME_TURN_OFF_MINUTE 0
#define WINDFAN_FREQUENCY_ON 1000  //(the amount of time to run the pump for during a cycle. In seconds)
#define WINDFAN_FREQUENCY_OFF 1000 //(the amount of time to run the pump for during a cycle. In seconds)

// Necessary Constants
#define WINDFAN_1_PIN 13 //(the pin the pump is currently connected to)
#define WINDFAN_2_PIN 13 //(the pin the pump is currently connected to)
#define WINDFAN_3_PIN 13 //(the pin the pump is currently connected to)
#define WINDFAN_4_PIN 13 //(the pin the pump is currently connected to)
#define WINDFAN_5_PIN 13 //(the pin the pump is currently connected to)
#define WINDFAN_6_PIN 13 //(the pin the pump is currently connected to)

#endif