#ifndef PRODUCTIONUTILITY_H
#define PRODUCTIONUTILITY_H

#include "Utility.h"
#include "ProductionState.h"

class ProductionUtility : public Utility
{
protected:
    float productionCapacity;
    float currentProduction;
    ProductionState *proState; // Pointer to the current production state

public:
    ProductionUtility(std::string name, ResourceDepartment *resDept, Resources *resource);
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
};

#endif // PRODUCTIONUTILITY_H
