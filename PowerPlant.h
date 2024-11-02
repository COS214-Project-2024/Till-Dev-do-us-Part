#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "ProductionUtility.h"
#include "Energy.h"

class PowerPlant : public ProductionUtility
{
private:
    Resources *energy;

public:
    PowerPlant(std::string name, ResourceDepartment *department, Resources *resource);
    ~PowerPlant();

    void startProduction() override; // Starts power production
};

#endif // POWERPLANT_H
