#ifndef TempSensorDummy_h
#define TempSensorDummy_h

#include "TempSensor.cpp"

class TempSensorDummy : public TempSensor
{
public:
    byte getTemperature() override;

    byte getHumidity() override;

    byte *getData() override;
};

byte TempSensorDummy::getTemperature()
{
    return 20;
}

byte TempSensorDummy::getHumidity()
{
    return 20;
}

byte *TempSensorDummy::getData()
{
    return nullptr;
}

#endif