#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Utility.h"

class WaterSupply : public Utility {
public:
    WaterSupply(Resource* resource, float totalProduction, int workers)
        : Utility("WaterSupply", resource, totalProduction, workers) {}

    void serviceDelivery() override {
        std::cout << "WaterSupply: Distributing water at " << getCurrentProduction() << " units capacity.\n";
        // Additional specific logic for water distribution
    }
};

#endif
