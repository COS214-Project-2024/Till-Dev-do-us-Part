/**
 * @file ResourceDepartment.h
 * @brief Defines the ResourceDepartment class responsible for managing resources and utilities in the simulation.
 */

#ifndef RESOURCEDEPARTMENT_H
#define RESOURCEDEPARTMENT_H

#include <iostream>
#include <vector>
#include "Resources.h"
#include "ProductionUtility.h"
#include "Department.h"

class Utility;  // Forward declaration

/**
 * @class ResourceDepartment
 * @brief Manages resources and utilities within the city simulation.
 */
class ResourceDepartment : public Department
{
private:
    std::vector<Resources *> resources; // List of managed resources
    std::vector<Utility *> utilities;   // List of registered utilities
    float budget;                       // Budget for the department

public:
    // Constructors and Destructor
    ResourceDepartment() = default; // Default constructor
    ResourceDepartment(float budget); // Constructor with budget
    ~ResourceDepartment(); // Destructor

    // Resource Management
    void addResource(Resources *resource);
    bool hasSufficientResource(Resources *resource, float amount);
    void consumeResource(Resources *resource, float amount);
    void releaseResource(Resources *resource, float amount);

    // Utility Management
    void addUtility(Utility *utility);
    void notifyUtilityOutage(const std::string &message);

    // Utility-State Notifications
    void updateUtilities();

    // Check total resource levels
    void checkResourceLevels();

    // Process resource requests from utilities
    bool processResourceRequest(std::string utiName, float amount);
};

#endif // RESOURCEDEPARTMENT_H
