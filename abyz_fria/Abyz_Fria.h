#ifndef Abyz_Fria_h
#define Abyz_Fria_h

#include <SimpleDHT.h>

class Abyz_Fria
{
public:
    Abyz_Fria();

    void setup(int);

private:
    SimpleDHT11 _dht11;
    int _dht11Pin;
};

#endif