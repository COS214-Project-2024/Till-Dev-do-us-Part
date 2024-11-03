/**
 * @file ProductionUtility.h
 * @brief Declares the ProductionUtility class for managing production-related utilities.
 *
 * The ProductionUtility class is derived from the Utility class and provides an interface 
 * for managing production operations, including handling production states and 
 * processing production requests within the city simulation.
 * 
 * @author Rethabile
 * @date 2023
 */

#ifndef PRODUCTIONUTILITY_H
#define PRODUCTIONUTILITY_H

#include <memory>
#include "Utility.h"
#include "ProductionState.h"
#include "OperationalProductionState.h"
#include <thread>       // For sleep_for
#include <chrono>
#include "MaintenanceProductionState.h"
#include "OutageProductionState.h"

/**
 * @class ProductionUtility
 * @brief Manages production operations and state transitions for production utilities.
 * 
 * The ProductionUtility class extends the Utility class by providing specific 
 * functionality for managing production capacity, current production levels, 
 * and handling production states.
 */
class ProductionUtility : public Utility
{
protected:
    float productionCapacity;      ///< The maximum production capacity of the utility.
    float currentProduction;       ///< The current level of production.
    ProductionState* proState;     ///< Pointer to the current production state.

public:
    /**
     * @brief Constructs a ProductionUtility object with specified parameters.
     * 
     * Initializes the production utility with a name, a pointer to the resource department,
     * a pointer to the resources it will use, and the maximum number of workers.
     * 
     * @param name The name of the production utility.
     * @param resDept A pointer to the associated Resource Department.
     * @param resource A pointer to the resources managed by this utility.
     * @param maxWorkers The maximum number of workers that can be hired for the utility.
     */
    ProductionUtility(std::string name, ResourceDepartment *resDept, Resources *resource, int maxWorkers);

    /**
     * @brief Virtual destructor for the ProductionUtility class.
     * 
     * Cleans up any resources used by the ProductionUtility object.
     */
    virtual ~ProductionUtility();

    // Production operations

    /**
     * @brief Starts the production process.
     * 
     * This is a pure virtual function that must be implemented by derived classes 
     * to define the specific behavior of starting production.
     */
    virtual void startProduction() = 0;

    /**
     * @brief Processes a production request.
     * 
     * Handles incoming requests related to production, including managing state transitions 
     * and adjusting production levels.
     */
    void processRequest();

    // Getters and setters for production attributes

    /**
     * @brief Gets the production capacity of the utility.
     * 
     * @return The maximum production capacity as a float.
     */
    float getProductionCapacity() const;

    /**
     * @brief Sets the production capacity of the utility.
     * 
     * @param capacity The new production capacity to set.
     */
    void setProductionCapacity(float capacity);

    /**
     * @brief Gets the current production level.
     * 
     * @return The current production level as a float.
     */
    float getCurrentProduction() const;

    /**
     * @brief Sets the current production level.
     * 
     * @param production The new production level to set.
     */
    void setCurrentProduction(float production);

    // State management

    /**
     * @brief Gets the current production state as a string.
     * 
     * @return A string representation of the current production state.
     */
    std::string getProState() const;

    /**
     * @brief Sets the production state to a new state.
     * 
     * @param state A pointer to the new ProductionState to set.
     */
    void setProState(ProductionState *state);

    /**
     * @brief Retrieves and displays the current status of the production utility.
     * 
     * Outputs information about production capacity, current production, and state.
     */
    void getStatus() const override;

    /**
     * @brief Checks for breakdowns in the production process.
     * 
     * Monitors the production utility for potential breakdowns and handles them
     * according to the utility's operational procedures.
     */
    void checkForBreakdowns();
};

#endif // PRODUCTIONUTILITY_H
