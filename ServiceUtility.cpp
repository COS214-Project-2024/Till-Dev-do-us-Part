#include "ServiceUtility.h"

// ServiceUtility::ServiceUtility(std::string name, ResourceDepartment *resDept)
//     : Utility(name, resDept, resource, workers), serviceCapacity(buildings.size()), currentServiceLevel(0), servState(nullptr) {}

ServiceUtility::~ServiceUtility() = default;

void ServiceUtility::processRequest()
{
    std::cout << "Processing service request..." << std::endl;
    // Logic to process service request
}

float ServiceUtility::getServiceCap() const { return serviceCapacity; }
void ServiceUtility::setServiceCap(float capacity) { serviceCapacity = capacity; }

float ServiceUtility::getCurrentServiceLevel() const { return currentServiceLevel; }
void ServiceUtility::setCurrentServiceLevel(float level) { currentServiceLevel = level; }

std::string ServiceUtility::getServState() const
{
    return (servState) ? servState->getStateName() : "No state";
}

void ServiceUtility::setServState(ServiceState *state)
{
    if (!servState)
    {
        delete servState;
    }
    if (state)
    {
        cout << state->getStateName() << std::endl;
        cout << "State exits setting state " << std::endl;
    }
    std::cout << "Settting state" << std::endl;

    this->servState = state;
    if (servState)
    {
        cout << "not setting state " << std::endl;
    }

    std::cout << "state set" << std::endl;
}

int ServiceUtility::getCapacity() const
{
    return serviceCapacity;
}

void ServiceUtility::getStatus() const
{
    std::cout << "----------------Utility Status -------------------" << std::endl;
    std::cout << "1. Utility Name                    : " << name << std::endl;
    std::cout << "2. Status                          : " << servState->getStateName() << std::endl;
    std::cout << "   - Total Capacity                : " << serviceCapacity << std::endl;
    std::cout << "   - Service Level                 : " << currentServiceLevel << "/3" << std::endl;
    std::cout << "3. Revenue                         : " << revenue << std::endl;
    std::cout << "4. Workers                         : " << workers << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}