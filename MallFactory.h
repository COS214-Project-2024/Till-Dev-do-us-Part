#ifndef MALLFACTORY_H
#define MALLFACTORY_H
#include "BuildingFactory.h"
#include "Mall.h"

class MallFactory: public BuildingFactory{

    public:
        MallFactory();
        Building* build();
};
#endif