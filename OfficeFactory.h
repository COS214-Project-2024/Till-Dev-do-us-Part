#ifndef OFFICEFACTORY_H
#define OFFICEFACTORY_H
#include "BuildingFactory.h"
#include "Office.h"

class OfficeFactory: public BuildingFactory{

    public:
        OfficeFactory();
        Building* build();
};
#endif