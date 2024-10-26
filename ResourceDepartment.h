#ifndef RESOURCEDEPARTMENT_H
#define RESOURCEDEPARTMENT_H

#include <vector>
#include "Utility.h"
#include "Resource.h"
#include "Building.h"
#include "Citizen.h"

class ResourceDepartment {
private:
    std::vector<Utility*> utilities;
    std::vector<Resource*> resources;
    std::vector<Building*> buildings;
    std::vector<Citizen*> citizens;

public:
    ResourceDepartment() = default;

    // Register utilities, resources, buildings, and citizens with the department
    void addUtility(Utility* utility);
    void addResource(Resource* resource);
    void addBuilding(Building* building);
    void addCitizen(Citizen* citizen);

    // Communication Methods
    void requestResource(Utility* utility, float amount);
    void notifyBuildingsUtilityState(const std::string& message);
    void notifyCitizensUtilityState(const std::string& message, const std::string& mood);

    // Manage resource allocation
    bool allocateResource(Resource* resource, float amount);
    void releaseResource(Resource* resource, float amount);

    // Clean up
    ~ResourceDepartment();
};

#endif
