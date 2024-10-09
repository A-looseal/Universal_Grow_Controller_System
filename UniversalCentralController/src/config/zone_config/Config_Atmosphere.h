#ifndef Atmosphere_Config_h
#define Atmosphere_Config_h
#include "Arduino.h"

/*ZONE A - The upper atmosphere of the grow tent
current setup: 1x Air sensor | 1x Co2 Sensor*/

// critical temperature determined if the measured  water temperateure is equal to or greater than this value,
#define ZONEA_WATER_TEMPERATURE_CRITICAL 30
// max temperature determined if the measured water temperateure is equal to or greater than this value,
#define ZONEA_WATER_TEMPERATURE_MAX 28

#define ZONEA_AIR_TEMPERATURE_CRITICAL 55
#define ZONEA_AIR_TEMPERATURE_MAX 40
#define ZONEA_AIR_HUMIDITY_CRITICAL 75
#define ZONEA_AIR_HUMIDITY_MAX 60

#define ZONEA_AIR_SENSOR_TYPE DHT22 // the pin the water temperature sensor is currently connected to
#define ZONEA_AIR_SENSOR_PIN 32
#define ZONEA_C02_SENSOR_PIN 33
// pin the water temperature probe is connected to
#define ZONEA_WATER_TEMPERATURE_SENSOR_PIN 31
#endif