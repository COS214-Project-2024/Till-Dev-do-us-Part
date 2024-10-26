#ifndef LandmarkFactory_H
#define LandmarkFactory_H
#include "BuildingFactory.h"
#include "Landmark.h"

class LandmarkFactory: public BuildingFactory{

public:
    LandmarkFactory();
    Building* build();
}
#endif