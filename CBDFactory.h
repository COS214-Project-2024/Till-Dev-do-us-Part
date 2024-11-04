#ifndef CBDFACTORY_H
#define CBDFACTORY_H
#include "BuildingFactory.h"
#include "CBD.h"

class CBDFactory: public BuildingFactory{

    public:
        CBDFactory();
        Building* build();
};
#endif