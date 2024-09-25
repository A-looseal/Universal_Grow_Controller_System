#ifndef Device_Controller_h
#define Device_Controller_h
#include "Arduino.h"
#include "ClockController.h"
#include "WaterThermometer.h"
#include "AirThermometer.h"
#include "config/device_config/Config_Fan_Exhaust.h"
#include "config/device_config/Config_Fan_Intake.h"
#include "config/device_config/Config_Fan_Wind.h"
#include "config/device_config/Config_Light_Sun.h"
#include "config/device_config/Config_Pump_Oxygen.h"
#include "config/device_config/Config_Pump_Water.h"

/* EXHAUST FAN VARIABLES */
unsigned long exhaustFanTimer_previousMillis = 0; // will store last time LED was updated
bool canExhaustFlow = true;                       //(dynamically control whether the pump can be activated or not. Set by the clock)
bool exhaustFanState = false;                     //(the current state of the water pump)

/* INTAKE FAN VARIABLES */
unsigned long intakeFanTimer_previousMillis = 0; // will store last time LED was updated
bool canIntakeFlow = true;                       //(dynamically control whether the pump can be activated or not. Set by the clock)
bool intakeFanState = false;                     //(the current state of the water pump)

/* WIND FAN VARIABLES */
unsigned long windFanTimer_previousMillis = 0; // will store last time LED was updated
bool canWindFlow = true;                       //(dynamically control whether the pump can be activated or not. Set by the clock)
bool windFanState = false;                     //(the current state of the water pump)

/* SUN LIGHT VARIABLES */
unsigned long sunTimer_previousMillis = 0; // will store last time LED was updated
bool canSunShine = false;                  //(dynamically control whether the pump can be activated or not. Set by the clock)
bool sunLightState = false;                //(the current state of the water pump)

/* WATER PUMP VARIABLES */
unsigned long waterTimer_previousMillis = 0; // will store last time LED was updated
bool canWaterFlow = false;                   //(dynamically control whether the pump can be activated or not. Set by the clock)
bool waterPumpState = false;                 //(the current state of the water pump)

/* OXYGEN PUMP VARIABLES*/
unsigned long oxygenTimer_previousMillis = 0; // will store last time LED was updated
bool canOxygenFlow = false;                   //(dynamically control whether the pump can be activated or not. Set by the clock)
bool oxygenPumpState = false;                 //(the current state of the water pump)

void InitializeAllDevices()
{
  // Input sensors
  InitializeWaterTemperature();
  InitializeAirTemperature();
  // Output devices
  InitializeExhaustFan(); // see Config_Fan_Exhaust.h
  InitializeIntakeFan();  // see Config_Fan_Intake.h
  InitializeWindFans(6);  // see Config_Fan_Wind.h
  InitializeSunLight();   // see Config_Light_Sun.h
  InitializeWaterPump();  // see Config_Pump_Water.h
  InitializeOxygenPump(); // see Config_Pump_Oxygen.h
}

void CycleSunLight()
{ // if hardware can currently be enabled
  if (canSunShine == true)
  { // check if light is already on
    if (sunLightState == false)
    { // check if canopy area is overheating
      Serial.println(F("Attempting to cycle sun light On"));
      if (zoneB_isAirHumidityCritical == false || zoneB_isAirTemperatureCritical == false)
      {
        // turn the sun light on
        digitalWrite(SUNLIGHT_PIN, HIGH);
        // track current state of the sun light
        sunLightState = true;
        Serial.println(F("sun light is on."));
      }
    }

    // check if the light is already off
    if (sunLightState == true)
    {
      if (zoneB_isAirHumidityCritical == true || zoneB_isAirTemperatureCritical == true)
      {
        Serial.println(F("Temperature is CRITICAL, Shutting Sun Light down!"));
        // turn the sun light off
        digitalWrite(SUNLIGHT_PIN, LOW);
        // track current state of the pump
        sunLightState = false;
        Serial.println(F("sun light is off."));
      }
    }
  }

  // turn the light off if it is not time for it to be on
  if (canSunShine == false)
  {
    // turn the sun light off
    digitalWrite(SUNLIGHT_PIN, LOW);
    // track current state of the pump
    sunLightState = false;
    Serial.println(F("sun light is off."));
  }
}

