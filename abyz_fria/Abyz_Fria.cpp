#ifndef Abyz_Fria_h
#define Abyz_Fria_h

#include "DHT11.cpp"

#include "Commands\ParallelCommandExecuter.cpp"

class Abyz_Fria
{
public:
    void setup()
    {
        _primaryCommand.begin();
    }

    void loop()
    {
        _primaryCommand();
    }

private:
    DHT11Sensor _dht11;

    ParallelCommandExecuter _primaryCommand;
};

#endif