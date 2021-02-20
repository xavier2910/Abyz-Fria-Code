#line 2 "Abyz_Fria_Tests.ino"

#include <AUnit.h>

#include "TempSensor.cpp"
#include "TempSensorDummy.cpp"

test(tempSensor) // TODO: await fix
{
    TempSensorDummy temp(-1);

    assertEqual(temp.getTemperature(), 20);
    assertEqual(temp.getHumidity(), 20);
    assertEqual(temp.getData(), nullptr);
}

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    aunit::TestRunner::run();
}