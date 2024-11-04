/**
 * @file ProductionUtility.cpp
 * @brief Implements the ProductionUtility class methods for managing production-oriented utilities in the simulation.
 */

#include "ProductionUtility.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

/**
 * @brief Constructs a ProductionUtility with specified name, Resource Department, resource, and worker limit.
 * @param name Name of the production utility
 * @param resDept Pointer to the Resource Department
 * @param resource Pointer to the resources used by the utility
 * @param MaxWorkers Maximum number of workers allowed
 */
ProductionUtility::ProductionUtility(std::string name, ResourceDepartment *resDept, Resources *resource, int MaxWorkers)
    : Utility(name, resDept, resource, MaxWorkers), currentProduction(0), proState(nullptr)
{
}

/**
 * @brief Default destructor for ProductionUtility.
 */
ProductionUtility::~ProductionUtility() = default;

/**
 * @brief Processes a production request.
 */
void ProductionUtility::processRequest()
{
    std::cout << "Processing production request..." << std::endl;
    // Logic to process production request
}

/**
 * @brief Gets the production capacity.
 * @return The production capacity
 */
float ProductionUtility::getProductionCapacity() const { return productionCapacity; }

/**
 * @brief Sets the production capacity.
 * @param capacity New production capacity
 */
void ProductionUtility::setProductionCapacity(float capacity) { productionCapacity = capacity; }

/**
 * @brief Gets the current production level.
 * @return The current production level
 */
float ProductionUtility::getCurrentProduction() const { return currentProduction; }

/**
 * @brief Sets the current production level.
 * @param production New production level
 */
void ProductionUtility::setCurrentProduction(float production) { currentProduction = production; }

/**
 * @brief Gets the current state of the production utility.
 * @return The name of the current production state
 */
std::string ProductionUtility::getProState() const
{
    return (proState) ? proState->getStateName() : "No state";
}

/**
 * @brief Sets the production state.
 * @param state New state for the production
 */
void ProductionUtility::setProState(ProductionState *state)
{
    delete proState;
    proState = state;
}

/**
 * @brief Prints the current status of the production utility.
 */
void ProductionUtility::getStatus() const
{
    std::cout << "----------------Utility Status -------------------" << std::endl;
    std::cout << "1. Utility Name                    : " << name << std::endl;
    std::cout << "2. Status                          : " << proState->getStateName() << std::endl;
    std::cout << "   - Total Capacity                : " << productionCapacity << " units of " << getProduct() << std::endl;
    std::cout << "   - Current Production            : " << currentProduction << " units of " << getProduct() << std::endl;
    std::cout << "3. Revenue                         : " << 1000000 << std::endl;
    std::cout << "4. Active Workers                  : " << ActiveWorkers << "/" << MaxWorkers << " workers" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}

/**
 * @brief Checks for potential breakdowns in the production utility.
 * If a breakdown occurs, it transitions to Maintenance State.
 */
void ProductionUtility::checkForBreakdowns()
{
    // Seed the random generator (should be done once, ideally in a constructor or main function)
    static bool seeded = false;
    if (!seeded)
    {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }

    // Randomly decide if a breakdown occurs (e.g., 10% chance)
    int chance = rand() % 100; // Generates a number between 0 and 99
    if (chance < 10) // 10% chance of breakdown
    {
        std::cout << name << " has broken down and is entering Maintenance State." << std::endl;

        // Change state to Maintenance
        setProState(new MaintenanceProductionState());
    }
    else
    {
        std::cout << name << " is functioning normally." << std::endl;
    }
}

/**
 * @brief Gets the type of utility.
 * @return The type of utility as a string
 */
std::string ProductionUtility::getType() const
{
    return "Production";
}

/**
 * @brief Increments the request counter and checks status report criteria.
 */
void ProductionUtility::incrementRequestCounter()
{
    requestCounter++;
    if (requestCounter >= 50)
    {
        requestCounter = 0; // Reset counter
        std::cout << "\n=== Utility Status Report ===" << std::endl;
        getStatus();
    }
}
