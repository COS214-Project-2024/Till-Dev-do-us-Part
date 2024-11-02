#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "ProductionUtility.h"
#include "Water.h"

class WaterSupply : public ProductionUtility {
    private: Resources * water;
public:

   WaterSupply(std::string name, ResourceDepartment *department, Water *resource,int numworkers);
    ~WaterSupply();

    void startProduction() override;          // Starts power production
    
};

#endif // WATERSUPPL_H
