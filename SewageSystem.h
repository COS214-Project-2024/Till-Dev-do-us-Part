#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "ServiceUtility.h"

class SewageSystem : public ServiceUtility {
public:
    SewageSystem(std::string name, ResourceDepartment* department, Resources* resource, int workers,float cap);
    ~SewageSystem();

    void startService() override;                 // Starts sewage management service
    
};

#endif // SEWAGESYSTEM_H
