#ifndef ClockController_h
#define ClockController_h
#include "Arduino.h"
#include "RTClib.h"

RTC_DS3231 OnBoardClock; // clock object
DateTime currentTime;    // current time object

int currentHour;
int currentMinute;

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
}

void UpdateClock()
{
    // get a reading of the current time
    currentTime = OnBoardClock.now();
    currentHour = (currentTime.hour());
    currentMinute = (currentTime.minute());
}

#endif