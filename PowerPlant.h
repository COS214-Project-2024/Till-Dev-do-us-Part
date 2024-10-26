#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "Utility.h"

class PowerPlant : public Utility {
public:
    PowerPlant(std::string name, Resource* resource, float totalProduction, int workers);
    ~PowerPlant();

    // Override serviceDelivery for PowerPlant-specific production
    void serviceDelivery() override;
};

#endif
