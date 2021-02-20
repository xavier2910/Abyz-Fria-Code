#ifndef TempSensor_h
#define TempSensor_h

class TempSensor
{
protected:
    int _pin;

public:
    TempSensor(int);

    virtual byte getTemperature() = 0;
    virtual byte getHumidity() = 0;
    virtual byte *getData() = 0;
};

TempSensor::TempSensor(int pin) : _pin(pin)
{
}

#endif