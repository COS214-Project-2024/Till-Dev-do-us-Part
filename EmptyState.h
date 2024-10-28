// EmptyState.h
#ifndef EMPTY_STATE_H
#define EMPTY_STATE_H

#include "TransState.h"

class EmptyState : public TransState {
public:
    void handleState(TransportFacilities* facility) override;
};

#endif // EMPTY_STATE_H
