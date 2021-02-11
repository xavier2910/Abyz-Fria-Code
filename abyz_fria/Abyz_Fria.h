#ifndef Abyz_Fria_h
#define Abyz_Fria_h

#include "TempSensor.cpp

class Abyz_Fria
{
public:
    Abyz_Fria();

    void setup(int);

private:
    TempSensor _dht11;
    int _dht11Pin;
};

#endif