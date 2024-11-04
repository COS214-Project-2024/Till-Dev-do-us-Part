/**
 * @file ServiceUtility.cpp
 * @brief Implements the ServiceUtility class methods for managing service-oriented utilities in the simulation.
 */

#include "ServiceUtility.h"

/**
 * @brief Constructs a ServiceUtility with specified name and Resource Department.
 * @param name Name of the service utility
 * @param resDept Pointer to the Resource Department
 */
ServiceUtility::ServiceUtility(std::string name, ResourceDepartment *resDept)
    : Utility(name, resDept, resource, MaxWorkers), serviceCapacity(0), currentServiceLevel(0), servState(nullptr) {}

/**
 * @brief Default destructor for ServiceUtility.
 */
ServiceUtility::~ServiceUtility() = default;

/**
 * @brief Processes a service request.
 */
void ServiceUtility::processRequest()
{
    std::cout << "Processing service request..." << std::endl;
}

/**
 * @brief Gets the service capacity.
 * @return The service capacity
 */
float ServiceUtility::getServiceCap() const { return serviceCapacity; }

/**
 * @brief Sets the service capacity.
 * @param capacity New service capacity
 */
void ServiceUtility::setServiceCap(float capacity) { serviceCapacity = capacity; }

/**
 * @brief Gets the current service level.
 * @return The current service level
 */
float ServiceUtility::getCurrentServiceLevel() const { return currentServiceLevel; }

/**
 * @brief Sets the current service level.
 * @param level New current service level
 */
void ServiceUtility::setCurrentServiceLevel(float level) { currentServiceLevel = level; }

/**
 * @brief Gets the current state of the service utility.
 * @return The name of the current service state
 */
std::string ServiceUtility::getServState() const
{
    return (servState) ? servState->getStateName() : "No state";
}

/**
 * @brief Sets the service state.
 * @param state New state for the service
 */
void ServiceUtility::setServState(ServiceState *state)
{
    delete servState;
    servState = state;
}

/**
 * @brief Gets the total service capacity.
 * @return The service capacity
 */
int ServiceUtility::getCapacity() const
{
    return serviceCapacity;
}

/**
 * @brief Prints the current status of the service utility.
 */
void ServiceUtility::getStatus() const
{
    std::cout << "----------------Utility Status -------------------" << std::endl;
    std::cout << "1. Utility Name                    : " << name << std::endl;
    std::cout << "2. Status                          : " << servState->getStateName() << std::endl;
    std::cout << "   - Total Capacity                : " << serviceCapacity << std::endl;
    std::cout << "   - Service Level                 : " << currentServiceLevel << "/3" << std::endl;
    std::cout << "3. Revenue                         : " << 10000 << std::endl;
    std::cout << "4. Workers                         : " << ActiveWorkers << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}

/**
 * @brief Gets the type of utility.
 * @return The type of utility as a string
 */
std::string ServiceUtility::getType() const
{
    return "Service";
}
