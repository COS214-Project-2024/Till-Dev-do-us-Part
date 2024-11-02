#include "ProductionUtility.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

ProductionUtility::ProductionUtility(std::string name, ResourceDepartment *resDept, Resources *resource,int numworkers)
    : Utility(name, resDept, resource,numworkers), currentProduction(0), proState(nullptr)
{
}

ProductionUtility::~ProductionUtility() = default;


void ProductionUtility::processRequest()
{
    std::cout << "Processing production request..." << std::endl;
    // Logic to process production request
}

float ProductionUtility::getProductionCapacity() const { return productionCapacity; }
void ProductionUtility::setProductionCapacity(float capacity) { productionCapacity = capacity; }

float ProductionUtility::getCurrentProduction() const { return currentProduction; }
void ProductionUtility::setCurrentProduction(float production) { currentProduction = production; }

std::string ProductionUtility::getProState() const
{
    return (proState) ? proState->getStateName() : "No state";
}

void ProductionUtility::setProState(ProductionState *state)
{
    delete proState;
    proState = state;
}

void ProductionUtility::getStatus() const
{
    std::cout << "----------------Utility Status -------------------" << std::endl;
    std::cout << "1. Utility Name                    : " << name << std::endl;
    std::cout << "2. Status                          : " << proState->getStateName() << std::endl;
    std::cout << "   - Total Capacity                : " << productionCapacity << std::endl;
    std::cout << "   - Current Production            : " << currentProduction << std::endl;
    std::cout << "3. Revenue                         : " << 1000000 << std::endl;
    std::cout << "4. Active Workers                  : " << workers << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}

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
