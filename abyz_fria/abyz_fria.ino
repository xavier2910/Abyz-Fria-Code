#include "Abyz_Fria.cpp"

#define DHT_PIN 2 //TODO: set this pin

Abyz_Fria rocket;

void setup()
{
    Serial.begin(9600);

        rocket.main();
}

void loop()
{
}