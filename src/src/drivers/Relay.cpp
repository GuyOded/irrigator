#include "Relay.h"
#include <Arduino.h>

// TODO: Optimize code repeatition to a minimum in set() and clear()

void Relay::set()
{
    if (m_isActivated)
    {
        return;
    }
    m_isActivated = true;

    if (m_contactType == RelayContactType::NormallyOpen)
    {
        activate();
        return;
    }

    deactivate();
    return;
}

void Relay::clear()
{
    if (!m_isActivated)
    {
        return;
    }
    m_isActivated = false;

    if (m_contactType == RelayContactType::NormallyOpen)
    {
        deactivate();
        return;
    }

    activate();
    return;
}

bool Relay::isOn()
{
    return m_isActivated;
}

void Relay::activate()
{
    uint8_t outputValue = m_activationType == RelayActivation::High ? HIGH : LOW;
    digitalWrite(m_pinNumber, outputValue);
}

void Relay::deactivate()
{
    uint8_t outputValue = m_activationType == RelayActivation::High ? LOW : HIGH;
    digitalWrite(m_pinNumber, outputValue);
}
