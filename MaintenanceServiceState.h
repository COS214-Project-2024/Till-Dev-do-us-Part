#ifndef MAINTENANCESERVICESTATE_H
#define MAINTENANCESERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

class MaintenanceServiceState : public ServiceState {
public:
    void handleService(ServiceUtility* utility) override;
    std::string getStateName() const override { return "Maintenance"; }
};

#endif // MAINTENANCESERVICESTATE_H
