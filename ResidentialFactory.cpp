#include "ResidentialFactory.h"

ResidentialFactory:: ResidentialFactory()
{
    building= new Residential();
}

Building* ResidentialFactory:: build()
{
        if (building!=nullptr){
        return building-> clone();

    }
}
