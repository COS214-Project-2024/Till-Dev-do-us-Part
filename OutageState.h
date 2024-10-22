#ifndef OUTAGESTATE_H
#define OUTAGESTATE_H

#include "UtilityState.h"

class OutageState : public UtilityState {
public:
    void startProduction(Utility* utility);
    std::string getStateName() ;
};

#endif
