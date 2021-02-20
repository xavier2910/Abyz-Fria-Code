#ifndef DHT11_h
#define DHT11_h

#include "TempSensor.cpp"
#include <SimpleDHT.h>

#include <StandardCplusplus.h>
#include <stdexcept>

class DHT11Sensor : public TempSensor
{
public:
    byte getTemperature() override
    {
        byte temp = 0;
        int err = _sensor.read(_pin, &temp, NULL, NULL);
        return temp;
    }

    byte getHumidity() override
    {
        byte humid = 0;
        int err = _sensor.read(_pin, NULL, &humid, NULL);
        return humid;
    }

    byte *getData() override
    {
        /*std::logic_error err("not implemented");
        throw err;*/
        // TODO: await fix
    }

private:
    SimpleDHT11 _sensor;
};

#endif