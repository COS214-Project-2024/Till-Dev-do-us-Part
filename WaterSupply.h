#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "ProductionUtility.h"
#include "Water.h"

/**
 * @brief Class representing a water supply utility that produces and manages water resources.
 * 
 * Inherits from ProductionUtility and implements specific production functionality for water supply.
 */
class WaterSupply : public ProductionUtility {
private:
    Resources *water; ///< Pointer to the water resource

public:
    /**
     * @brief Constructs a WaterSupply object.
     * 
     * @param name The name of the water supply utility.
     * @param department Pointer to the ResourceDepartment managing the utility.
     * @param resource Pointer to the Water resource being produced.
     * @param numworkers The number of workers in the utility.
     */
    WaterSupply(std::string name, ResourceDepartment *department, Water *resource, int numworkers);
    
    /**
     * @brief Destroys the WaterSupply object.
     */
    ~WaterSupply();

    /**
     * @brief Starts the water production process.
     * 
     * This method initiates the production cycle, managing the state of the water supply utility.
     */
    void startProduction() override; // Starts water production
};

#endif // WATERSUPPLY_H
