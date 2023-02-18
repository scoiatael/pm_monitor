#include <Arduino.h>
#include "Seeed_BME280.h"

BME280 bme280;
bool bme280_init = false;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(16, OUTPUT);
  Wire.begin(5);
  Wire.setClock(4);
  digitalWrite(2, LOW);
  digitalWrite(16, LOW);
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
  Serial.print("loop. Ready? ");
  Serial.println(bme280_init);
  digitalWrite(2, LOW);
  digitalWrite(16, LOW);
  if (!bme280_init) {
    digitalWrite(2, HIGH);
    bme280_init = bme280.init();
  } else {
    digitalWrite(16, HIGH);
    serialDump(getReading(bme280));
  }
  delay(1000);
}