#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "ResourceDepartment.h"
#include "Resources.h"
#include "Business.h"
#include "Wellness.h"

class ResourceDepartment;
class Utility
{
protected:
    std::string name;
    ResourceDepartment *resDept; // Pointer to the Resource Department
    Resources *resource;         // Pointer to the resources used by the utility
    Business * UtilityBus;//Hire workers using Business
    int workers;

public:
    // Constructors and destructor
    Utility();
    Utility(const std::string &name, ResourceDepartment *resDept, Resources *resource,int numworkers);
    virtual ~Utility();

  
    void notifyResourceDept(const std::string &message);

    // Getters and setters
    virtual std::string getName() const;
    int getWorkers() const;
    virtual void getStatus() const;
    Resources *getResource() const;
    
};

#endif // UTILITY_H
