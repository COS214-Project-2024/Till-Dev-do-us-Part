// EmptyState.h
#ifndef EMPTY_STATE_H
#define EMPTY_STATE_H

#include "TransState.h"
#include "NormalState.h"
#include "CongestedState.h"

class EmptyState : public TransState {
public:
    void handleState() override;
    void changeState();
    EmptyState(TransportFacilities*f);
};

#endif // EMPTY_STATE_H
