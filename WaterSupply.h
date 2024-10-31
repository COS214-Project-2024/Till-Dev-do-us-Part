#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "ProductionUtility.h"
#include "Water.h"

class WaterSupply : public ProductionUtility {
    private: Resources * water;
public:

    WaterSupply(std::string name, ResourceDepartment* department, Resources* resource);
    ~WaterSupply();

    void startProduction() override;          // Starts power production
    
};

#endif // POWERPLANT_H
