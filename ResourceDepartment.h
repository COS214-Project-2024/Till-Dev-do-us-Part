#ifndef RESOURCEDEPARTMENT_H
#define RESOURCEDEPARTMENT_H

#include <iostream>
#include <vector>
#include "Resources.h"
#include "Utility.h"
#include "Department.h"

/**
 * @brief Class representing a resource department managing resources and utilities.
 * 
 * This department is responsible for handling resource allocation, monitoring resource levels,
 * and managing utilities that depend on these resources.
 */
class ResourceDepartment : public Department
{
private:
    std::vector<Resources *> resources; ///< List of managed resources
    std::vector<Utility *> utilities;    ///< List of registered utilities
    int totalEnergyDemand;                ///< Total energy demand across utilities
    int totalWaterDemand;                 ///< Total water demand across utilities

public:
    // Constructors and Destructor
    ResourceDepartment() = default;       ///< Default constructor
    ResourceDepartment(float budget);      ///< Parameterized constructor
    ~ResourceDepartment();                 ///< Destructor

    // Resource Management
    /**
     * @brief Adds a resource to the department's management.
     * 
     * @param resource Pointer to the resource to be added.
     */
    void addResource(Resources *resource);

    /**
     * @brief Checks if sufficient resources are available.
     * 
     * @param resource Pointer to the resource to check.
     * @param amount The amount needed.
     * @return true if sufficient resources are available, false otherwise.
     */
    bool hasSufficientResource(Resources *resource, float amount);

    /**
     * @brief Consumes a specified amount of a resource.
     * 
     * @param resource Pointer to the resource to consume.
     * @param amount The amount to consume.
     */
    void consumeResource(Resources *resource, float amount);

    /**
     * @brief Releases a specified amount of a resource back to the pool.
     * 
     * @param resource Pointer to the resource to release.
     * @param amount The amount to release.
     */
    void releaseResource(Resources *resource, float amount);

    // Utility Management
    /**
     * @brief Registers a utility with the resource department.
     * 
     * @param utility Pointer to the utility to be registered.
     */
    void addUtility(Utility *utility);

    /**
     * @brief Notifies all registered utilities about an outage.
     * 
     * @param message The message to send to utilities.
     */
    void notifyUtilityOutage(const std::string &message);

    // Utility-State Notifications
    /**
     * @brief Updates all registered utilities about the current resource state.
     */
    void updateUtilities();

    // Check total resource levels
    /**
     * @brief Checks the current levels of all managed resources.
     */
    void checkResourceLevels();

    /**
     * @brief Processes a resource request from a utility.
     * 
     * @param utiName The name of the utility requesting the resource.
     * @param amount The amount of resource requested.
     * @return true if the request was successfully processed, false otherwise.
     */
    bool processResourceRequest(std::string utiName, float amount);
};

#endif // RESOURCEDEPARTMENT_H
