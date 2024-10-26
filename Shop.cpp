#include "Shop.h"

Shop::Shop():Commercial("Shop"){

}

Shop::~Shop(){
    occupants.clear();
}

void Shop::demolish(){
    //want it to call the destructor
}

bool Shop::clean()
{
    return useWater(350) && useElectricity(300);
}

bool Shop::addOccupant(Citizen *c){
    if (c != nullptr && occupants.size() < capacity)
    {
        occupants.push_back(c);
        return true;
    }

    return false;
}

