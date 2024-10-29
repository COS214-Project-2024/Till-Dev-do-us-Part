// Abstract Products
// TransportFacilities.h
#pragma once
#include <string>
#include <vector>
// #include "TransportMode.h"
#include "TransState.h"

class TransportMode;

class TransportFacilities {
protected:
    TransState* currentState;
    TransportFacilities(TransState* state) : currentState(state) {};
    // std::unique_ptr<TransState> currentState;
    
    

public:
    virtual ~TransportFacilities() = default;   
    virtual void maintain() = 0;
    virtual void useTransport() = 0;
    void setState(TransState* state);
    void handleState();
    // Methods to access vehicle counts
    int getVehicleCount();
    int getTrainCount();
    int getPlaneCount();

    //Mediator
    virtual void changeState(const std::string& state) = 0;
};