#include "src/ClockController.h"
#include "src/WaterThermometer.h"
#include "src/AirThermometer.h"
#include "src/DeviceController.h"
#include "src/LogicController.h"
#include "src/config/User_Config.h"

//#define ENABLE_SERIAL_OUTPUT

void setup()
{
    Serial.begin(115200);

    InitializeClock();
    InitializeAllDevices();
}

void loop()
{
#ifdef ENABLE_SERIAL_OUTPUT
    Serial.println('\n');
    Serial.println(F("#########################"));
#endif
    UpdateClock();

#ifdef ENABLE_SERIAL_OUTPUT
    Serial.print("current hour: ");
    Serial.println(currentHour);
    Serial.print("current minute: ");
    Serial.println(currentMinute);
    Serial.println(F("#########################"));
#endif

    GetData_AirClimate();   // read raw data from all air climate sensors
    GetData_WaterClimate(); // read raw data from all water climate sensors
    
    CheckAir_Temperature("ZONE A", ZONEA_AIR_TEMPERATURE_CRITICAL, ZONEA_AIR_TEMPERATURE_MAX, zoneA_currentAirTemperature, zoneA_isAirTemperatureCritical, zoneA_isAirTemperatureHot);
    CheckAir_Humidity("ZONE A", ZONEA_AIR_HUMIDITY_CRITICAL, ZONEA_AIR_HUMIDITY_MAX, zoneA_currentAirHumidity, zoneA_isAirHumidityCritical, zoneA_isAirHumidityHot);
    CheckWater_Temperature("ZONE A", ZONEA_WATER_TEMPERATURE_CRITICAL, ZONEA_WATER_TEMPERATURE_MAX, zoneA_currentWaterTemperature, zoneA_isWaterTemperatureCritical, zoneA_isWaterTemperatureHot);
     IntakeFanLogic();
     ExhaustFanLogic();

#ifdef ENABLE_SERIAL_OUTPUT
    Serial.println(F("#########################"));
#endif

    CheckAir_Temperature("ZONE B", ZONEB_AIR_TEMPERATURE_CRITICAL, ZONEB_AIR_TEMPERATURE_MAX, zoneB_currentAirTemperature, zoneB_isAirTemperatureCritical, zoneB_isAirTemperatureHot);
    CheckAir_Humidity("ZONE B", ZONEB_AIR_HUMIDITY_CRITICAL, ZONEB_AIR_HUMIDITY_MAX, zoneB_currentAirHumidity, zoneB_isAirHumidityCritical, zoneB_isAirHumidityHot);
    CheckWater_Temperature("ZONE B", ZONEB_WATER_TEMPERATURE_CRITICAL, ZONEB_WATER_TEMPERATURE_MAX, zoneB_currentWaterTemperature, zoneB_isWaterTemperatureCritical, zoneB_isWaterTemperatureHot);
    // WindFanLogic();
     // SunLightLogic();

#ifdef ENABLE_SERIAL_OUTPUT
    Serial.println(F("#########################"));
#endif

    CheckAir_Temperature("ZONE C", ZONEC_AIR_TEMPERATURE_CRITICAL, ZONEC_AIR_TEMPERATURE_MAX, zoneC_currentAirTemperature, zoneC_isAirTemperatureCritical, zoneC_isAirTemperatureHot);
    CheckAir_Humidity("ZONE C", ZONEC_AIR_HUMIDITY_CRITICAL, ZONEC_AIR_HUMIDITY_MAX, zoneC_currentAirHumidity, zoneC_isAirHumidityCritical, zoneC_isAirHumidityHot);
    CheckWater_Temperature("ZONE C", ZONEC_WATER_TEMPERATURE_CRITICAL, ZONEC_WATER_TEMPERATURE_MAX, zoneC_currentWaterTemperature, zoneC_isWaterTemperatureCritical, zoneC_isWaterTemperatureHot);
    // WaterPumpLogic();
    // OxygenPumpLogic();

#ifdef ENABLE_SERIAL_OUTPUT
    Serial.println(F("#########################"));
#endif

    delay(5000);
}