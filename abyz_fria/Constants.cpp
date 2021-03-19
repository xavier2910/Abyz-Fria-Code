#ifndef Constants_h
#define Constants_h

#include "arduino.h"

class Constants
{
public:
    class DHT11
    {
    public:
        static const int kPin = -1; //TODO: set this
    };

    class SD
    {
    public:
        static const int kCSPin = 10;
        static const int kPowPin = 8;
    };
};

#endif