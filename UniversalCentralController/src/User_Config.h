//uncomment the following to enable verbose outout via the serial port. Useful for developing/debugging
#define ENABLE_SERIAL_OUTPUT

/*ZONE A - The upper atmosphere of the grow tent
current setup: 1x Air sensor | 1x Co2 Sensor*/
//pin the water temperature probe is connected to
#define ZONEA_WATER_TEMPERATURE_SENSOR_PIN 12
//critical temperature determined if the measured  water temperateure is equal to or greater than this value,
#define ZONEA_WATER_TEMPERATURE_CRITICAL 30
//max temperature determined if the measured water temperateure is equal to or greater than this value,
#define ZONEA_WATER_TEMPERATURE_MAX 28
#define ZONEA_AIR_SENSOR_TYPE DHT22                     //(the pin the water temperature sensor is currently connected to)
#define ZONEA_AIR_SENSOR_PIN 11 
#define ZONEA_AIR_TEMPERATURE_CRITICAL 32
#define ZONEA_AIR_TEMPERATURE_MAX 30
#define ZONEA_AIR_HUMIDITY_CRITICAL 75
#define ZONEA_AIR_HUMIDITY_MAX 70








#define ZONEB_WATER_TEMPERATURE_SENSOR_PIN 10
#define ZONEB_WATER_TEMPERATURE_CRITICAL 30
#define ZONEB_WATER_TEMPERATURE_MAX 28
#define ZONEB_AIR_SENSOR_TYPE DHT22                     //(the pin the water temperature sensor is currently connected to)
#define ZONEB_AIR_SENSOR_PIN 9 
#define ZONEB_AIR_TEMPERATURE_CRITICAL 32
#define ZONEB_AIR_TEMPERATURE_MAX 30
#define ZONEB_AIR_HUMIDITY_CRITICAL 75
#define ZONEB_AIR_HUMIDITY_MAX 70


#define ZONEC_WATER_TEMPERATURE_SENSOR_PIN 8
#define ZONEC_WATER_TEMPERATURE_CRITICAL 30
#define ZONEC_WATER_TEMPERATURE_MAX 28
#define ZONEC_AIR_SENSOR_TYPE DHT22                     //(the pin the water temperature sensor is currently connected to)
#define ZONEC_AIR_SENSOR_PIN 7 
#define ZONEC_AIR_TEMPERATURE_CRITICAL 32
#define ZONEC_AIR_TEMPERATURE_MAX 30
#define ZONEC_AIR_HUMIDITY_CRITICAL 75
#define ZONEC_AIR_HUMIDITY_MAX 70