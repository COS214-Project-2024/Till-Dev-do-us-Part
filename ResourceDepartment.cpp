// #include "ResourceDepartment.h"
// #include <iostream>

// void ResourceDepartment::addUtility(Utility* utility) {
//     utilities.push_back(utility);
// }

// void ResourceDepartment::addResource(Resource* resource) {
//     resources.push_back(resource);
// }

// void ResourceDepartment::addBuilding(Building* building) {
//     buildings.push_back(building);
// }

// void ResourceDepartment::addCitizen(Citizen* citizen) {
//     citizens.push_back(citizen);
// }

// // Utility requests a certain amount of resource
// void ResourceDepartment::requestResource(Utility* utility, float amount) {
//     Resource* resource = utility->getResource();
//     if (allocateResource(resource, amount)) {
//         std::cout << "Allocated " << amount << " units of " << resource->getName() 
//                   << " to " << utility->getName() << std::endl;
//     } else {
//         std::cout << "Insufficient resources for " << utility->getName() << ". Initiating outage." << std::endl;
//         utility->setState(new OutageState());
//         notifyBuildingsUtilityState("Utility outage: " + utility->getName());
//         notifyCitizensUtilityState("Utility outage: " + utility->getName(), "angry");
//     }
// }

// // Notify all registered buildings of utility state change
// void ResourceDepartment::notifyBuildingsUtilityState(const std::string& message) {
//     for (Building* building : buildings) {
//         std::cout << "Notifying building: " << building->getType() << " - " << message << std::endl;
//     }
// }

// // Notify all registered citizens of utility state change and update their mood
// void ResourceDepartment::notifyCitizensUtilityState(const std::string& message, const std::string& mood) {
//     for (Citizen* citizen : citizens) {
//         std::cout << "Notifying citizen of utility change: " << message << std::endl;
//         citizen->updateMood(mood);
//     }
// }

// // Allocate a certain amount of resource if available
// bool ResourceDepartment::allocateResource(Resource* resource, float amount) {
//     if (resource->getAvailableAmount() >= amount) {
//         resource->consume(amount);
//         return true;
//     }
//     return false;
// }

// // Release a certain amount of resource back to the pool
// void ResourceDepartment::releaseResource(Resource* resource, float amount) {
//     resource->replenish(amount);
// }

// ResourceDepartment::~ResourceDepartment() {
//     // Clean-up if necessary (in actual implementation)
// }

//// New Resource department
class ResourceDepartment {
private:
    std::vector<Utility*> utilities;   // List of utility services (e.g., Power, Water)
    int totalElectricity;              // Total electricity available
    int totalWater;                    // Total water available
    int totalWasteCapacity;            // Total capacity for waste management
    int totalSewageCapacity;           // Total capacity for sewage management

public:
    ResourceDepartment(int electricity, int water, int wasteCapacity, int sewageCapacity)
        : totalElectricity(electricity), totalWater(water), totalWasteCapacity(wasteCapacity), totalSewageCapacity(sewageCapacity) {}

    // Methods to request resources for a building
    bool requestElectricity(int amount);
    bool requestWater(int amount);
    bool manageWaste(int wasteAmount);
    bool manageSewage(int sewageAmount);

    // Methods to clear waste and sewage
    void clearWaste(Building* building);
    void clearSewage(Building* building);

    // Regular update cycle for resource management
    void update();

    // Register and manage utilities
    void addUtility(Utility* utility);
};

#endif

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
