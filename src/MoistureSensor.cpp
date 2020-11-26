#include "MoistureSensor.h"

MoistureSensor::MoistureSensor(int analogInput){
  _analogInput = analogInput;
}

int MoistureSensor::moistureStep(){
    return ((int)MoistureSensor::MoistureLevl::dry - (int)MoistureSensor::MoistureLevl::water)/3;
}

bool MoistureSensor::is_dry(int moisture_val){
  return moisture_val >= (int)MoistureSensor::MoistureLevl::dry - moistureStep();
}

bool MoistureSensor::is_water(int moisture_val ){
  return moisture_val < ((int) MoistureSensor::MoistureLevl::water + moistureStep()); 
}

bool MoistureSensor::is_wet(int moisture_val){
  return !is_dry(moisture_val) && !is_water(moisture_val);
}

int MoistureSensor::readValue(){
  return analogRead(_analogInput);
}

