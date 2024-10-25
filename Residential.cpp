#include "Residential.h"

Residential::Residential(string type):Building(type){

}

bool Residential::addOccupant(Citizen *c){
    if(c != nullptr && occupants.size() < capacity){
        occupants.push_back(c);
        return true;
    }
    
    return false;
}

