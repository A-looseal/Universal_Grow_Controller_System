#ifndef WaterThermometer_h
#define WaterThermometer_h
#include "Arduino.h"
#include "OneWire.h"
#include "DallasTemperature.h"
#include "User_Config.h"

#define ENABLE_SERIAL_OUTPUT

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

void UpdateWaterTemperature()
{
    zoneA_WaterSensor.requestTemperatures();
    zoneB_WaterSensor.requestTemperatures();
    zoneC_WaterSensor.requestTemperatures();

    zoneA_currentWaterTemperature = zoneA_WaterSensor.getTempCByIndex(0);
    zoneB_currentWaterTemperature = zoneB_WaterSensor.getTempCByIndex(0);
    zoneC_currentWaterTemperature = zoneC_WaterSensor.getTempCByIndex(0);
}

bool Check_Water_Temperature(String _zoneName, float _critTemp, float _maxTemp, float _currentTemp, bool _critFlag, bool _hotFlag, DallasTemperature _sensor)
{

    _sensor.requestTemperatures();
    _currentTemp = _sensor.getTempCByIndex(0);

#ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(_zoneName);
    Serial.print(F(" CURRENT WATER TEMPERATURE: "));
#endif

    if (_currentTemp != DEVICE_DISCONNECTED_C)
    {
        // if temperature is above critical threshold.
        if (_currentTemp >= _critTemp)
        {
            _critFlag = true;
            _hotFlag = true;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.print(F("CRITICAL: "));
            Serial.println(_currentTemp);
#endif
            return false;
        }

        // if temperature is above the max threshold
        else if (_currentTemp >= _maxTemp && _currentTemp < _critTemp)
        {
            _critFlag = false;
            _hotFlag = true;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.print(F("ELEVATED: "));
            Serial.println(_currentTemp);
#endif
            return false;
        }

        // if temperature is below critical & max threshold
        else
        {
            _critFlag = false;
            _hotFlag = false;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.print(F("NORMAL: "));
            Serial.println(_currentTemp);
#endif
            return true;
        }
    }
    else
    {
        Serial.println("Error: Could not read temperature data");
    }
}

#endif