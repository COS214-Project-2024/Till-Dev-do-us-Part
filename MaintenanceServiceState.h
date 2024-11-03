#ifndef MAINTENANCESERVICESTATE_H
#define MAINTENANCESERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

/**
 * @brief Class representing the maintenance state of a service utility.
 * 
 * Inherits from ServiceState and defines behavior specific to maintenance.
 */
class MaintenanceServiceState : public ServiceState {
public:
    /**
     * @brief Handles service operations while in maintenance state.
     * 
     * @param utility Pointer to the ServiceUtility that is in maintenance.
     */
    void handleService(ServiceUtility* utility) override;

    /**
     * @brief Gets the name of the state.
     * 
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "Maintenance"; }
};

#endif // MAINTENANCESERVICESTATE_H
