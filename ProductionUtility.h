#ifndef PRODUCTIONUTILITY_H
#define PRODUCTIONUTILITY_H
#include <memory>
#include "Utility.h"
#include "ProductionState.h"
#include "OperationalProductionState.h"
#include <thread>       // For sleep_for
#include <chrono>  
#include "MaintenanceProductionState.h"
#include "OutageProductionState.h"
class ProductionUtility : public Utility
{
protected:
    float productionCapacity;
    float currentProduction;
    ProductionState* proState;
public:
    ProductionUtility(std::string name, ResourceDepartment *resDept, Resources *resource,int maxWorkers);
    virtual ~ProductionUtility();

    // Production operations
   
    virtual void startProduction() = 0;
    void processRequest();

    // Getters and setters for production attributes
    float getProductionCapacity() const;
    void setProductionCapacity(float capacity);

    float getCurrentProduction() const;
    void setCurrentProduction(float production);

    // State management
    std::string getProState() const;
    void setProState(ProductionState *state);
    void getStatus() const override;
     void checkForBreakdowns();

};

#endif // PRODUCTIONUTILITY_H
