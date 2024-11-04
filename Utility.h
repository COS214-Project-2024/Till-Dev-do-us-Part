/**
 * @file Utility.h
 * @brief Defines the Utility class used in managing utilities in the simulation.
 * @author rethabile
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "Resources.h"
#include "Business.h"
#include "Wellness.h"

class ResourceDepartment;

/**
 * @class Utility
 * @brief Abstract base class for managing various utilities in the simulation.
 */
class Utility
{
protected:
    std::string name;                  ///< Name of the utility
    ResourceDepartment *resDept;       ///< Pointer to the Resource Department
    Resources *resource;               ///< Pointer to the resources used by the utility
    Business *UtilityBus;              ///< Manages worker hiring for the utility
    int MaxWorkers;                    ///< Maximum number of workers the utility can hire
    int ActiveWorkers;                 ///< Currently active workers

public:
    /**
     * @brief Default constructor for Utility.
     */
    Utility();

    /**
     * @brief Parameterized constructor for Utility.
     * @param name Name of the utility
     * @param resDept Pointer to the Resource Department
     * @param resource Pointer to the resources used by the utility
     * @param maxWorkers Maximum number of workers for the utility
     */
    Utility(const std::string &name, ResourceDepartment *resDept, Resources *resource, int maxWorkers);

    /**
     * @brief Virtual destructor for Utility.
     */
    virtual ~Utility();

    /**
     * @brief Sends a notification message to the Resource Department.
     * @param message The message to be sent to the Resource Department
     */
    void notifyResourceDept(const std::string &message);

    /**
     * @brief Gets the name of the utility.
     * @return The name of the utility
     */
    virtual std::string getName() const;

    /**
     * @brief Pure virtual function to get the type of utility.
     * @return The type of utility
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Pure virtual function to get the status of the utility.
     */
    virtual void getStatus() const = 0;

    /**
     * @brief Gets the number of active workers.
     * @return The number of active workers
     */
    int getActiveWorkers() const;

    /**
     * @brief Gets the maximum number of workers.
     * @return The maximum number of workers
     */
    int getMaxWorkers() const;

    /**
     * @brief Gets the resource pointer used by the utility.
     * @return Pointer to the resources used by the utility
     */
    Resources *getResource() const;
};

#endif // UTILITY_H
