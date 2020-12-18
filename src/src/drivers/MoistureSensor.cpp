#include "MoistureSensor.h"
#include <Arduino.h>

MoistureSensor::MoistureSensor(int analogInput)
{
    m_analogInput = analogInput;
}

bool MoistureSensor::isDry()
{
    return readValue() >= (MoistureLevel::Dry - MOISTURE_LEVEL_INCREMENT);
}

bool MoistureSensor::isWater()
{
    return readValue() < (MoistureLevel::Water + MOISTURE_LEVEL_INCREMENT);
}

bool MoistureSensor::isWet()
{
    return !isDry() && !isWater();
}

int MoistureSensor::readValue()
{
    return analogRead(m_analogInput);
}
