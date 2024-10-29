#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "ServiceUtility.h"

class WasteManagement : public ServiceUtility {
public:
    WasteManagement(std::string name, ResourceDepartment* department, Resources* resource, int workers,float cap);
    ~WasteManagement();

    void startService() override;                  // Starts waste management service
       // Adjusts waste management service level
};

#endif // WASTEMANAGEMENT_H
