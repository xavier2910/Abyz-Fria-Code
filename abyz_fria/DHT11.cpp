#ifndef DHT11_h
#define DHT11_h

#include "TempSensor.cpp"
#include <SimpleDHT.h>

#include <StandardCplusplus.h>
#include <memory>

class DHT11Sensor : public TempSensor
{
public:
    byte getTemperature(int pin) override
    {
        byte temp = 0;
        _sensor.read(pin, &temp, NULL, NULL);
        return temp;
    };

    byte getHumidity(int pin) override
    {
        byte humid = 0;
        _sensor.read(pin, NULL, &humid, NULL);
        return humid;
    }

private:
    SimpleDHT11 _sensor;
};

#endif