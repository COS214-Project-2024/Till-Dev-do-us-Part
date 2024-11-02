// Abstract Products
// TransportStation.h
#include "TransportMode.h"
#pragma once
#include <string>

class TransportStation {
// protected:
//     TransportMode* momo;
public:
    virtual ~TransportStation() = default;
    virtual void handlePassengers() = 0;
    virtual void manageFreight() = 0;
    virtual void maintain() = 0;
    
};
