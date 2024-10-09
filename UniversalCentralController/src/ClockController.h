#ifndef ClockController_h
#define ClockController_h
#include "Arduino.h"
#include "RTClib.h"

#define ENABLE_SERIAL_OUTPUT

RTC_DS3231 OnBoardClock; // clock object
DateTime currentTime;    // current time object

int currentHour;
int currentMinute;
byte currentPeriod;

/* SYSTEM CLOCK VARIABLES */
unsigned long currentMillis;

void InitializeClock()
{
    OnBoardClock.begin();
    // search for connected clock. Dont continue if none is found
    if (!OnBoardClock.begin())
    {
#ifdef ENABLE_SERIAL_OUTPUT
        Serial.println("Couldn't find RTC");
        Serial.flush();
#endif
        while (1)
            delay(10);
    }

/*
    if (OnBoardClock.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    OnBoardClock.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }*/
}

void UpdateClock()
{
    currentMillis = millis();
    // get a reading of the current time
    currentTime = OnBoardClock.now();
    currentHour = (currentTime.hour());
    currentMinute = (currentTime.minute());
    currentPeriod = (currentTime.isPM());
}

#endif