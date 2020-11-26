#include "MoistureSensor.h"

const unsigned int LED = 13;

MoistureSensor moistureSensor = MoistureSensor(0);

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
int moisture_val;
moisture_val = analogRead(0); //connect sensor to Analog 0 
Serial.println(moisture_val);
Serial.println(moistureSensor.is_dry(moisture_val) ? "dry" :
 moistureSensor.is_water(moisture_val) ? "water" :
 moistureSensor.is_wet(moisture_val) ?  "wet" : "not defined"
 ); 
delay(500);
}




