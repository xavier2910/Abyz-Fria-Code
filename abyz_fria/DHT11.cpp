#ifndef DHT11_h
#define DHT11_h

#include "TempSensor.cpp"
#include <SimpleDHT.h>

#include <StandardCplusplus.h>
#include <stdexcept>

class DHT11Sensor : public TempSensor
{
public:
    byte getTemperature(int pin) override
    {
        byte temp = 0;
        int err = _sensor.read(pin, &temp, NULL, NULL);
        return temp;
    }

    byte getHumidity(int pin) override
    {
        byte humid = 0;
        int err = _sensor.read(pin, NULL, &humid, NULL);
        return humid;
    }

    byte *getData(int pin) override
    {
        std::logic_error err("not implemented");
        throw err;
    }

private:
    SimpleDHT11 _sensor;
};

#endif