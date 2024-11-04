#include "SuburbFactory.h"

SuburbFactory:: SuburbFactory()
{
    building = new Suburb();
}

Building* SuburbFactory:: build()
{
    return building-> clone();
}