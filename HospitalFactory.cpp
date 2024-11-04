#include "HospitalFactory.h"

HospitalFactory:: HospitalFactory()
{
    building = new Hospital();
}

Building* HospitalFactory:: build()
{
    return building-> clone();
}