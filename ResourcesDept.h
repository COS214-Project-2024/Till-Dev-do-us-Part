#ifndef ResourcesDept_H
#define ResourcesDept_H

#include "Department.h"
#include "Utility.h"

class ResourcesDept : public Department {
private:
    std:: vector<Utility*> utilities;
    int totalEnergyDemand;
    int totalWaterDemand;
public:
    ResourcesDept(float budget);
    void adddUtility();
    void processResourceRequest(float amount);
    
};

#endif 
