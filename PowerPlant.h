#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "ProductionUtility.h"
#include "Energy.h"

/**
 * @brief Class representing a power plant that produces energy.
 * 
 * Inherits from ProductionUtility and implements specific production functionality for a power plant.
 */
class PowerPlant : public ProductionUtility
{
private:
    Resources *energy; ///< Pointer to the energy resource

public:
    /**
     * @brief Constructs a PowerPlant object.
     * 
     * @param name The name of the power plant.
     * @param department Pointer to the ResourceDepartment managing the plant.
     * @param resource Pointer to the Energy resource being produced.
     * @param numworkers The number of workers in the plant.
     */
    PowerPlant(std::string name, ResourceDepartment *department, Energy *resource, int numworkers);
    
    /**
     * @brief Destroys the PowerPlant object.
     */
    ~PowerPlant();

    /**
     * @brief Starts the power production process.
     * 
     * This method initiates the production cycle, checking for breakdowns,
     * handling production based on the current operational state, and attempting
     * to restart production if the plant is in an outage state.
     */
    void startProduction() override; // Starts power production
};

#endif // POWERPLANT_H
