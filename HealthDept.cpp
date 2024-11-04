#include "HealthDept.h"
#include <iostream>

/**
 * @brief Constructor to initialize HealthDept with a given budget.
 * @param budget The initial budget for the Health Department.
 */
HealthDept::HealthDept(float budget)
{
    this->budget = budget;
}

/**
 * @brief Adds a healthcare facility to the Health Department.
 * @param name The name of the facility.
 * @param facility Pointer to the HealthcareFacility being added.
 */
void HealthDept::addFacility(std::string name, HealthcareFacility* facility)
{
    if(budget <= 0)
    {
        std::cout << "No budget to build Health Facility\n";
        return;
    }
    facilities[name] = facility;
    budget -= 500; // Deducting a fixed budget amount for now
}

/**
 * @brief Admits a patient to an available healthcare facility.
 * @param c Pointer to the Citizen being admitted.
 */
void HealthDept::admitPatient(Citizen* c)
{
    auto clinicIt = facilities.find("Clinic");
    if (clinicIt != facilities.end())
    {
        HealthcareFacility* clinic = clinicIt->second;
        clinic->admitPatient(c);
        return;
    }
}

/**
 * @brief Calculates and outputs the total death toll across all facilities.
 */
void HealthDept::totalDeaths()
{
    int totalDeaths = 0;
    for(auto& facilityPair : facilities)
    {
        HealthcareFacility* facility = facilityPair.second;
        totalDeaths += facility->getDeathToll();
    }
    std::cout << "The Health Department has reported a total death toll of " << totalDeaths << " in 2024\n\n";
}

/**
 * @brief Destructor for HealthDept, responsible for cleaning up resources.
 */
HealthDept::~HealthDept()
{
    for (auto& facilityPair : facilities)
    {
        // Deletion logic if needed
    }
    facilities.clear(); // Clear the map of facilities
}
