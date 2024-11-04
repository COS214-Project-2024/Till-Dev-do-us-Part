/**
 * @file FullCapacityServiceState.h
 * @brief Defines the full capacity state for service utilities.
 */

#ifndef FullCapacitySERVICESTATE_H
#define FullCapacitySERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

/**
 * @class FullCapacityServiceState
 * @brief Represents the full capacity state of a service utility.
 */
class FullCapacityServiceState : public ServiceState {
public:
    /**
     * @brief Handles service operations in the full capacity state.
     * 
     * In this state, the service utility is operating at maximum capacity,
     * and appropriate actions should be taken to manage service requests and
     * potential overflow.
     * 
     * @param utility Pointer to the ServiceUtility currently in this state.
     */
    void handleService(ServiceUtility* utility) override;

    /**
     * @brief Retrieves the name of this state.
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "FullCapacity"; }
};

#endif // FullCapacitySERVICESTATE_H
