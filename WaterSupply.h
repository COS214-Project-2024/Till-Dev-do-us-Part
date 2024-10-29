#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "ProductionUtility.h"
// #include "Water.h"

class WaterSupply : public ProductionUtility {
public:
    WaterSupply(std::string name, ResourceDepartment* department, Resources* resource, float capacity, int workers);
    ~WaterSupply();

    void startProduction() override;             // Starts water supply production
   
};

#endif // WATERSUPPLY_H
