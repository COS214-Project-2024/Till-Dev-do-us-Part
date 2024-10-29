#ifndef OPERATIONALSERVICESTATE_H
#define OPERATIONALSERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

class OperationalServiceState : public ServiceState {
public:
    void startService(ServiceUtility* utility) override;
    std::string getStateName() const override { return "Operational"; }
};

#endif // OPERATIONALSERVICESTATE_H
