#ifndef OUTAGESERVICESTATE_H
#define OUTAGESERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

class OutageServiceState : public ServiceState {
public:
    void startService(ServiceUtility* utility) override;
    std::string getStateName() const override { return "Outage"; }
};

#endif // OUTAGESERVICESTATE_H
