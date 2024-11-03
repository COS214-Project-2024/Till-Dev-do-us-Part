/**
 * @file ProductionUtility.cpp
 * @brief Implements the ProductionUtility class for managing production operations.
 * 
 * This file contains the definitions for the ProductionUtility class, including 
 * methods for processing requests, managing production states, and handling breakdowns.
 * 
 * @see ProductionUtility.h for class declarations.
 */

#include "ProductionUtility.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

/**
 * @brief Constructs a ProductionUtility object with specified parameters.
 * 
 * Initializes the production utility with a name, a pointer to the resource department,
 * a pointer to the resources it will use, and the maximum number of workers.
 * 
 * @param name The name of the production utility.
 * @param resDept A pointer to the associated Resource Department.
 * @param resource A pointer to the resources managed by this utility.
 * @param MaxWorkers The maximum number of workers that can be hired for the utility.
 */
ProductionUtility::ProductionUtility(std::string name, ResourceDepartment *resDept, Resources *resource, int MaxWorkers)
    : Utility(name, resDept, resource, MaxWorkers), currentProduction(0), proState(nullptr)
{
    std::cout << "Simulation One" << std::endl;
}

/**
 * @brief Destructor for the ProductionUtility class.
 * 
 * Cleans up any resources used by the ProductionUtility object.
 */
ProductionUtility::~ProductionUtility() = default;

/**
 * @brief Processes a production request.
 * 
 * Simulates processing a production request and includes logic 
 * to manage the request.
 */
void ProductionUtility::processRequest()
{
    std::cout << "Processing production request..." << std::endl;
    // Logic to process production request
}

/**
 * @brief Gets the production capacity of the utility.
 * 
 * @return The maximum production capacity as a float.
 */
float ProductionUtility::getProductionCapacity() const { return productionCapacity; }

/**
 * @brief Sets the production capacity of the utility.
 * 
 * @param capacity The new production capacity to set.
 */
void ProductionUtility::setProductionCapacity(float capacity) { productionCapacity = capacity; }

/**
 * @brief Gets the current production level.
 * 
 * @return The current production level as a float.
 */
float ProductionUtility::getCurrentProduction() const { return currentProduction; }

/**
 * @brief Sets the current production level.
 * 
 * @param production The new production level to set.
 */
void ProductionUtility::setCurrentProduction(float production) { currentProduction = production; }

/**
 * @brief Gets the current production state as a string.
 * 
 * @return A string representation of the current production state.
 */
std::string ProductionUtility::getProState() const
{
    return (proState) ? proState->getStateName() : "No state";
}

/**
 * @brief Sets the production state to a new state.
 * 
 * Deletes the previous production state and assigns a new one.
 * 
 * @param state A pointer to the new ProductionState to set.
 */
void ProductionUtility::setProState(ProductionState *state)
{
    delete proState;
    proState = state;
}

/**
 * @brief Retrieves and displays the current status of the production utility.
 * 
 * Outputs information about production capacity, current production, 
 * state, revenue, and active workers to the console.
 */
void ProductionUtility::getStatus() const
{
    std::cout << "----------------Utility Status -------------------" << std::endl;
    std::cout << "1. Utility Name                    : " << name << std::endl;
    std::cout << "2. Status                          : " << proState->getStateName() << std::endl;
    std::cout << "   - Total Capacity                : " << productionCapacity << std::endl;
    std::cout << "   - Current Production            : " << currentProduction << std::endl;
    std::cout << "3. Revenue                         : " << 1000000 << std::endl; // Example static revenue
    std::cout << "4. Active Workers                  : " << ActiveWorkers << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}

/**
 * @brief Checks for breakdowns in the production process.
 * 
 * Randomly determines if a breakdown occurs (10% chance) and changes the state
 * of the utility to MaintenanceProductionState if a breakdown is detected.
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
    if (chance < 10)
    { // 10% chance of breakdown
        std::cout << name << " has broken down and is entering Maintenance State." << std::endl;

        // Change state to Maintenance (assuming setState and MaintenanceState exist)
        setProState(new MaintenanceProductionState());
    }
    else
    {
        std::cout << name << " is functioning normally." << std::endl;
    }
}
