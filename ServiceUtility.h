#ifndef SERVICEUTILITY_H
#define SERVICEUTILITY_H
//This class is the Aggregate
//
#include "Utility.h"
#include "ServiceState.h"
// #include "Building.h"
// #include "BuildingIterator.h"
#include "OperationalServiceState.h"

class ServiceUtility : public Utility
{
protected:
    // std::vector<Building *> buildings;//LandDepartment Department Pointer
    // //Business Pointer
    // BuildingIterator iterator;
    float serviceCapacity;
    float currentServiceLevel;
    ServiceState *servState; // Pointer to the current service state

public:
    ServiceUtility(std::string name, ResourceDepartment *resDept);
    virtual ~ServiceUtility();

    // Service operations

    virtual void startService() = 0;
    // virtual void iterateBuildings(bool limitedProcessing, int maxBuildings) = 0;
    void processRequest();

    // Getters and setters for service attributes
    float getServiceCap() const;
    void setServiceCap(float capacity);

    float getCurrentServiceLevel() const;
    void setCurrentServiceLevel(float level);

    // State management
    std::string getServState() const;
    void setServState(ServiceState *state);

    void getStatus() const override;

    int  getCapacity() const;
    

    
};

#endif // SERVICEUTILITY_H
