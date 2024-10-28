#include "ResourceDepartment.h"
#pragma once
class Adult
{
private:
    ResourceDepartment* resourceDepartment;
public:
    Adult(ResourceDepartment* rd);
    ~Adult();
    void goToWork();
};


