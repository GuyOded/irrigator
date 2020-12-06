#include "src/drivers/MoistureSensor.h"

const unsigned int LED = 13;

MoistureSensor moistureSensor = MoistureSensor(A0);

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    int moistureVal;
    moistureVal = moistureSensor.readValue();
    Serial.println(moistureSensor.isDry(moistureVal) ? "dry" : moistureSensor.isWater(moistureVal) ? "water" : moistureSensor.isWet(moistureVal) ? "wet" : "not defined");
    delay(500);
}
