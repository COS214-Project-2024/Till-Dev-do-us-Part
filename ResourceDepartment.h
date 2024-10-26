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

////New respurce depta

#include "ResourceDepartment.h"

bool ResourceDepartment::requestElectricity(int amount) {
    if (totalElectricity >= amount) {
        totalElectricity -= amount;
        std::cout << "ResourceDepartment: Allocated " << amount << " units of electricity.\n";
        return true;
    } else {
        std::cout << "ResourceDepartment: Insufficient electricity!\n";
        return false;
    }
}

bool ResourceDepartment::requestWater(int amount) {
    if (totalWater >= amount) {
        totalWater -= amount;
        std::cout << "ResourceDepartment: Allocated " << amount << " units of water.\n";
        return true;
    } else {
        std::cout << "ResourceDepartment: Insufficient water!\n";
        return false;
    }
}

bool ResourceDepartment::manageWaste(int wasteAmount) {
    if (wasteAmount <= totalWasteCapacity) {
        totalWasteCapacity -= wasteAmount;
        std::cout << "ResourceDepartment: Managed " << wasteAmount << " units of waste.\n";
        return true;
    } else {
        std::cout << "ResourceDepartment: Waste capacity exceeded!\n";
        return false;
    }
}

bool ResourceDepartment::manageSewage(int sewageAmount) {
    if (sewageAmount <= totalSewageCapacity) {
        totalSewageCapacity -= sewageAmount;
        std::cout << "ResourceDepartment: Managed " << sewageAmount << " units of sewage.\n";
        return true;
    } else {
        std::cout << "ResourceDepartment: Sewage capacity exceeded!\n";
        return false;
    }
}

// Clears waste for a specific building
void ResourceDepartment::clearWaste(Building* building) {
    int wasteCleared = building->getWasteAmount();
    totalWasteCapacity += wasteCleared; // Assume full capacity after clearing
    building->clearWaste();
    std::cout << "ResourceDepartment: Cleared waste from building.\n";
}

// Clears sewage for a specific building
void ResourceDepartment::clearSewage(Building* building) {
    int sewageCleared = building->getSewageAmount();
    totalSewageCapacity += sewageCleared; // Assume full capacity after clearing
    building->clearSewage();
    std::cout << "ResourceDepartment: Cleared sewage from building.\n";
}

// Add utilities such as power, water supply, waste management, etc.
void ResourceDepartment::addUtility(Utility* utility) {
    utilities.push_back(utility);
}

// Routine update method to simulate scheduled resource management
void ResourceDepartment::update() {
    for (auto utility : utilities) {
        utility->serviceDelivery();
    }
}

