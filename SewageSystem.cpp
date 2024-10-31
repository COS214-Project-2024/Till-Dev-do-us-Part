#include "SewageSystem.h"
#include <iostream>

SewageSystem::SewageSystem(std::string name, ResourceDepartment *department, Resources *resource, int workers, float cap)
    : ServiceUtility(name, department, resource, workers, cap) {}

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
}
