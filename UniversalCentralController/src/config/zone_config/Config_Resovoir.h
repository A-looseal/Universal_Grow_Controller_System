#ifndef Resovoir_Config_h
#define Resovoir_Config_h
#include "Arduino.h"

#define ZONEC_WATER_TEMPERATURE_SENSOR_PIN 8
#define ZONEC_WATER_TEMPERATURE_CRITICAL 30
#define ZONEC_WATER_TEMPERATURE_MAX 28
#define ZONEC_AIR_SENSOR_TYPE DHT22                     //(the pin the water temperature sensor is currently connected to)
#define ZONEC_AIR_SENSOR_PIN 7 
#define ZONEC_AIR_TEMPERATURE_CRITICAL 32
#define ZONEC_AIR_TEMPERATURE_MAX 30
#define ZONEC_AIR_HUMIDITY_CRITICAL 75
#define ZONEC_AIR_HUMIDITY_MAX 70

#endif