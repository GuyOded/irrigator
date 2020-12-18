#ifndef relay_h
#define relay_h

#include <Arduino.h>

namespace RelayContactType
{
    enum RelayContactType
    {
        NormallyClosed = 0,
        NormallyOpen = 1
    };
}

namespace RelayActivation
{
    enum RelayActivation
    {
        Low = 0,
        High = 1
    };
}

class Relay
{
public:
    Relay(const uint8_t pinNumber,
          const RelayContactType::RelayContactType relayType = RelayContactType::NormallyOpen,
          const RelayActivation::RelayActivation activationType = RelayActivation::Low) : m_pinNumber{pinNumber},
                                                                                          m_contactType{relayType},
                                                                                          m_activationType{activationType}
    {
        m_isActivated = true;
        pinMode(m_pinNumber, OUTPUT);
        clear();
    }

    // TODO: Choose a more informative name
    void set();
    void clear();
    bool isOn();

private:
    const uint8_t m_pinNumber;
    const RelayContactType::RelayContactType m_contactType;
    const RelayActivation::RelayActivation m_activationType;
    bool m_isActivated;
    // TODO: Choose a more informative name
    void activate();
    void deactivate();
};

#endif