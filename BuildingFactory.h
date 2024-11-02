#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H
#include "Building.h"

class BuildingFactory{

protected:
    Building* building;

public:
    //BuildingFactory();
    virtual Building* build()=0;
    virtual ~BuildingFactory() {}

};

#endif