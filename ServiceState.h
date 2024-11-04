/**
 * @file ServiceState.h
 * @brief Defines the ServiceState interface for service utilities.
 */

#ifndef SERVICESTATE_H
#define SERVICESTATE_H

#include <string>

class ServiceUtility;

/**
 * @class ServiceState
 * @brief Abstract base class for defining different service states.
 */
class ServiceState 
{
public:
    virtual ~ServiceState() = default;

    /**
     * @brief Handles service behavior specific to this state.
     * @param utility Pointer to the ServiceUtility that is in this state.
     */
    virtual void handleService(ServiceUtility *utility) = 0;

    /**
     * @brief Retrieves the name of the state.
     * @return A string representing the state name.
     */
    virtual std::string getStateName() const = 0;
};

#endif // SERVICESTATE_H
