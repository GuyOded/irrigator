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
    bool isDry();
    bool isWater();
    bool isWet();
    int readValue();

private:
    static const int MOISTURE_LEVEL_INCREMENT = (MoistureLevel::dry - MoistureLevel::water) / 3;
    int m_analogInput;
};

#endif
