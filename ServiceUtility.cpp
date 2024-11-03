#include "ServiceUtility.h"

/**
 * @brief Constructs a ServiceUtility object with specified parameters.
 * 
 * Initializes the service utility with a name, a pointer to the resource department, 
 * and sets the initial service capacity and current service level to zero.
 * 
 * @param name The name of the service utility.
 * @param resDept A pointer to the associated Resource Department.
 */
ServiceUtility::ServiceUtility(std::string name, ResourceDepartment *resDept)
    : Utility(name, resDept, nullptr, 0), serviceCapacity(0), currentServiceLevel(0), servState(nullptr) {}

/**
 * @brief Virtual destructor for the ServiceUtility class.
 * 
 * Cleans up any resources used by the ServiceUtility object.
 */
ServiceUtility::~ServiceUtility() = default;

/**
 * @brief Processes a service request.
 * 
 * Outputs a message indicating that a service request is being processed.
 */
void ServiceUtility::processRequest()
{
    std::cout << "Processing service request..." << std::endl;
    // Logic to process service request
}

/**
 * @brief Gets the service capacity of the utility.
 * 
 * @return The maximum service capacity as a float.
 */
float ServiceUtility::getServiceCap() const { return serviceCapacity; }

/**
 * @brief Sets the service capacity of the utility.
 * 
 * @param capacity The new service capacity to set.
 */
void ServiceUtility::setServiceCap(float capacity) { serviceCapacity = capacity; }

/**
 * @brief Gets the current service level.
 * 
 * @return The current service level as a float.
 */
float ServiceUtility::getCurrentServiceLevel() const { return currentServiceLevel; }

/**
 * @brief Sets the current service level.
 * 
 * @param level The new service level to set.
 */
void ServiceUtility::setCurrentServiceLevel(float level) { currentServiceLevel = level; }

/**
 * @brief Gets the current service state as a string.
 * 
 * @return A string representation of the current service state.
 */
std::string ServiceUtility::getServState() const
{
    return (servState) ? servState->getStateName() : "No state";
}

/**
 * @brief Sets the service state to a new state.
 * 
 * Deletes the previous service state if it exists and assigns a new one.
 * 
 * @param state A pointer to the new ServiceState to set.
 */
void ServiceUtility::setServState(ServiceState *state)
{
    if (servState)
    {
        delete servState;
    }
    
    if (state)
    {
        std::cout << "State exists. Setting state to: " << state->getStateName() << std::endl;
    }

    std::cout << "Setting state..." << std::endl;

    this->servState = state;

    if (servState)
    {
        std::cout << "State set successfully." << std::endl;
    }
}

/**
 * @brief Gets the service capacity as an integer.
 * 
 * @return The current service capacity as an integer.
 */
int ServiceUtility::getCapacity() const
{
    return serviceCapacity;
}

/**
 * @brief Retrieves and displays the current status of the service utility.
 * 
 * Outputs information about the utility's name, current status, service capacity, 
 * current service level, revenue, and number of workers to the console.
 */
void ServiceUtility::getStatus() const
{
    std::cout << "----------------Utility Status -------------------" << std::endl;
    std::cout << "1. Utility Name                    : " << name << std::endl;
    std::cout << "2. Status                          : " << (servState ? servState->getStateName() : "No state") << std::endl;
    std::cout << "   - Total Capacity                : " << serviceCapacity << std::endl;
    std::cout << "   - Service Level                 : " << currentServiceLevel << "/3" << std::endl;
    std::cout << "3. Revenue                         : " << 10000 << std::endl;
    std::cout << "4. Workers                         : " << ActiveWorkers << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}
