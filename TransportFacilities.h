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
    TransportMode* momo;
    TransportFacilities(TransState* state);
    std::vector<TransportMode*> moVec;
    std::vector<Citizen*> citizens;

    // std::unique_ptr<TransState> currentState;
    
    

public:
    virtual ~TransportFacilities() = default;  
    TransportFacilities(); 
    // virtual void maintain() = 0;
    // virtual void useTransport() = 0;
    void setState(TransState* state);
    void handleState();
    virtual int getModeCount()=0;
    virtual void decreaseTraffic();
    virtual void changeState();
    TransState* getState();
    void add(TransportMode*momo);
    void remove(TransportMode* momo);
    int GetModeCount();
    std::vector<TransportMode*> GetModes();
    void notifyCitizens();
    void attach(Citizen* c);
    void detach(Citizen* c);

    // Methods to access vehicle counts
    // int getModeCount();
    // int getModeCount();
    // int getPlaneCount();

    //Mediator
    // virtual void changeState(const std::string& state);
};