#ifndef CULTURALFACTORY_H
#define CULTURALFACTORY_H
#include "BuildingFactory.h"
#include "CulturalCenter.h"

class CulturalFactory: public BuildingFactory{

    public:
        CulturalFactory();
        Building* build();
};
#endif