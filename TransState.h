// TransState.h
#ifndef TRANS_STATE_H
#define TRANS_STATE_H

#include <string>
#include <iostream>

class TransportFacilities; // Forward declaration

class TransState {
public:
    virtual ~TransState() = default;
    virtual void handleState(TransportFacilities* facility) = 0;
    void changeState(TransState newState);

};

#endif // TRANS_STATE_H