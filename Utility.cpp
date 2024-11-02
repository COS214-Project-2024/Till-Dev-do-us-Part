#include "Utility.h"
#include <iostream>

Utility::Utility(const std::string &name, ResourceDepartment *resDept, Resources *resource, int numworkers)
    : name(name), resDept(resDept), resource(resource)
{
    UtilityBus = new Wellness("Utility", numworkers);
    std::cout << "Buying Property for Utilities" << std::endl;
    UtilityBus->buyProperty("Plant");
    std::cout << "Hiring Employess for Utilities" << std::endl;
    for (int i = 0; i <= numworkers; i++)
    {
        UtilityBus->hireEmployee();
    }
    
}

Utility::~Utility() = default;

void Utility::notifyResourceDept(const std::string &message)
{
    // Notify the Resource Department with a specific message
    std::cout << "Notifying Resource Department: " << message << std::endl;
}

std::string Utility::getName() const
{
    return name;
}

Resources *Utility::getResource() const
{
    return resource;
}

void Utility::getStatus() const
{
    std::cout << "---- Utility Status ----" << std::endl;
}