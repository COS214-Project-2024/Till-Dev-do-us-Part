#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>
#include <string>
#include "UtilityState.h"
#include "Resource.h"
#include "Building.h"
#include "Citizen.h"

// Forward declarations for state classes
class UtilityState;
class OperationalState;
class MaintenanceState;
class OutageState;

class Utility {
private:
    std::string name;
    float totalProduction;
    float currentProduction;
    float totalDemand;
    float revenue;
    int workers;

    Resource* resource; // Link to the resource being managed (e.g., energy, water)

    // Current state of the utility
    UtilityState* currentState;

    std::vector<Building*> connectedBuildings; // Buildings connected to this utility
    std::vector<Citizen*> affectedCitizens;    // Citizens affected by this utility

public:
    Utility(std::string name, Resource* resource, float totalProduction, int workers);
    ~Utility();

    // State-related behavior
    void startProduction();

    // Change the current state of the utility
    void setState(UtilityState* newState);

    // Getters and Setters for Utility Data
    float getTotalProduction() const;
    void setCurrentProduction(float production);
    float getCurrentProduction() const;
    Resource* getResource() const;
    int getWorkers() const;
};

#endif
