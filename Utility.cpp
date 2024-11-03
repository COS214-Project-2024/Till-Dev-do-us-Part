#include "Utility.h"
#include <iostream>

Utility::Utility(const std::string &name, ResourceDepartment *resDept, Resources *resource, int maxWorkers)
    : name(name), resDept(resDept), resource(resource), MaxWorkers(maxWorkers)
{
    UtilityBus = new Wellness("Utility", MaxWorkers);
    std::cout << "Buying Property for Utilities" << std::endl;
    UtilityBus->buyProperty("Plant");
    std::cout << "Hiring Employess for Utilities" << std::endl;
    for (int i = 0; i <= MaxWorkers; i++)
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

int Utility::getActiveWorkers() const
{
    return ActiveWorkers;
}
int Utility::getMaxWorkers() const
{
    return MaxWorkers;
}