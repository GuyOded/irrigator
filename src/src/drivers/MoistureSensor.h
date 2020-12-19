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
    bool isDisconnected();

private:
    static const int DISCONNECTED_VALUE = 1023;
    static const int MOISTURE_LEVEL_INCREMENT = (MoistureLevel::dry - MoistureLevel::water) / 3;
    int m_analogInput;
};

#endif
