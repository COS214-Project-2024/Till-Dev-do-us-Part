#ifndef RESOURCEDEPARTMENT_H
#define RESOURCEDEPARTMENT_H

#include <iostream>
#include <vector>
#include "Resources.h"
#include "Utility.h"

class ResourceDepartment
{
private:
    std::vector<Resources *> resources; // List of managed resources
    std::vector<Utility *> utilities;  // List of registered utilities

public:
    // Constructor and Destructor
    ResourceDepartment() = default;
    ~ResourceDepartment();

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
};

#endif // RESOURCEDEPARTMENT_H
