/**
 * @file ProductionUtility.h
 * @brief Defines the ProductionUtility class for managing production-oriented utilities in the simulation.
 */

#ifndef PRODUCTIONUTILITY_H
#define PRODUCTIONUTILITY_H

#include <memory>
#include "Utility.h"
#include "ProductionState.h"
#include "OperationalProductionState.h"
#include <thread>
#include <chrono>
#include "MaintenanceProductionState.h"
#include "OutageProductionState.h"

/**
 * @class ProductionUtility
 * @brief Manages production-related utilities, handling production capacity, levels, and state transitions.
 */
class ProductionUtility : public Utility
{
protected:
    float productionCapacity;           ///< Production capacity of the utility
    float currentProduction;            ///< Current production level
    ProductionState *proState;          ///< Pointer to the current production state
    int requestCounter = 0;             ///< Counter for requests processed

public:
    /**
     * @brief Constructs a ProductionUtility with the specified name, Resource Department, resource, and worker limit.
     * @param name Name of the production utility
     * @param resDept Pointer to the Resource Department
     * @param resource Pointer to the resources used by the utility
     * @param maxWorkers Maximum number of workers allowed
     */
    ProductionUtility(std::string name, ResourceDepartment *resDept, Resources *resource, int maxWorkers,WiseBucks* app);

    /**
     * @brief Default destructor for ProductionUtility.
     */
    virtual ~ProductionUtility();

    // Production operations

    /**
     * @brief Pure virtual function to start production; must be implemented by derived classes.
     */
    virtual void startProduction() = 0;

    /**
     * @brief Processes a production request.
     */
    void processRequest();

    // Getters and setters for production attributes

    /**
     * @brief Gets the production capacity.
     * @return The production capacity
     */
    float getProductionCapacity() const;

    /**
     * @brief Sets the production capacity.
     * @param capacity New production capacity
     */
    void setProductionCapacity(float capacity);

    /**
     * @brief Gets the current production level.
     * @return The current production level
     */
    float getCurrentProduction() const;

    /**
     * @brief Sets the current production level.
     * @param production New production level
     */
    void setCurrentProduction(float production);

    // State management

    /**
     * @brief Gets the current state of the production utility.
     * @return The name of the current production state
     */
    std::string getProState() const;

    /**
     * @brief Sets the production state.
     * @param state New state for the production
     */
    void setProState(ProductionState *state);

    /**
     * @brief Prints the current status of the production utility.
     */
    void getStatus() const override;

    /**
     * @brief Pure virtual function to get the product produced; must be implemented by derived classes.
     * @return The name of the product produced
     */
    virtual std::string getProduct() const = 0;

    /**
     * @brief Gets the type of utility.
     * @return The type of utility as a string
     */
    std::string getType() const override;

    /**
     * @brief Checks for potential breakdowns in the production utility.
     */
    void checkForBreakdowns();

    /**
     * @brief Increments the request counter.
     */
    void incrementRequestCounter();
    void resetRequestCounter();
};

#endif // PRODUCTIONUTILITY_H
