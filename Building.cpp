#include"Building.h"

Building::Building(string type)
{
    this->type = type;
}

Building::~Building()
{

}

void Building::loadElectricity(int units)
{
    if(units > 0)
        electricityUnits += units;  
} 

void Building::loadWater(int units)
{
    if(units > 0)
        waterUnits +=units;
}

bool Building::useElectricity(int units) //units will always be > 0 'cause this is used by clean, useShower, useStove which have a predefined usage 
{
    if (this->electricityUnits - units < 0 || !this->state->useWater())
        return false;
    
    electricityUnits-=units;
    return true;
}

bool Building::useWater(int units) // units will always be > 0 'cause this is used by clean, useShower, useStove which have a predefined usage
{
    if (this->waterUnits - units < 0 ||! this->state->useWater())
        return false;

    waterUnits -= units;
    return true;
}

//a citizen calls the utilities.getWater(units,building) which calls building.loadWater(units). Same applies with elec
//when a citizen goes to work, the citizen calls useShower() which calls useWater(100) and useElectricity(50)
