#ifndef RESOURCEDEPARTMENT_H
#define RESOURCEDEPARTMENT_H

#include <iostream>
#include <vector>
#include "Resources.h"
#include "Utility.h"
#include "Department.h"


class Utility;

class ResourceDepartment: public Department
{
private:
    std::vector<Resources *> resources; // List of managed resources
    std::vector<Utility *> utilities;  // List of registered utilities
      int totalEnergyDemand;
      int totalWaterDemand;


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

    ResourceDepartment(float budget);

    void processResourceRequest(float amount);
};

#endif // RESOURCEDEPARTMENT_H
