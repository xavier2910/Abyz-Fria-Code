#ifndef Abyz_Fria_h
#define Abyz_Fria_h

#include "DHT11.cpp"

class Abyz_Fria
{
public:
    int main()
    {
        return 0;
    }

    void configTempSensor(int pin)
    {
        _dht11Pin = pin;
    }

private:
    DHT11Sensor _dht11;
    int _dht11Pin;
};

#endif