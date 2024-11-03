#include "ParkFactory.h"

ParkFactory:: ParkFactory()
{
    building = new Park();
}

Building* ParkFactory:: build()
{
    return building-> clone();
}