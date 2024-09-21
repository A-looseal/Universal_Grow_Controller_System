#ifndef AirThermometer_h
#define AirThermometer_h
#include "Arduino.h"
#include <DHT.h>
#include "User_Config.h"

float zoneA_currentAirTemperature;
bool zoneA_isAirTemperatureHot = false;
bool zoneA_isAirTemperatureCritical = false;
float zoneA_currentAirHumidity;
bool zoneA_isAirHumidityHot = false;
bool zoneA_isAirHumidityCritical = false;

float zoneB_currentAirTemperature;
bool zoneB_isAirTemperatureHot = false;
bool zoneB_isAirTemperatureCritical = false;
float zoneB_currentAirHumidity;
bool zoneB_isAirHumidityHot = false;
bool zoneB_isAirHumidityCritical = false;

float zoneC_currentAirTemperature;
bool zoneC_isAirTemperatureHot = false;
bool zoneC_isAirTemperatureCritical = false;
float zoneC_currentAirHumidity;
bool zoneC_isAirHumidityHot = false;
bool zoneC_isAirHumidityCritical = false;

DHT zoneA_AirSensor(ZONEA_AIR_SENSOR_PIN, ZONEA_AIR_SENSOR_TYPE);
DHT zoneB_AirSensor(ZONEB_AIR_SENSOR_PIN, ZONEB_AIR_SENSOR_TYPE);
DHT zoneC_AirSensor(ZONEC_AIR_SENSOR_PIN, ZONEC_AIR_SENSOR_TYPE);

void InitializeAirTemperature()
{
    zoneA_AirSensor.begin();
    zoneB_AirSensor.begin();
    zoneC_AirSensor.begin();
}

void GetData_AirClimate()
{
    zoneA_currentAirTemperature = zoneA_AirSensor.readTemperature();
    zoneB_currentAirTemperature = zoneB_AirSensor.readTemperature();
    zoneC_currentAirTemperature = zoneC_AirSensor.readTemperature();

    zoneA_currentAirHumidity = zoneA_AirSensor.readHumidity();
    zoneB_currentAirHumidity = zoneB_AirSensor.readHumidity();
    zoneC_currentAirHumidity = zoneC_AirSensor.readHumidity();
}

//the name of the desired zone. \ the critical temperature value \ the max temperature value \ the container that stores the current temperature
bool CheckAir_Temperature(String _zoneName, float _critTempThreshold, float _maxTempThreshold, float _currentTempStorage, bool _critAlertFlag, bool _hotAlertFlag)
{

#ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(_zoneName);
    Serial.print(F(" CURRENT AIR TEMPERATURE: "));
#endif

    // if temperature is above critical threshold.
    if (_currentTempStorage >= _critTempThreshold)
    {
        _critAlertFlag = true;
        _hotAlertFlag = true;
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("CRITICAL: "));
        Serial.println(_currentTempStorage);
#endif
        return false;
    }

    // if temperature is above the max threshold
    else if (_currentTempStorage >= _maxTempThreshold && _currentTempStorage < _critTempThreshold)
    {
        _critAlertFlag = false;
        _hotAlertFlag = true;
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("ELEVATED: "));
        Serial.println(_currentTempStorage);
#endif
        return false;
    }

    // if temperature is below critical & max threshold
    else
    {
        _critAlertFlag = false;
        _hotAlertFlag = false;
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("NORMAL: "));
        Serial.println(_currentTempStorage);
#endif
        return true;
    }
}

//the name of the desired zone. \ the critical temperature value \ the max temperature value \ the container that stores the current temperature
bool CheckAir_Humidity(String _zoneName, float _critHumidityThreshold, float _maxHumidityThreshold, float _currentHumidityStorage, bool _critAlertFlag, bool _hotAlertFlag)
{

#ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(_zoneName);
    Serial.print(F(" CURRENT AIR HUMIDITY: "));
#endif

    // if Humidity is above critical threshold.
    if (_currentHumidityStorage >= _critHumidityThreshold)
    {
        _critAlertFlag = true;
        _hotAlertFlag = true;
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("CRITICAL: "));
        Serial.println(_currentHumidityStorage);
#endif
        return false;
    }

    // if Humidity is above the max threshold
    else if (_currentHumidityStorage >= _maxHumidityThreshold && _currentHumidityStorage < _critHumidityThreshold)
    {
        _critAlertFlag = false;
        _hotAlertFlag = true;
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("ELEVATED: "));
        Serial.println(_currentHumidityStorage);
#endif
        return false;
    }

    // if Humidity is below critical & max threshold
    else
    {
        _critAlertFlag = false;
        _hotAlertFlag = false;
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("NORMAL: "));
        Serial.println(_currentHumidityStorage);
#endif
        return true;
    }
}

#endif