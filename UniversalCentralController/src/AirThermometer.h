#ifndef AirThermometer_h
#define AirThermometer_h
#include "Arduino.h"
#include "DHT.h"
#include "config/zone_config/Config_Atmosphere.h"
#include "config/zone_config/Config_Canopy.h"
#include "config/zone_config/Config_Resovoir.h"
#include "config/User_Config.h"

#define ENABLE_SERIAL_OUTPUT
// #define TEST_AIR_HUMIDITY 50
// #define TEST_AIR_TEMPERATURE 50

float zoneA_currentAirTemperature;
bool zoneA_isAirTemperatureHot;
bool zoneA_isAirTemperatureCritical;
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

// the name of the desired zone. \ the critical temperature value \ the max temperature value \ the container that stores the current temperature
bool CheckAir_Temperature(String _zoneName, float _critTempThreshold, float _maxTempThreshold, float _currentTempStorage, bool &_critAlertFlag, bool &_hotAlertFlag)
{
#ifdef TEST_AIR_TEMPERATURE
    _currentTempStorage = _currentTempStorage + TEST_AIR_TEMPERATURE;
#endif

#ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(_zoneName);
    Serial.print(F(" Current air tempperature: "));
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

// the name of the desired zone. \ the critical temperature value \ the max temperature value \ the container that stores the current temperature
bool CheckAir_Humidity(String _zoneName, float _critHumidityThreshold, float _maxHumidityThreshold, float _currentHumidityStorage, bool &_critAlertFlag, bool &_hotAlertFlag)
{
#ifdef TEST_AIR_HUMIDITY
    _currentHumidityStorage = _currentHumidityStorage + TEST_AIR_HUMIDITY;
#endif

#ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(_zoneName);
    Serial.print(F(" Current air humidity: "));
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

void ReadAllAirTemperature()
{
    CheckAir_Temperature("ZONE A", ZONEA_AIR_TEMPERATURE_CRITICAL, ZONEA_AIR_TEMPERATURE_MAX, zoneA_currentAirTemperature, zoneA_isAirTemperatureCritical, zoneA_isAirTemperatureHot);
    CheckAir_Temperature("ZONE B", ZONEB_AIR_TEMPERATURE_CRITICAL, ZONEB_AIR_TEMPERATURE_MAX, zoneB_currentAirTemperature, zoneB_isAirTemperatureCritical, zoneB_isAirTemperatureHot);
    CheckAir_Temperature("ZONE C", ZONEC_AIR_TEMPERATURE_CRITICAL, ZONEC_AIR_TEMPERATURE_MAX, zoneC_currentAirTemperature, zoneC_isAirTemperatureCritical, zoneC_isAirTemperatureHot);
}

void ReadAllAirHumidity()
{
    CheckAir_Humidity("ZONE A", ZONEA_AIR_HUMIDITY_CRITICAL, ZONEA_AIR_HUMIDITY_MAX, zoneA_currentAirHumidity, zoneA_isAirHumidityCritical, zoneA_isAirHumidityHot);
    CheckAir_Humidity("ZONE B", ZONEB_AIR_HUMIDITY_CRITICAL, ZONEB_AIR_HUMIDITY_MAX, zoneB_currentAirHumidity, zoneB_isAirHumidityCritical, zoneB_isAirHumidityHot);
    CheckAir_Humidity("ZONE C", ZONEC_AIR_HUMIDITY_CRITICAL, ZONEC_AIR_HUMIDITY_MAX, zoneC_currentAirHumidity, zoneC_isAirHumidityCritical, zoneC_isAirHumidityHot);
}

#endif