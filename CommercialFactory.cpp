#include "CommercialFactory.h"

CommercialFactory:: CommercialFactory()
{
    building= new Commercial();
}

Building* CommercialFactory:: build()
{
        if (building!=nullptr){
        return building-> clone();

    }
}
