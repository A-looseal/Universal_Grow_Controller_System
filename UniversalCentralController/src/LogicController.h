#ifndef Logic_Contorller_h
#define Logic_Contorller_h
#include "Arduino.h"
#include "DeviceController.h"

void SunLightLogic()
{
    // if hardware is not currently enabled
    if (canSunShine == false)
    {
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("attempting to enable sun light capability: "));
#endif
        // check if the current time is greater than the set on time, but in the same period.
        if (currentHour >= SUNLIGHT_TIME_TURN_ON_HOUR)
        {
            // enable hardware capability
            canSunShine = true;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.println(F("successfully enabled sun light!"));
#endif
        }
        else
        {
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.println(F("not yet time to enable sun light."));
#endif
        }
    }
    else if (canSunShine == true)
    {
        {
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.print(F("attempting to disable sun light capability: "));
#endif
            // check if the current time is greater than the set on time, but in the same period.
            if (currentHour >= SUNLIGHT_TIME_TURN_OFF_HOUR)
            {
                // if the hardare should be enabled, enable hardware capability
                canSunShine = false;
#ifdef ENABLE_SERIAL_OUTPUT
                Serial.println(F("successfully disabled sun light!"));
#endif
            }
            else
            {
#ifdef ENABLE_SERIAL_OUTPUT
                Serial.println(F("not yet time to disable sun light."));
#endif
            }
        }
    }

    CycleSunLight();
}

void WaterPumpLogic()
{
    // if hardware is not currently enabled
    if (canWaterFlow == false)
    {

#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("attempting to enable water capability: "));
#endif
        // check if the current time is greater than the set on time, but in the same period.
        if (currentHour >= WATERPUMP_TIME_TURN_ON_HOUR)
        {
            // if the hardare should be enabled, enable hardware capability
            canWaterFlow = true;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.println(F("successfully enabled water!"));
#endif
        }
        else
        {
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.println(F("not yet time to enable water."));
#endif
        }
    }
    // if hardware is not currently enabled
    else if (canWaterFlow == true)
    {
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("attempting to disable water capability: "));
#endif
        // check if the current time is greater than the set on time, but in the same period.
        if (currentHour >= WATERPUMP_TIME_TURN_OFF_HOUR)
        {
            // if the hardare should be enabled, enable hardware capability
            canWaterFlow = false;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.println(F("successfully disabled water!"));
#endif
        }
        else
        {
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.println(F("not yet time to disable water."));
#endif
        }
    }
    CycleWaterPump();
}

void OxygenPumpLogic()
{
    // if hardware is not currently enabled
    if (canOxygenFlow == false)
    {
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("attempting to enable oxygen capability: "));
#endif
        // check if the current time is greater than the set on time, but in the same period.
        if (currentHour >= OXYGENPUMP_TIME_TURN_ON_HOUR)
        {
            // if the hardare should be enabled, enable hardware capability
            canOxygenFlow = true;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.println(F("successfully enabled oxygen!"));
#endif
        }
        else
        {
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.println(F("not yet time to enable oxygen."));
#endif
        }
    } // if hardware is not currently enabled
    else if (canOxygenFlow == true)
    {
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.print(F("attempting to disable oxygen capability: "));
#endif
        // check if the current time is greater than the set on time, but in the same period.
        if (currentHour >= OXYGENPUMP_TIME_TURN_OFF_HOUR)
        {
            // if the hardare should be enabled, enable hardware capability
            canOxygenFlow = false;
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.println(F("successfully disabled oxygen!"));
#endif
        }
        else
        {
#ifdef ENABLE_SERIAL_OUTPUT
            Serial.println(F("not yet time to disable oxygen."));
#endif
        }
    }
    CycleOxygenPump();
}

void IntakeFanLogic(){
    canIntakeFlow = true;
    CycleIntakeFan();
}

void ExhaustFanLogic(){
    canExhaustFlow = true;
    CycleExhaustFan();
}

void WindFanLogic(){
    canWindFlow = true;
}

#endif