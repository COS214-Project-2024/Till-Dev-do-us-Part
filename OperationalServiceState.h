#ifndef OPERATIONALSERVICESTATE_H
#define OPERATIONALSERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

class OperationalServiceState : public ServiceState {
public:
    void handleService(ServiceUtility* utility) override;
    std::string getStateName() const override;
    
};

#endif // OPERATIONALSERVICESTATE_H
