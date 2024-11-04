#ifndef SHOPFACTORY_H
#define SHOPFACTORY_H
#include "BuildingFactory.h"
#include "Shop.h"

class ShopFactory: public BuildingFactory{

public:
    ShopFactory();
    Building* build();
};
#endif