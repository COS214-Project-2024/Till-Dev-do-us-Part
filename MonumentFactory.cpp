#include "MonumentFactory.h"

MonumentFactory:: MonumentFactory()
{
    building = new Monument();
}

Building* MonumentFactory:: build()
{
    return building-> clone();
}