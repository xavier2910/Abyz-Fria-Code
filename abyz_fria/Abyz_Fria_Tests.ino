#line 2 "Abyz_Fria_Tests.ino"

#include <AUnit.h>

#include "TempSensorDummy.cpp"
#include "Commands/CommandDummy.cpp"

test(tempSensor)
{
    TempSensorDummy temp;

    assertEqual(temp.getTemperature(), 20.0f);
    assertEqual(temp.getHumidity(), 20.0f);
}

test(command)
{
    CommandDummy command;
    for (int i = 0; i < 100; ++1)
    {
        if (i == 9)
        {
            command.begin();
        }
        if (i == 89)
        {
            command.end();
        }
        command();
        if (i >= 9 && i < 89)
        {
            assertTrue(command.hasSetup);
            assertFalse(command.torndown);
            assertEqual(command.executedTime, i - 9);
        }
        else if (i < 9)
        {
            assertFalse(command.hasSetup);
            assertFalse(command.torndown);
            assertEqual(command.executedTime, 0);
        }
        else if (i >= 89)
        {
            assertTrue(command.hasSetup);
            assertTrue(command.torndown);
            assertEqual(command.executedTime, 80)
        }
    }
}

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    aunit::TestRunner::run();
}