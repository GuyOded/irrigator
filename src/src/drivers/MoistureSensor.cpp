#include "MoistureSensor.h"
#include <Arduino.h>

MoistureSensor::MoistureSensor(int analogInput)
{
    m_analogInput = analogInput;
}

int MoistureSensor::moistureStep()
{
    return (MoistureLevel::dry - MoistureLevel::water) / 3;
}

bool MoistureSensor::isDry(int moistureVal)
{
    return moistureVal >= MoistureLevel::dry - moistureStep();
}

bool MoistureSensor::isWater(int moistureVal)
{
    return moistureVal < (MoistureLevel::water + moistureStep());
}

bool MoistureSensor::isWet(int moistureVal)
{
    return !isDry(moistureVal) && !isWater(moistureVal);
}

int MoistureSensor::readValue()
{
    return analogRead(m_analogInput);
}
