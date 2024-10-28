#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Utility.h"
#include "Energy.h"


class PowerPlant : public Utility
{
private:
    Energy *energy;
    ResourceDepartment *department;

public:
    PowerPlant();
    PowerPlant(std::string name, ResourceDepartment *department, Resources *energy, float totalProduction, int workers);
    ~PowerPlant();

    // Override serviceDelivery for PowerPlant-specific production
    void serviceDelivery();
};

#endif
