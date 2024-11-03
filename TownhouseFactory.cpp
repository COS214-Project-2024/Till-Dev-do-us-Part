#include "TownhouseFactory.h"

TownhouseFactory:: TownhouseFactory()
{
    building = new Townhouse();
}

Building* TownhouseFactory:: build()
{
    return building-> clone();
}