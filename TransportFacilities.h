// Abstract Products
// TransportFacilities.h
#pragma once
#include <string>
#include <vector>
#include <algorithm>
// #include "TransportMode.h"
#include "TransState.h"
#include "Citizen.h"

class TransportMode;

class TransportFacilities {
protected:
    TransState* currentState;
    TransportFacilities(TransState* state);
    std::vector<TransportMode*> moVec;
    std::vector<Citizen*> citizens;

    
public:
    virtual ~TransportFacilities();  
    TransportFacilities(); 
    void setState(TransState* state);
    int getModeCount();
    virtual void decreaseTraffic();
    TransState* getState();
    void add(TransportMode*momo);
    void remove(TransportMode* momo);
    int GetModeCount();
    std::vector<TransportMode*> GetModes();
    void notifyCitizens();
    void attach(Citizen* c);
    void detach(Citizen* c);
};