// CongestedState.h
#ifndef CONGESTED_STATE_H
#define CONGESTED_STATE_H

#include "TransState.h"

class CongestedState : public TransState {
public:
    void handleState(TransportFacilities* facility);
    void changeState(TransState newState);
};

#endif // CONGESTED_STATE_H
