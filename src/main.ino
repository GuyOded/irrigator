#include "src/drivers/MoistureSensor.h"

const unsigned int LED = 13;

MoistureSensor moistureSensor = MoistureSensor(0);

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int moistureVal;
    moistureVal = analogRead(0); //connect sensor to Analog 0
    Serial.println(moistureVal);
    Serial.println(moistureSensor.isDry(moistureVal) ? "dry" : moistureSensor.isWater(moistureVal) ? "water" : moistureSensor.isWet(moistureVal) ? "wet" : "not defined");
    delay(500);
}
