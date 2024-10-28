#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Utility.h"

class WaterSupply : public Utility
{
public:
    WaterSupply();
    WaterSupply(Resources *resource, ResourceDepartment *department, float totalProduction, int workers)
        : Utility("WaterSupply", department, resource, totalProduction, workers) {}

    void serviceDelivery()
    {
        std::cout << "WaterSupply: Distributing water at " << getCurrentProduction() << " units capacity.\n";
        // Additional specific logic for water distribution
    }
};

#endif
