#ifndef TempSensor_h
#define TempSensor_h

using namespace std;

class TempSensor
{
public:
    virtual byte getTemperature(int);
    virtual byte getHumidity(int);
    virtual byte *getData(int);
};

#endif