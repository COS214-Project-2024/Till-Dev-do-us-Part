/**
 * @file ServiceUtility.h
 * @brief Declares the ServiceUtility class for managing service operations.
 * 
 * The ServiceUtility class extends the Utility class and provides functionality 
 * for managing service operations and states within the system. It serves as an 
 * aggregate for various service-related functionalities.
 * 
 * @author Rethabile
 * @date 2023
 */

#ifndef SERVICEUTILITY_H
#define SERVICEUTILITY_H

#include "Utility.h"
#include "ServiceState.h"
#include "DevelopmentDept.h"
// #include "BuildingIterator.h"
#include "OperationalServiceState.h"

/**
 * @class ServiceUtility
 * @brief Manages service operations and state transitions for service utilities.
 * 
 * The ServiceUtility class defines an interface for managing service capacities, 
 * current service levels, and handling various service states for a utility.
 */
class ServiceUtility : public Utility
{
protected:
    // std::vector<Building *> buildings; // Pointer to buildings managed by the ServiceUtility
    // BuildingIterator iterator; // Iterator for processing buildings
    float serviceCapacity;        ///< The maximum service capacity of the utility.
    float currentServiceLevel;    ///< The current level of service being provided.
    ServiceState *servState;      ///< Pointer to the current service state.

public:
    /**
     * @brief Constructs a ServiceUtility object with specified parameters.
     * 
     * Initializes the service utility with a name and a pointer to the resource department.
     * 
     * @param name The name of the service utility.
     * @param resDept A pointer to the associated Resource Department.
     */
    ServiceUtility(std::string name, ResourceDepartment *resDept);

    /**
     * @brief Virtual destructor for the ServiceUtility class.
     * 
     * Cleans up any resources used by the ServiceUtility object.
     */
    virtual ~ServiceUtility();

    // Service operations

    /**
     * @brief Starts the service operations for the utility.
     * 
     * This is a pure virtual function that must be implemented by derived classes 
     * to define the specific behavior of starting service operations.
     */
    virtual void startService() = 0;

    /**
     * @brief Processes a service request.
     * 
     * Handles incoming requests related to service operations.
     */
    void processRequest();

    // Getters and setters for service attributes

    /**
     * @brief Gets the service capacity of the utility.
     * 
     * @return The maximum service capacity as a float.
     */
    float getServiceCap() const;

    /**
     * @brief Sets the service capacity of the utility.
     * 
     * @param capacity The new service capacity to set.
     */
    void setServiceCap(float capacity);

    /**
     * @brief Gets the current service level.
     * 
     * @return The current service level as a float.
     */
    float getCurrentServiceLevel() const;

    /**
     * @brief Sets the current service level.
     * 
     * @param level The new service level to set.
     */
    void setCurrentServiceLevel(float level);

    // State management

    /**
     * @brief Gets the current service state as a string.
     * 
     * @return A string representation of the current service state.
     */
    std::string getServState() const;

    /**
     * @brief Sets the service state to a new state.
     * 
     * Deletes the previous service state and assigns a new one.
     * 
     * @param state A pointer to the new ServiceState to set.
     */
    void setServState(ServiceState *state);

    /**
     * @brief Retrieves and displays the current status of the service utility.
     * 
     * Outputs information about service capacity, current service level, 
     * and the current state to the console.
     */
    void getStatus() const override;

    /**
     * @brief Gets the service capacity as an integer.
     * 
     * @return The current service capacity as an integer.
     */
    int getCapacity() const;
    
    /**
     * @brief Creates a Development Department instance.
     * 
     * This is a pure virtual function that must be implemented by derived classes 
     * to provide specific development department functionality.
     * 
     * @return A pointer to the created DevelopmentDept object.
     */
    virtual DevelopmentDept* createDevelopmentDept() = 0;
};

#endif // SERVICEUTILITY_H
