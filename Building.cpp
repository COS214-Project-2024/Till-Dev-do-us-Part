#include"Building.h"

Building::Building(string type)
{
    this->type = type;
}

Building::~Building()
{
    occupants.clear();
}

bool Building::isOccupied(){
    return occupants.size() > 0;
}


bool Building::addOccupant(Citizen *c){
    if(c != NULL){
        if(occupants.size() < capacity){
            occupants.push_back(c);
            return true;
        }
    }
    return false;
}
