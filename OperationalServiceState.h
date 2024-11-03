#ifndef OPERATIONALSERVICESTATE_H
#define OPERATIONALSERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

/**
 * @brief Class representing the operational state of a service utility.
 * 
 * Inherits from ServiceState and defines behavior specific to operational services.
 */
class OperationalServiceState : public ServiceState {
public:
    /**
     * @brief Handles service operations while in the operational state.
     * 
     * @param utility Pointer to the ServiceUtility that is operational.
     */
    void handleService(ServiceUtility* utility) override;

    /**
     * @brief Gets the name of the state.
     * 
     * @return A string representing the state name.
     */
    std::string getStateName() const override;
};

#endif // OPERATIONALSERVICESTATE_H
