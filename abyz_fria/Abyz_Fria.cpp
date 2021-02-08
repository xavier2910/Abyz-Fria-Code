#include "Abyz_Fria.h"

void Abyz_Fria::setup(int dht11Pin)
{
    Serial.begin(9600);

    _dht11Pin = dht11Pin;
}