#include "src/ClockController.h"

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
    delay(1000);
}