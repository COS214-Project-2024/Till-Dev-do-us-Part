#ifndef SuburbFactory_H
#define SuburbFactory_H
#include "BuildingFactory.h"
#include "Suburb.h"

class SuburbFactory: public BuildingFactory{

    public:
        SuburbFactory();
        Building* build();
};
#endif