#ifndef Canopy_Config_h
#define Canopy_Config_h
#include "Arduino.h"

//air temperature sensor
#define ZONEB_AIR_TEMPERATURE_CRITICAL 32
#define ZONEB_AIR_TEMPERATURE_MAX 30
#define ZONEB_AIR_HUMIDITY_CRITICAL 75
#define ZONEB_AIR_HUMIDITY_MAX 70

//water temperature sensor
#define ZONEB_WATER_TEMPERATURE_CRITICAL 30
#define ZONEB_WATER_TEMPERATURE_MAX 28

//
#define ZONEB_AIR_SENSOR_TYPE DHT22                     //(the pin the water temperature sensor is currently connected to)
#define ZONEB_AIR_SENSOR_PIN 9 
#define ZONEB_WATER_TEMPERATURE_SENSOR_PIN 10

#endif