void CycleIntakeFan()
{ // if hardware can currently be enabled
  if (canIntakeFlow == true)
  {
    // check if atmosphere area is currently overheating
    if (zoneA_isAirHumidityCritical == true)
    {
      // check if intake fan is currently off
      if (intakeFanState == false)
      {
        // turn the intake fan on
        digitalWrite(INTAKEFAN_PIN, HIGH);
        // track current state of the intake fan
        intakeFanState = true;
        Serial.println(F("enabled the intake fan."));
      }
    }

    
    else
    {
      if (intakeFanState == true)
      {
        // turn the intake fan off
        digitalWrite(INTAKEFAN_PIN, LOW);
        // track current state of the intake fan
        intakeFanState = false;
        Serial.println(F("disabled the intake fan."));
      }
    }
    
  }


// turn the intake fan off if it is not time for it to be on
if (canIntakeFlow == false)
{
  if (intakeFanState == true)
  {
    // turn the intnake fan off
    digitalWrite(INTAKEFAN_PIN, LOW);
    // track current state of the intake fan
    intakeFanState = false;
    Serial.println(F("disabled the intake fan."));
  }
}
}

void CycleExhaustFan()
{ // if hardware can currently be enabled
  if (canExhaustFlow == true)
  {
    // check if atmosphere area is currently overheating
    if (zoneA_isAirHumidityCritical == true)
    {
      // check if intake fan is currently off
      if (exhaustFanState == false)
      {
        // turn the intake fan on
        digitalWrite(EXHAUSTFAN_PIN, HIGH);
        // track current state of the intake fan
        exhaustFanState = true;
        Serial.println(F("enabled the exhaust fan."));
      }
    }
    else
    {
      // check if intake fan is currently on
      if (exhaustFanState == true)
      {
        // turn the intake fan off
        digitalWrite(EXHAUSTFAN_PIN, LOW);
        // track current state of the intake fan
        exhaustFanState = false;
        Serial.println(F("disabled the exhaust fan."));
      }
    }
  }

  // turn the exhaust fan off if it is not time for it to be on
  if (canExhaustFlow == false)
  {
    if (exhaustFanState == true)
    {
      // turn the exhhaust fan off
      digitalWrite(INTAKEFAN_PIN, LOW);
      // track current state of the exhaust fan
      exhaustFanState = false;
      Serial.println(F("disabled the exhaust fan."));
    }
  }
}

void CycleWaterPump()
{ // if hardware can currently be enabled
  if (canWaterFlow == true)
  {
    // check if reseovoir area is not currently overheating
    if (zoneC_isWaterTemperatureCritical == false)
    {
      // check if water pump is currently off
      if (waterPumpState == false)
      {
        // turn the water pump on
        digitalWrite(WATERPUMP_PIN, HIGH);
        // track current state of the water pump
        waterPumpState = true;
        Serial.println(F("enabled the water pump."));
      }
    }

    // check if the water pump is currently on
    if (waterPumpState == true)
    { // check if resovoir area is currently overheating
      if (zoneC_isWaterTemperatureCritical == true)
      {
        // turn the intake fan off
        digitalWrite(WATERPUMP_PIN, LOW);
        // track current state of the intake fan
        waterPumpState = false;
        Serial.println(F("disabled the water pump."));
      }
    }
  }

  // turn the water off if it is not time for it to be on
  if (canWaterFlow == false)
  {
    // turn the water pump off
    digitalWrite(WATERPUMP_PIN, LOW);
    // track current state of the water pump
    waterPumpState = false;
    Serial.println(F("disabled the water pump."));
  }
}

void CycleOxygenPump()
{ // if hardware can currently be enabled
  if (canOxygenFlow == true)
  {
    // check if reseovoir area is not currently overheating
    if (zoneC_isAirHumidityCritical == false || zoneC_isAirTemperatureCritical == false)
    {
      // check if oxygen pump is currently off
      if (oxygenPumpState == false)
      {
        // turn the oxygen pump on
        digitalWrite(OXYGENPUMP_PIN, HIGH);
        // track current state of the oxygen pump
        oxygenPumpState = true;
        Serial.println(F("enabled the oxygen pump."));
      }
    }

    // check if the oxygen pump is currently on
    if (oxygenPumpState == true)
    { // check if resovoir area is currently overheating
      if (zoneA_isAirHumidityCritical == true || zoneA_isAirTemperatureCritical == true)
      {
        // turn the oxygen pump off
        digitalWrite(OXYGENPUMP_PIN, LOW);
        // track current state of the oxygen pump
        oxygenPumpState = false;
        Serial.println(F("disabled the oxygen pump."));
      }
    }
  }

  // turn the oxygen off if it is not time for it to be on
  if (canOxygenFlow == false)
  {
    // turn the oxygen pump off
    digitalWrite(OXYGENPUMP_PIN, LOW);
    // track current state of the oxygen pump
    oxygenPumpState = false;
    Serial.println(F("disabled the oxygen pump."));
  }
}

#endif