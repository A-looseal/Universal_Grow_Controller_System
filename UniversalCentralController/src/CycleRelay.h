#ifndef CycleRelay_h
#define CycleRelay_h
#include "Arduino.h"
#include "ClockController.h"
#include "WaterThermometer.h"
#include "AirThermometer.h"
#include "config/Device_Config.h"

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

void UpdateMillis(){

}

void InitializeSunlight(){
    // intake fan
  pinMode(INTAKEFAN_PIN, OUTPUT);
  digitalWrite(INTAKEFAN_PIN, LOW);
}

void CycleSunLight()
{ // if hardware is currently enabled
  if (canSunShine == true)
  { // check if reservoir is overheating
    if (sunLightState == false && zoneA_isAirHumidityCritical == true || zoneA_isAirHumidityHot == true || zoneA_isAirTemperatureCritical == true || zoneA_isAirTemperatureHot == true)
    {
      Serial.println(F("Attempting to cycle sun light On/Off"));
      // TODO: use ()millis to run pump for x time, x time (relay, not pwm)
      if (sunLightState == false && currentMillis - sunTimer_previousMillis >= SUNLIGHT_FREQUENCY_ON)
      {
        // turn the pump on
        digitalWrite(SUNLIGHT_PIN, HIGH);
        // TODO: track current state of the pump
        sunLightState = true;
        // save the last time you blinked the LED
        sunTimer_previousMillis = currentMillis;
        Serial.println(F("sun light is on."));
      }

      // TODO: use ()millis to stop pump for x time (relay, not pwm)
      if (sunLightState == true && currentMillis - sunTimer_previousMillis >= SUNLIGHT_FREQUENCY_OFF)
      {
        // turn the pump off
        digitalWrite(SUNLIGHT_PIN, LOW);
        // TODO: track current state of the pump
        sunLightState = false;
        // save the last time you blinked the LED
        sunTimer_previousMillis = currentMillis;
        Serial.println(F("sun light is off."));
      }

      // TODO: only do off cycle logic if the off frequency is 0
    }
  }
  if (canSunShine == false)
  {
    digitalWrite(SUNLIGHT_PIN, LOW);
  }
}




#endif