// CongestedState.h
#ifndef CONGESTED_STATE_H
#define CONGESTED_STATE_H

#include "TransState.h"
#include "TransportFacilities.h"
#include "EmptyState.h"
#include "NormalState.h"

class NormalState;
class EmptyState;

class CongestedState : public TransState {
private:
    TransportFacilities* stateFacility;
public:
    CongestedState();
    void handleState();
    void changeState();
    std:: string getStateName();

};

#endif // CONGESTED_STATE_H
