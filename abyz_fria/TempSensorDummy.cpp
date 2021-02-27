#ifndef TempSensorDummy_h
#define TempSensorDummy_h

#include "TempSensor.cpp"

class TempSensorDummy : public TempSensor
{
public:
    TempSensorDummy();

    float getTemperature() override;

    float getHumidity() override;
};

TempSensorDummy::TempSensorDummy() : TempSensor(-1) {}

float TempSensorDummy::getTemperature()
{
    return 20.0f;
}

float TempSensorDummy::getHumidity()
{
    return 20.0f;
}

#endif