#ifndef Abyz_Fria_h
#define Abyz_Fria_h

#include "TempSensor.cpp"

class Abyz_Fria
{
public:
    int main()
    {
        return 0;
    }

    void configTempSensor(int)
    {
        _dht11Pin = pin;
    }

private:
    TempSensor _dht11;
    int _dht11Pin;
};

#endif