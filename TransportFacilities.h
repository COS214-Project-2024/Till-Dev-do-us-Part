// Abstract Products
// TransportFacilities.h
#ifndef TRANSPORTFACILITIES_H
#define TRANSPORTFACILITIES_H
#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "TransportMode.h"
// #include "TransportMode.h"
#include "TransState.h"
#include "Citizen.h"

class TransportMode;
class TransState;

class TransportFacilities {
protected:
    std::string name; 
    TransState* currentState;
    std::vector<TransportMode*> moVec;
    std::vector<Citizen*> citizens;

    
public:
    virtual ~TransportFacilities();  
    TransportFacilities(); 
    // TransportFacilities(TransState* state);
    virtual void setState(TransState* state);
    virtual int getModeCount();
    virtual void decreaseTraffic();
    virtual TransState* getState();
    virtual void add(TransportMode*momo);
    virtual void remove(TransportMode* momo);
    virtual int GetModeCount();
    virtual std::vector<TransportMode*> GetModes();
    virtual void notifyCitizens();
    virtual void attach(Citizen* c);
    virtual void detach(Citizen* c);
    virtual std:: string getFacilName();
};

#endif