#ifndef FULLCAPACITYSERVICESTATE_H
#define FULLCAPACITYSERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

/**
 * @brief Class representing the full capacity state of a service.
 * 
 * Inherits from ServiceState and implements specific service handling when at full capacity.
 */
class FullCapacityServiceState : public ServiceState {
public:
    /**
     * @brief Handles service requests in the full capacity state.
     * 
     * @param utility Pointer to the ServiceUtility managing the service.
     */
    void handleService(ServiceUtility* utility) override;

    /**
     * @brief Retrieves the name of this service state.
     * 
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "FullCapacity"; }
};

#endif // FULLCAPACITYSERVICESTATE_H
