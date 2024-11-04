// NormalState.h
#ifndef NORMAL_STATE_H
#define NORMAL_STATE_H

#include "TransState.h"
#include "CongestedState.h"
#include "EmptyState.h"

class NormalState : public TransState {
public:
    NormalState(TransportFacilities*f);
    void handleState() override;
    void changeState();
};

#endif // NORMAL_STATE_H
