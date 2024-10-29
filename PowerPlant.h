#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "ProductionUtility.h"
#include "Energy.h"

class PowerPlant : public ProductionUtility {
public:
    PowerPlant(std::string name, ResourceDepartment* department, Resources* resource, float capacity, int workers);
    ~PowerPlant();

    void startProduction() override;          // Starts power production
    
};

#endif // POWERPLANT_H
