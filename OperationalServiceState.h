/**
 * @file OperationalServiceState.h
 * @brief Defines the operational state for service utilities.
 */

#ifndef OPERATIONALSERVICESTATE_H
#define OPERATIONALSERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

/**
 * @class OperationalServiceState
 * @brief Represents the operational state of a service utility.
 */
class OperationalServiceState : public ServiceState {
public:
    /**
     * @brief Handles service processes in the operational state.
     * 
     * This method manages the operations of the service utility, including
     * processing buildings if applicable.
     * 
     * @param utility Pointer to the ServiceUtility currently in this state.
     */
    void handleService(ServiceUtility* utility) override;

    /**
     * @brief Retrieves the name of this state.
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "Operational"; }
};

#endif // OPERATIONALSERVICESTATE_H
