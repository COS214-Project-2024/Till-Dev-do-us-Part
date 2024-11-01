#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "ResourceDepartment.h"
#include "Resources.h"

class ResourceDepartment;
class Utility
{
protected:
    std::string name;
    ResourceDepartment *resDept; // Pointer to the Resource Department
    Resources *resource;         // Pointer to the resources used by the utility
    float revenue;
    int workers;

public:
    // Constructors and destructor
    Utility();
    Utility(const std::string &name, ResourceDepartment *resDept, Resources *resource, int workers);
    virtual ~Utility();

    // Basic utility operations
    virtual void checkForBreakdowns();
    void notifyResourceDept(const std::string &message);

    // Getters and setters
    virtual std::string getName() const;
    int getWorkers() const;
    virtual void getStatus() const;
    Resources *getResource() const;
    
};

#endif // UTILITY_H
