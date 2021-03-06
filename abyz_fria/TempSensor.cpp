#ifndef TempSensor_h
#define TempSensor_h

class TempSensor
{

protected:
    int _pin;

public:
    TempSensor(int pin) : _pin(pin)
{
}

    virtual float getTemperature() = 0;
    virtual float getHumidity() = 0;
};


#endif