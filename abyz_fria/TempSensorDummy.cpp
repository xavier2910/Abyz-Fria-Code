#ifndef TempSensorDummy_h
#define TempSensorDummy_h

#include "TempSensor.cpp"

class TempSensorDummy : public TempSensor
{
public:
    TempSensorDummy() : TempSensor(-1) {}

    float getTemperature() override{
    return 20.0f;
}

    float getHumidity() override{
    return 20.0f;
}
};


#endif