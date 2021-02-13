#ifndef TempSensor_h
#define TempSensor_h

#include <StandardCplusplus.h>
#include <memory>

class TempSensor
{
public:
    virtual byte getTemperature(int);
    virtual byte getHumidity(int);
    virtual unique_ptr<byte[]> getData(int);
};

#endif