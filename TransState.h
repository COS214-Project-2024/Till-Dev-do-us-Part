// TransState.h
#ifndef TRANS_STATE_H
#define TRANS_STATE_H

#include <string>
#include <iostream>
#include "TransportFacilities.h"

class TransportFacilities; // Forward declaration

class TransState {
protected: 
    std:: string name;
    TransportFacilities* stateFacility;

public:
    virtual ~TransState();
    virtual void handleState() = 0;
    void changeState();
    virtual std:: string getStateName(){return name;}

};

#endif // TRANS_STATE_H