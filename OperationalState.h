#ifndef OPERATIONALSTATE_H
#define OPERATIONALSTATE_H

#include "UtilityState.h"

class OperationalState : public UtilityState {
public:
    void startProduction(Utility* utility) ;
    std::string getStateName() ;
};

#endif
