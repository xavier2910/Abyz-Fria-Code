#ifndef Abyz_Fria_h
#define Abyz_Fria_h

#include "DHT11.cpp"
#include "Constants.cpp"

#include <SD.h>
#include <arduino.h>

class Abyz_Fria
{
public:
    void setup()
    {
        _canLoop = true;

        _canLoop &= setupSD();
    }

    void loop()
    {
        if (!_canLoop)
        {
            Serial.println(F("error; can't loop"));
            return;
        }

        SDLib::File logFile = getLogFile();
        if (logFile)
        {
            logLine(logFile, String(dhtTemp) + String(",") + String(humid));
        }
    }

private:
    DHT11Sensor _dht11;

    bool _canLoop;

    float dhtTemp;
    float humid;

    bool setupSD()
    {
        pinMode(Constants::SD::kCSPin, OUTPUT);
        pinMode(Constants::SD::kPowPin, OUTPUT);
        digitalWrite(Constants::SD::kPowPin, HIGH);

        if (!SD.begin(Constants::SD::kCSPin))
        {
            Serial.println(F("Card failure"));
            return false;
        }
        else
            return true;
    }

    void getSensorData()
    {
        if (millis() % 1000 == 0)
        {
            dhtTemp = _dht11.getTemperature();
            humid = _dht11.getHumidity();
        }
    }

    SDLib::File getLogFile()
    {
        return SD.open("log.csv", FILE_WRITE);
    }

    void logLine(SDLib::File logFile, String param)
    {
        logFile.println(param);
    }
};

#endif