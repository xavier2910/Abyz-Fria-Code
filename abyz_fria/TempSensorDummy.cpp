#ifndef TempSensorDummy_h
#define TempSensorDummy_h

#include "TempSensor.cpp"

class TempSensorDummy : public TempSensor
{
public:
    float getTemperature() override;

    float getHumidity() override;
};

float TempSensorDummy::getTemperature()
{
    return 20.0f;
}

float TempSensorDummy::getHumidity()
{
    return 20.0f;
}

#endif