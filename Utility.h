/**
 * @file Utility.h
 * @brief Defines the Utility class for managing utility services within the simulation.
 *
 * The Utility class provides an interface for managing various utilities 
 * such as assigning resources, interacting with the resource department, 
 * and managing workers for a particular utility in the city simulation.
 * 
 * @author Rethabile
 * @date 2023
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "ResourceDepartment.h"
#include "Resources.h"
#include "Business.h"
#include "Wellness.h"

// Forward declarations
class ResourceDepartment;

/**
 * @class Utility
 * @brief Represents a base class for utilities in the city simulation.
 * 
 * The Utility class serves as a base class for specific types of utilities 
 * in the simulation, enabling resource management, worker assignment, and 
 * communication with the ResourceDepartment.
 */
class Utility
{
protected:
    std::string name;              ///< Name of the utility.
    ResourceDepartment *resDept;   ///< Pointer to the associated Resource Department.
    Resources *resource;           ///< Pointer to the resources used by the utility.
    Business *UtilityBus;          ///< Business object to manage hiring of workers.
    int MaxWorkers;                ///< Maximum number of workers the utility can hire.
    int ActiveWorkers;             ///< Current number of active workers in the utility.

public:
    /**
     * @brief Default constructor for Utility.
     */
    Utility();

    /**
     * @brief Parameterized constructor for Utility.
     * 
     * @param name Name of the utility.
     * @param resDept Pointer to the Resource Department associated with this utility.
     * @param resource Pointer to the resources managed by this utility.
     * @param maxWorkers Maximum number of workers allowed for the utility.
     */
    Utility(const std::string &name, ResourceDepartment *resDept, Resources *resource, int maxWorkers);

    /**
     * @brief Virtual destructor for Utility.
     */
    virtual ~Utility();

    /**
     * @brief Notifies the Resource Department with a specified message.
     * 
     * Sends a message to the associated Resource Department for communication 
     * regarding resource needs or updates.
     * 
     * @param message The message to send to the Resource Department.
     */
    void notifyResourceDept(const std::string &message);

    /**
     * @brief Gets the name of the utility.
     * 
     * @return A string representing the name of the utility.
     */
    virtual std::string getName() const;

    /**
     * @brief Gets the number of active workers in the utility.
     * 
     * @return The number of active workers.
     */
    int getActiveWorkers() const;

    /**
     * @brief Gets the maximum number of workers allowed in the utility.
     * 
     * @return The maximum number of workers.
     */
    int getMaxWorkers() const;

    /**
     * @brief Retrieves the current status of the utility.
     * 
     * Outputs information about the utility's state, such as resources and worker count.
     */
    virtual void getStatus() const;

    /**
     * @brief Gets the resources managed by the utility.
     * 
     * @return A pointer to the Resources object associated with the utility.
     */
    Resources *getResource() const;
};

#endif // UTILITY_H
