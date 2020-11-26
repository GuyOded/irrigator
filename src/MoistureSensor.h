#ifndef moisture_sensor_h
#define moisture_sensor_h

class MoistureSensor
{
    public:
    MoistureSensor(int analogInput);
    bool is_dry(int moisture_val);
    bool is_water(int moisture_val);
    bool is_wet(int moisture_val);
    enum class MoistureLevl {dry=587,water=309};
    int readValue();

    private:
    int moistureStep();
    int _analogInput;
};




#endif