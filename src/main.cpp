#include <Arduino.h>
#include "Seeed_BME280.h"

BME280 bme280;

#define SDA 4
#define SCL 5

void setup() {
  Wire.begin(SDA);
  Wire.setClock(SCL);
  Serial.begin(9600);
  bme280.init();
}

struct sensorReading {
  float pressure;
  int airQuality;
  float temperature;
  float altitude;
  uint32_t humidity;
};

sensorReading getReading(BME280 bme280) {
  float pressure = bme280.getPressure();
  return sensorReading{
    pressure,
    analogRead(A0),
    bme280.getTemperature(),
    bme280.calcAltitude(pressure),
    bme280.getHumidity()
  };
}

void serialDump(sensorReading reading) {
  Serial.print("{ \"airQuality\": ");
  Serial.print(reading.airQuality, DEC);
  Serial.print(", \"pressure\": ");
  Serial.print(reading.pressure);
  Serial.print(", \"temperature\": ");
  Serial.print(reading.temperature);
  Serial.print(", \"altitude\": ");
  Serial.print(reading.altitude);
  Serial.print(", \"humidity\": ");
  Serial.print(reading.humidity);
  Serial.println("}");
}

void loop() {
  serialDump(getReading(bme280));
  delay(1000);
}