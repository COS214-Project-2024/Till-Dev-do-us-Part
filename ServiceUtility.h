/**
 * @file ServiceUtility.h
 * @brief Defines the ServiceUtility class for managing service-oriented utilities in the simulation.
 * @author rethabile
 */

#ifndef SERVICEUTILITY_H
#define SERVICEUTILITY_H

#include "Utility.h"
#include "ServiceState.h"
#include "DevelopmentDept.h"
#include "OperationalServiceState.h"
#include "ResourceDepartment.h"

/**
 * @class ServiceUtility
 * @brief Manages service-related utilities, handling service capacity, level, and state transitions.
 */
class ServiceUtility : public Utility
{
protected:
    float serviceCapacity;         ///< Capacity of the service utility
    float currentServiceLevel;     ///< Current service level
    ServiceState *servState;       ///< Pointer to the current service state

public:
    /**
     * @brief Constructs a ServiceUtility with the specified name and Resource Department.
     * @param name Name of the service utility
     * @param resDept Pointer to the Resource Department
     */
    ServiceUtility(std::string name, ResourceDepartment *resDept,WiseBucks* app);

    /**
     * @brief Default destructor for ServiceUtility.
     */
    virtual ~ServiceUtility();

    // Service operations

    /**
     * @brief Pure virtual function to start the service; must be implemented by derived classes.
     */
    virtual void startService() = 0;

    /**
     * @brief Processes service requests.
     */
    void processRequest();

    // Getters and setters for service attributes

    /**
     * @brief Gets the service capacity.
     * @return The service capacity
     */
    float getServiceCap() const;

    /**
     * @brief Sets the service capacity.
     * @param capacity New capacity for the service
     */
    void setServiceCap(float capacity);

    /**
     * @brief Gets the current service level.
     * @return The current service level
     */
    float getCurrentServiceLevel() const;

    /**
     * @brief Sets the current service level.
     * @param level New service level
     */
    void setCurrentServiceLevel(float level);

    // State management

    /**
     * @brief Gets the current state of the service utility.
     * @return The name of the current service state
     */
    std::string getServState() const;

    /**
     * @brief Sets the service state.
     * @param state New state for the service
     */
    void setServState(ServiceState *state);

    /**
     * @brief Prints the current status of the service utility.
     */
    void getStatus() const override;

    /**
     * @brief Gets the total service capacity as an integer.
     * @return The service capacity
     */
    int getCapacity() const;

    /**
     * @brief Pure virtual function to create a Development Department; must be implemented by derived classes.
     * @return Pointer to the newly created Development Department
     */
    virtual DevelopmentDept* createDevelopmentDept() = 0;

    /**
     * @brief Gets the type of utility.
     * @return The type of utility as a string
     */
    std::string getType() const override;
};

#endif // SERVICEUTILITY_H
