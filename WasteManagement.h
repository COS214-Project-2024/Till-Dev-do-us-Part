#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H
//This class is the Concrete Aggregate Aggregate
#include "ServiceUtility.h"
#include "ServiceState.h"
#include <vector>

class WasteManagement : public ServiceUtility
{
private:
    // std::vector<Building *> buildings;
    // BuildingIterator iterator;


public:
    WasteManagement(std::string name, ResourceDepartment *department);
    ~WasteManagement();

    void startService() override;
    void iterateBuildings(bool limitedProcessing, int maxBuildings) override; // Starts waste management service
                                                                              // Adjusts waste management service level
};

#endif // WASTEMANAGEMENT_H
