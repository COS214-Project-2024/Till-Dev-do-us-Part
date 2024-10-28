#include "Office.h"

Office::Office():Commercial("Office"){
    area = 800;
    value = 12000;
    floor =0;
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

Building *Office::clone()
{
    Office *newBuilding = new Office();

    newBuilding->electricityUnits = this->electricityUnits;
    newBuilding->waterUnits = this->waterUnits;
    newBuilding->capacity = this->capacity;

    return newBuilding;
}
