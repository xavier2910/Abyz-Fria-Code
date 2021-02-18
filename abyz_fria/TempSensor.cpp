#ifndef TempSensor_h
#define TempSensor_h

class TempSensor
{
public:
    virtual byte getTemperature(int) = 0;
    virtual byte getHumidity(int) = 0;
    virtual byte *getData(int) = 0;
};

#endif