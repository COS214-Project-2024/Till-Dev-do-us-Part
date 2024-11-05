// Abstract Products
// TransportStation.h
// #include "TransportMode.h"
#ifndef TRANSPORTSTATION_H
#define TRANSPORTSTATION_H
#include <string>

class TransportStation {
public:
    virtual ~TransportStation();
    virtual void handlePassengers() = 0;
    virtual void manageFreight() = 0;
    virtual void maintain() = 0;
    
};

#endif