// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

//water sensor 1
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS1 12
#define ONE_WIRE_BUS2 10

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire1(ONE_WIRE_BUS1);
OneWire oneWire2(ONE_WIRE_BUS2);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);

/*
 * The setup function. We only start the sensors here
 */
void setup(void) {
  // start serial port
  Serial.begin(112500);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors1.begin();
  sensors2.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void) {
  float tempA = sensors1.getTempCByIndex(0);
  float tempB = sensors2.getTempCByIndex(0);

  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors1.requestTemperatures();  // Send the command to get temperatures
  sensors2.requestTemperatures();  // Send the command to get temperatures
  Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.

  // Check if reading was successful
  if (tempA != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempA);
  } else {
    Serial.println("Error");
  }

    Serial.print("Temperature for the device 2 (index 1) is: ");
    Serial.println(tempB);
delay(1000);
}
