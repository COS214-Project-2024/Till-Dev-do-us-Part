#ifndef HOSPITALFACTORY_H
#define HOSPITALFACTORY_H
#include "BuildingFactory.h"
#include "Hospital.h"

class HospitalFactory: public BuildingFactory{

    public:
        HospitalFactory();
        Building* build();
};
#endif