#include "SewageSystem.h"
#include <iostream>

SewageSystem::SewageSystem(std::string name, ResourceDepartment *department)
    : ServiceUtility(name, department) {}

SewageSystem::~SewageSystem() {}

void SewageSystem::startService()
{
    if (servState)
    {
        servState->handleService(this);
    }
    else
    {
        std::cout << getName() << " has no service state set.\n";
    }
    getStatus();
}

// void SewageSystem::iterateBuildings(bool limitedProcessing, int maxBuildings)
// {

// } // Starts sewage management service
