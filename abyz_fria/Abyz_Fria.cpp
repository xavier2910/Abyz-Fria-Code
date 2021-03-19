#ifndef Abyz_Fria_h
#define Abyz_Fria_h

#include "DHT11.cpp"
#include "Constants.cpp"
#include "Logger.cpp"

#include <SD.h>
#include <Arduino.h>
#include <Adafruit_MPL3115A2.h>

class Abyz_Fria
{
public:
    void setup()
    {
        _canLoop = true;

        _canLoop = _canLoop && setupSD();

        _logger = Logger("log.csv");
    }

    void loop()
    {
        if (!_canLoop)
        {
            Serial.println(F("error; can't loop"));
            return;
        }

        bool loopSuccess = true;

        loopSuccess = loopSuccess && getSensorData();

        String line[]{String(millis()),
                      String(dhtTemp), String(humid),
                      String(mplTemp), String(alt), String(pascals)};
        loopSuccess = loopSuccess && _logger.log(6, line);
    }

private:
    DHT11Sensor _dht11;
    Adafruit_MPL3115A2 _mpl;

    Logger _logger;

    bool _canLoop;

    float dhtTemp;
    float humid;
    float mplTemp;
    float alt;
    float pascals;

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

    bool getSensorData()
    {
        bool ret = true;

        if (millis() % 1000 == 0)
        {
            dhtTemp = _dht11.getTemperature();
            humid = _dht11.getHumidity();
        }

        if (millis() % 250 == 0)
        {
            if (_mpl.begin())
            {
                mplTemp = _mpl.getTemperature();
                alt = _mpl.getAltitude();
                pascals = _mpl.getPressure();
            }
        }
        else
            ret = false;

        return ret;
    }
};

#endif