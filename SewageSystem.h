#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "ServiceUtility.h"

class SewageSystem : public ServiceUtility {
public:
    SewageSystem(std::string name, ResourceDepartment* department);
    ~SewageSystem();

    void startService() override;  
    void iterateBuildings(bool limitedProcessing, int maxBuildings) override;               // Starts sewage management service
    
};

#endif // SEWAGESYSTEM_H
