#include "WarehouseFactory.h"

WarehouseFactory:: WarehouseFactory()
{
    building = new Warehouse();
}

Building* WarehouseFactory:: build()
{
    return building-> clone();
}