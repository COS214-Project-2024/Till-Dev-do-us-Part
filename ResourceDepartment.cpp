#include "ResourceDepartment.h"
#include <iostream>

void ResourceDepartment::addUtility(Utility* utility) {
    utilities.push_back(utility);
}

void ResourceDepartment::addResource(Resource* resource) {
    resources.push_back(resource);
}

void ResourceDepartment::addBuilding(Building* building) {
    buildings.push_back(building);
}

void ResourceDepartment::addCitizen(Citizen* citizen) {
    citizens.push_back(citizen);
}

// Utility requests a certain amount of resource
void ResourceDepartment::requestResource(Utility* utility, float amount) {
    Resource* resource = utility->getResource();
    if (allocateResource(resource, amount)) {
        std::cout << "Allocated " << amount << " units of " << resource->getName() 
                  << " to " << utility->getName() << std::endl;
    } else {
        std::cout << "Insufficient resources for " << utility->getName() << ". Initiating outage." << std::endl;
        utility->setState(new OutageState());
        notifyBuildingsUtilityState("Utility outage: " + utility->getName());
        notifyCitizensUtilityState("Utility outage: " + utility->getName(), "angry");
    }
}

// Notify all registered buildings of utility state change
void ResourceDepartment::notifyBuildingsUtilityState(const std::string& message) {
    for (Building* building : buildings) {
        std::cout << "Notifying building: " << building->getType() << " - " << message << std::endl;
    }
}

// Notify all registered citizens of utility state change and update their mood
void ResourceDepartment::notifyCitizensUtilityState(const std::string& message, const std::string& mood) {
    for (Citizen* citizen : citizens) {
        std::cout << "Notifying citizen of utility change: " << message << std::endl;
        citizen->updateMood(mood);
    }
}

// Allocate a certain amount of resource if available
bool ResourceDepartment::allocateResource(Resource* resource, float amount) {
    if (resource->getAvailableAmount() >= amount) {
        resource->consume(amount);
        return true;
    }
    return false;
}

// Release a certain amount of resource back to the pool
void ResourceDepartment::releaseResource(Resource* resource, float amount) {
    resource->replenish(amount);
}

ResourceDepartment::~ResourceDepartment() {
    // Clean-up if necessary (in actual implementation)
}
