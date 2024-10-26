#include "LandmarkFactory.h"

LandmarkFactory:: LandmarkFactory()
{
    building= new Landmark();
}

Building* LandmarkFactory:: build()
{
    if (building!=nullptr){
        return building-> clone();

    }
      
}
