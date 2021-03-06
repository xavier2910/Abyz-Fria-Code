#ifndef DHT11_h
#define DHT11_h

#include "TempSensor.cpp"
#include "Constants.cpp"
#include <SimpleDHT.h>


class DHT11Sensor : public TempSensor
{
public:
    DHT11Sensor() : TempSensor(Constants::DHT11::kPin)
    {
    }

    float getTemperature() override
    {
        float temp = 0;
        int err = _sensor.read2(_pin, &temp, NULL, NULL);
        return temp;
    }

    float getHumidity() override
    {
        float humid = 0;
        int err = _sensor.read2(_pin, NULL, &humid, NULL);
        return humid;
    }

private:
    SimpleDHT11 _sensor;
};

#endif