#ifndef WAREHOUSEFACTORY_H
#define WAREHOUSEFACTORY_H
#include "BuildingFactory.h"
#include "Warehouse.h"

class WarehouseFactory: public BuildingFactory{

    public:
        WarehouseFactory();
        Building* build();
};
#endif