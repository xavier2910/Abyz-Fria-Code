#line 2 "Abyz_Fria_Tests.ino"

#include <AUnit.h>

#include "TempSensorDummy.cpp"

test(tempSensor)
{
    TempSensorDummy temp(-1);

    assertEqual(temp.getTemperature(), 20.0f);
    assertEqual(temp.getHumidity(), 20.0f);
}

test(command)
{
}

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    aunit::TestRunner::run();
}