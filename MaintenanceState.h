#ifndef MAINTENANCESTATE_H
#define MAINTENANCESTATE_H

#include "UtilityState.h"

class MaintenanceState : public UtilityState {
public:
    void startProduction(Utility* utility);
    std::string getStateName() ;
};

#endif
