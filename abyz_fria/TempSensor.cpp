#ifndef TempSensor_h
#define TempSensor_h

class TempSensor
{

protected:
    int _pin;

public:
    TempSensor(int);

    virtual float getTemperature() = 0;
    virtual float getHumidity() = 0;
};

TempSensor::TempSensor(int pin) : _pin(pin)
{
}

#endif