#ifndef moisture_sensor_h
#define moisture_sensor_h

namespace MoistureLevel
{
    enum MoistureLevel
    {
        dry = 587,
        water = 309
    };
}

class MoistureSensor
{
public:
    MoistureSensor(int analogInput);
    bool isDry(int moistureVal);
    bool isWater(int moistureVal);
    bool isWet(int moistureVal);
    int readValue();

private:
    int moistureStep();
    int m_analogInput;
};

#endif
