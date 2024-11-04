// CongestedState.h
#ifndef CONGESTED_STATE_H
#define CONGESTED_STATE_H

#include "TransState.h"
#include "TransportFacilities.h"
#include "EmptyState.h"
#include "NormalState.h"


class CongestedState : public TransState {
public:
    CongestedState(TransportFacilities* f);
    void handleState();
    void changeState();


};

#endif // CONGESTED_STATE_H

