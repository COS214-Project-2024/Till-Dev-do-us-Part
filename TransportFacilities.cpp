#include "TransportFacilities.h"

// Constructor definition, matching the declaration in the header
TransportFacilities::TransportFacilities(TransState* state)
    : currentState(state) {}

void TransportFacilities::setState(TransState* newState) {
    currentState = newState;
}

void TransportFacilities::handleState() {
    if (currentState) {
        currentState->handleState(this);
    }
}
