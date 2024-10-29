#ifndef SERVICESTATE_H
#define SERVICESTATE_H

#include "UtilityState.h"

class ServiceUtility;

class ServiceState : public UtilityState
{
public:
    virtual ~ServiceState() = default;

    // Service-specific behavior for this state
    virtual void startService(ServiceUtility *utility) = 0;

};

#endif