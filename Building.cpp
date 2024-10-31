#include"Building.h"

Building::Building(string type)
{
    state = new ConstructionState();
    this->type = type;
    this->cleanliness = 100;
    electricityUnits = 0;
    waterUnits = 0;
}

Building::~Building()
{
    delete this->state;
    state = nullptr;
}

void Building::loadElectricity(float units)
{
    if(units > 0){
        if(this->state->getName() =="Construction" && waterUnits > 0 && cleanliness > 0 && electricityUnits ==0){
            delete this->state;
            this->state = new CompleteState();
            
        }
        electricityUnits += units;  
    }
} 

void Building::loadWater(float units)
{
    if (units > 0)
    {
        if (this->state->getName() == "Construction" && electricityUnits > 0 && cleanliness > 0 && waterUnits <= 0)
        {
            delete this->state;
            this->state = new CompleteState();
        }
        waterUnits+= units;
    }
}

bool Building::useElectricity(float units) //units will always be > 0 'cause this is used by clean, useShower, useStove which have a predefined usage 
{
    if (this->electricityUnits - units < 0 || !this->state->canUseElectricity())
        return false;
    
    electricityUnits-=units;
    return true;
}

bool Building::useWater(float units) // units will always be > 0 'cause this is used by clean, useShower, useStove which have a predefined usage
{
    if(this->waterUnits - units < 0 ||! this->state->canUseWater())
        return false;

    waterUnits -= units;
    return true;
}

float Building::getValue()
{
    return this->value;
}

string Building::getType()
{
    return this->type;
}

float Building::getWater()
{
    return waterUnits;
}

float Building::getElectricity()
{
    return electricityUnits;
}

float Building::getCleanliness()
{
    return cleanliness;
}
