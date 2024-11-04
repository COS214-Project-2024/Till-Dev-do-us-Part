/**
 * @file MaintenanceServiceState.h
 * @brief Defines the maintenance state for service utilities.
 */

#ifndef MAINTENANCESERVICESTATE_H
#define MAINTENANCESERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

/**
 * @class MaintenanceServiceState
 * @brief Represents the maintenance state of a service utility.
 */
class MaintenanceServiceState : public ServiceState {
public:
    /**
     * @brief Handles service operations in the maintenance state.
     * 
     * In this state, the service utility is not operational and may
     * be undergoing repairs, checks, or other maintenance activities.
     * The utility will not process service requests during this time.
     * 
     * @param utility Pointer to the ServiceUtility currently in this state.
     */
    void handleService(ServiceUtility* utility) override;

    /**
     * @brief Retrieves the name of this state.
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "Maintenance"; }
};

#endif // MAINTENANCESERVICESTATE_H
