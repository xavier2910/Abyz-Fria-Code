#include <Wire.h>                       // I2C library, primarily for altimeter
#include ".\Libs\SimpleDHT\SimpleDHT.h" // Temperature & humidity sensor library

#define DHT_PIN 2 //TODO: set this pin

SimpleDHT11 tempSensor;

bool readTemperatureSensor(byte &temperature, byte &humidity)
{
    if (tempSensor.read(DHT_PIN, &temperature, &humidity, NULL))
    {
        Serial.print("Read DHT11 failed.");
        return false;
    }
    return true;
}

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    byte temperature = 0;
    byte humidity = 0;
    if (readTemperatureSensor(temperature, humidity))
    {
        Serial.print("Sample OK: ");
        Serial.print((int)temperature);
        Serial.print(" *C, ");
        Serial.print((int)humidity);
        Serial.println(" %");
    }
}