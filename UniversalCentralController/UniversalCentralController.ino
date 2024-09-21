#include "src/ClockController.h"
#include "src/WaterThermometer.h"

/* SYSTEM CLOCK VARIABLES */
unsigned long currentMillis;

void setup()
{
    Serial.begin(115200);
    InitializeClock();
}

void loop()
{
    UpdateClock();

    Serial.print("current hour: ");
    Serial.println(currentHour);
    Serial.print("current minute: ");
    Serial.println(currentMinute);

    Check_Water_Temperature("ZONE A",
                            ZONEA_WATER_TEMPERATURE_CRITICAL,
                            ZONEA_WATER_TEMPERATURE_MAX,
                            zoneA_currentWaterTemperature,
                            zoneA_isWaterTemperatureCritical,
                            zoneA_isWaterTemperatureHot,
                            zoneA_WaterSensor);

    Check_Water_Temperature("ZONE B",
                            ZONEB_WATER_TEMPERATURE_CRITICAL,
                            ZONEB_WATER_TEMPERATURE_MAX,
                            zoneB_currentWaterTemperature,
                            zoneB_isWaterTemperatureCritical,
                            zoneB_isWaterTemperatureHot,
                            zoneB_WaterSensor);

Check_Water_Temperature("ZONE C",
                            ZONEC_WATER_TEMPERATURE_CRITICAL,
                            ZONEC_WATER_TEMPERATURE_MAX,
                            zoneC_currentWaterTemperature,
                            zoneC_isWaterTemperatureCritical,
                            zoneC_isWaterTemperatureHot,
                            zoneC_WaterSensor);
        delay(5000);
#ifdef ENABLE_SERIAL_OUTPUT
    Serial.println('\n');
    Serial.println(F("#########################"));
#endif
}