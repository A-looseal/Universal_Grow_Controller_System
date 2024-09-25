#ifndef WaterThermometer_h
#define WaterThermometer_h
#include "Arduino.h"
#include "OneWire.h"
#include "DallasTemperature.h"
#include "config/zone_config/Config_Atmosphere.h"
#include "config/zone_config/Config_Canopy.h"
#include "config/zone_config/Config_Resovoir.h"
#include "config/User_Config.h"

#define ENABLE_SERIAL_OUTPUT
//#define TEST_WATER_TEMPERATURE 50


float zoneA_currentWaterTemperature;
bool zoneA_isWaterTemperatureHot = false;
bool zoneA_isWaterTemperatureCritical = false;

float zoneB_currentWaterTemperature;
bool zoneB_isWaterTemperatureHot = false;
bool zoneB_isWaterTemperatureCritical = false;

float zoneC_currentWaterTemperature;
bool zoneC_isWaterTemperatureHot = false;
bool zoneC_isWaterTemperatureCritical = false;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire zoneA_OneWire(ZONEA_WATER_TEMPERATURE_SENSOR_PIN);
OneWire zoneB_OneWire(ZONEB_WATER_TEMPERATURE_SENSOR_PIN);
OneWire zoneC_OneWire(ZONEC_WATER_TEMPERATURE_SENSOR_PIN);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature zoneA_WaterSensor(&zoneA_OneWire);
DallasTemperature zoneB_WaterSensor(&zoneB_OneWire);
DallasTemperature zoneC_WaterSensor(&zoneC_OneWire);

void InitializeWaterTemperature()
{
    zoneA_WaterSensor.begin();
    zoneB_WaterSensor.begin();
    zoneC_WaterSensor.begin();
}

void GetData_WaterClimate()
{
    zoneA_WaterSensor.requestTemperatures();
    zoneB_WaterSensor.requestTemperatures();
    zoneC_WaterSensor.requestTemperatures();

    zoneA_currentWaterTemperature = zoneA_WaterSensor.getTempCByIndex(0);
    zoneB_currentWaterTemperature = zoneB_WaterSensor.getTempCByIndex(0);
    zoneC_currentWaterTemperature = zoneC_WaterSensor.getTempCByIndex(0);
}

bool CheckWater_Temperature(String _zoneName, float _criticalTemperatureThreshold, float _maximumTemperatureThreshold, float _currentTemperatureValue, bool &_criticalAlertFlag, bool &_hotAlertFlag)
{
#ifdef TEST_WATER_TEMPERATURE
    _currentHumidityStorage = _currentHumidityStorage + TEST_AIR_HUMIDITY;
#endif

#ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(_zoneName);
    Serial.print(F(" Current water temperature: "));
#endif

    if (_currentTemperatureValue != DEVICE_DISCONNECTED_C)
    {
        // if temperature is above critical threshold.
        if (_currentTemperatureValue >= _criticalTemperatureThreshold)
        {
            _criticalAlertFlag = true;
            _hotAlertFlag = true;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.print(F("CRITICAL: "));
            Serial.println(_currentTemperatureValue);
#endif
            return false;
        }

        // if temperature is above the max threshold
        else if (_currentTemperatureValue >= _maximumTemperatureThreshold && _currentTemperatureValue < _criticalTemperatureThreshold)
        {
            _criticalAlertFlag = false;
            _hotAlertFlag = true;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.print(F("ELEVATED: "));
            Serial.println(_currentTemperatureValue);
#endif
            return false;
        }

        // if temperature is below critical & max threshold
        else
        {
            _criticalAlertFlag = false;
            _hotAlertFlag = false;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.print(F("NORMAL: "));
            Serial.println(_currentTemperatureValue);
#endif
            return true;
        }
    }
    else
    {
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.println("nan");
#endif
    }
}

void ReadAllWaterTemperature()
{
    CheckWater_Temperature("ZONE A", ZONEA_WATER_TEMPERATURE_CRITICAL, ZONEA_WATER_TEMPERATURE_MAX, zoneA_currentWaterTemperature, zoneA_isWaterTemperatureCritical, zoneA_isWaterTemperatureHot);
    CheckWater_Temperature("ZONE B", ZONEB_WATER_TEMPERATURE_CRITICAL, ZONEB_WATER_TEMPERATURE_MAX, zoneB_currentWaterTemperature, zoneB_isWaterTemperatureCritical, zoneB_isWaterTemperatureHot);
    CheckWater_Temperature("ZONE C", ZONEC_WATER_TEMPERATURE_CRITICAL, ZONEC_WATER_TEMPERATURE_MAX, zoneC_currentWaterTemperature, zoneC_isWaterTemperatureCritical, zoneC_isWaterTemperatureHot);
}
#endif