#include <Arduino.h>
// #include "Seeed_BME280.h"

// #define MQ_135_PIN 0

// BME280 bme280;

// void setup() {
//   Serial.begin(9600);
//   bme280.init();
// }

// struct sensorReading {
//   float pressure;
//   int airQuality;
//   float temperature;
//   float altitude;
//   uint32_t humidity;
// };

// sensorReading getReading(BME280 bme280) {
//   float pressure = bme280.getPressure();
//   return sensorReading{
//     pressure,
//     analogRead(MQ_135_PIN),
//     bme280.getTemperature(),
//     bme280.calcAltitude(pressure),
//     bme280.getHumidity()
//   };
// }

// void serialDump(sensorReading reading) {
//   Serial.print("{ \"airQuality\": ");
//   Serial.print(reading.airQuality, DEC);
//   Serial.print(", \"pressure\": ");
//   Serial.print(reading.pressure);
//   Serial.print(", \"temperature\": ");
//   Serial.print(reading.temperature);
//   Serial.print(", \"altitude\": ");
//   Serial.print(reading.altitude);
//   Serial.print(", \"humidity\": ");
//   Serial.print(reading.humidity);
//   Serial.println("}");
// }

// void loop() {
//   serialDump(getReading(bme280));
//   delay(1000);
// }

#define LED_ESP12 2
#define LED_BUILTIN 16
void setup() {
  pinMode(LED_ESP12, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
} 
 
void loop() { 
  digitalWrite(LED_ESP12, HIGH); 
  digitalWrite(LED_BUILTIN, LOW); 
  delay(900); 
  digitalWrite(LED_ESP12, LOW);
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(500);
} 