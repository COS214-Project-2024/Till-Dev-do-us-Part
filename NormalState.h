// NormalState.h
#ifndef NORMAL_STATE_H
#define NORMAL_STATE_H

#include "TransState.h"

class NormalState : public TransState {
public:
    NormalState();
    void handleState() override;
    void changeState(TransState newState);
};

#endif // NORMAL_STATE_H
