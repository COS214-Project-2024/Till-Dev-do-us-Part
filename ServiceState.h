/**
 * @file ServiceState.h
 * @brief Declares the ServiceState class for managing service states of utilities.
 * 
 * The ServiceState class serves as an abstract base class for defining various 
 * service states in the service utility. It outlines the interface that all 
 * concrete service states must implement.
 * 
 * @author Rethabile
 * @date 2023
 */

#ifndef SERVICESTATE_H
#define SERVICESTATE_H

#include <string>

class ServiceUtility; // Forward declaration of ServiceUtility

/**
 * @class ServiceState
 * @brief Abstract base class representing the state of a service utility.
 * 
 * The ServiceState class defines the interface for different service states that 
 * a ServiceUtility can be in. Derived classes must implement the specific behavior 
 * for handling services and provide a name for the state.
 */
class ServiceState 
{
public:
    /**
     * @brief Virtual destructor for the ServiceState class.
     * 
     * Cleans up any resources used by the ServiceState object.
     */
    virtual ~ServiceState() = default;

    /**
     * @brief Handles service operations for the utility in the current state.
     * 
     * Derived classes must implement this method to define how the service 
     * utility behaves when in this specific state.
     * 
     * @param utility A pointer to the ServiceUtility that this state is managing.
     */
    virtual void handleService(ServiceUtility *utility) = 0;

    /**
     * @brief Gets the name of the current service state.
     * 
     * @return A string representation of the state name.
     */
    virtual std::string getStateName() const = 0;

};

#endif // SERVICESTATE_H
