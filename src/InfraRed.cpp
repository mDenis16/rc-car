
#include "InfraRed.h"
#include <Arduino.h>

bool CInfraRed::Read()
{
    int val = analogRead(pin);
    if (firstReadValue == -1)
        firstReadValue = val - 100;
        
    return val <= (firstReadValue);
}
void CInfraRed::Init()
{
    pinMode(pin, INPUT);
}