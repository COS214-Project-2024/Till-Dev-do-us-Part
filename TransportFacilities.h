// Abstract Products
// TransportFacilities.h
#pragma once
#include <string>
#include <vector>
#include "TransportMode.h"
#include "TransState.h"

class TransportFacilities {
protected:
    TransState* currentState;
    TransportFacilities(TransState* state);
    // std::unique_ptr<TransState> currentState;

public:
    virtual ~TransportFacilities() = default;   
    virtual void maintain() = 0;
    virtual void useTransport() = 0;
    void setState(TransState* state);
    void handleState();
};