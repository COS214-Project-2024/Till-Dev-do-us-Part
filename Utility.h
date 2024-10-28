#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <random>
#include "Resources.h"
#include "UtilityState.h"
#include "ResourceDepartment.h"

class Utility {
private:
    std::string name;
    ResourceDepartment* resourceDepartment; // Pointer to ResourceDepartment
    Resources* resource;
    UtilityState* currentState;
    float totalProduction;
    float currentProduction;
    float revenue;
    float totalDemand;
    int workers;

public:
    // Constructors and Destructor
    Utility();
    Utility(std::string name, ResourceDepartment* resourceDepartment, Resources* resource, float totalProduction, int workers);
    ~Utility();

    // Production and State Management
    void startProduction();
    void setState(UtilityState* newState);

    // Resource Requests and Breakdown Handling
    void requestResource(float amount);
    void checkForBreakdowns();
    void notifyResourceDivision(const std::string& message);

    // Getters and Setters
    float getTotalProduction() const;
    void setCurrentProduction(float production);
    float getCurrentProduction() const;
    Resources* getResource() const;
    int getWorkers() const;
    std::string getName() const;
};

#endif // UTILITY_H
