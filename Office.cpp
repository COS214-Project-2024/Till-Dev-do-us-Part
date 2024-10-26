#include "Office.h"

Office::Office():Commercial("Office"){

}

Office::~Office(){
    occupants.clear();
}

void Office::demolish(){
    //want it to call the destructor
}

bool Office::clean()
{
    return useWater(150) && useElectricity(40);
}

bool Office::addOccupant(Citizen *c){
    if (c != nullptr && occupants.size() < capacity)
    {
        occupants.push_back(c);
        return true;
    }

    return false;
}

