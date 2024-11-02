// TransState.h
#ifndef TRANS_STATE_H
#define TRANS_STATE_H

#include <string>
#include <iostream>

class TransportFacilities; // Forward declaration

class TransState {
private:
    TransportFacilities* stateFacility;

protected: 
    std:: string name;
public:
    virtual ~TransState() = default;
    virtual void handleState() = 0;
    void changeState();
    virtual std:: string getStateName(){return name;}

};

#endif // TRANS_STATE_H