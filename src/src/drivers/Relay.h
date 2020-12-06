#ifndef relay_h
#define releay_h

namespace RelayType
{
    enum  RelayType
    {
        NC = 0,
        NO = 1
    };
}

class Relay
{
    public:
        Relay(RelayType::RelayType relayType = RelayType::NO);
        void setRelay();
        void clearRelay();
        bool isOn();
        bool isOff();

    private:
        bool m_isOn;
};


#endif