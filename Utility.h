#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "UtilityState.h"
#include "ResourceDepartment.h"


class UtilityState;

class Utility {
protected:
    std::string name;
    float totalProduction;
    float currentProduction;
    float totalDemand;
    float revenue;
    int workers;

    Resource* resource; // Link to the resource being managed (e.g., energy, water)
    UtilityState* currentState; // Current state of the utility

    

public:
    Utility(std::string name, Resource* resource, float totalProduction, int workers);
    virtual ~Utility();

    // State-related behavior
    void startProduction();

    // Handle breakdowns
    void checkForBreakdowns();

    // Change the current state of the utility
    void setState(UtilityState* newState);

    // Getters and Setters for Utility Data
    float getTotalProduction() const;
    void setCurrentProduction(float production);
    float getCurrentProduction() const;
    Resource* getResource() const;
    int getWorkers() const;

    // Interactions with Resources
    void requestResource(float amount);
    void notifyResourceDivision(const std::string& message);

    // Overridable function for specific utilities like PowerPlant
    virtual void serviceDelivery() = 0;
};

#endif
