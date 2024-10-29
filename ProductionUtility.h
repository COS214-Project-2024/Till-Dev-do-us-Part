#ifndef PRODUCTIONUTILITY_H
#define PRODUCTIONUTILITY_H

#include "Utility.h"
#include "ProductionState.h"

class ProductionUtility : public Utility {
protected:
    float productionCapacity;
    float currentProduction;
    ProductionState* proState;  // Pointer to the current production state

public:
    ProductionUtility(std::string name, ResourceDepartment* resDept, Resources* resource, int workers, float capacity);
    virtual ~ProductionUtility();

    // Production operations
    void startProduction() override;
    void processRequest();

    // Getters and setters for production attributes
    float getProductionCap() const;
    void setProductionCap(float capacity);
    
    float getCurrentProduction() const;
    void setCurrentProduction(float production);

    // State management
    std::string getProState() const;
    void setProState(ProductionState* state);
};

#endif // PRODUCTIONUTILITY_H
