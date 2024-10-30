// NormalState.h
#ifndef NORMAL_STATE_H
#define NORMAL_STATE_H

#include "TransState.h"

class NormalState : public TransState {
public:
    void handleState(TransportFacilities* facility) override;
    void changeState(TransState newState);
};

#endif // NORMAL_STATE_H