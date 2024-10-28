// Abstract Products
// TransportStation.h
#pragma once
#include <string>

class TransportStation {
public:
    virtual ~TransportStation() = default;
    virtual void handlePassengers() = 0;
    virtual void manageFreight() = 0;
    virtual void maintain() = 0;
};
