#ifndef SERVICEUTILITY_H
#define SERVICEUTILITY_H

#include "Utility.h"
#include "ServiceState.h"

class ServiceUtility : public Utility {
protected:
    float serviceCapacity;
    float currentServiceLevel;
    ServiceState* servState;  // Pointer to the current service state

public:
    ServiceUtility(std::string name, ResourceDepartment* resDept, Resources* resource, int workers, float capacity);
    virtual ~ServiceUtility();

    // Service operations
    virtual void startService();
    void processRequest();

    // Getters and setters for service attributes
    float getServiceCap() const;
    void setServiceCap(float capacity);

    float getCurrentServiceLevel() const;
    void setCurrentServiceLevel(float level);

    // State management
    std::string getServState() const;
    void setServState(ServiceState* state);
};

#endif // SERVICEUTILITY_H
