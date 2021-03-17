#ifndef DHT11_h
#define DHT11_h

#include "Constants.cpp"
#include <SimpleDHT.h>

class DHT11Sensor
{
public:
    DHT11Sensor() : _pin(Constants::DHT11::kPin)
    {
    }

    float getTemperature()
    {
        float temp = 0;
        int err = _sensor.read2(_pin, &temp, NULL, NULL);
        return temp;
    }

    float getHumidity()
    {
        float humid = 0;
        int err = _sensor.read2(_pin, NULL, &humid, NULL);
        return humid;
    }

private:
    SimpleDHT11 _sensor;
    int _pin;
};

#endif