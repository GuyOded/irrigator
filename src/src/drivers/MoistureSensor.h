#ifndef moisture_sensor_h
#define moisture_sensor_h

namespace MoistureLevel
{
    enum MoistureLevel
    {
        Dry = 587,
        Water = 309
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
    static const int MOISTURE_LEVEL_INCREMENT = (MoistureLevel::Dry - MoistureLevel::Water) / 3;
    int m_analogInput;
};

#endif
