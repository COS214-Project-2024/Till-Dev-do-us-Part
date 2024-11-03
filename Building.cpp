#include "Building.h"
#include "ResourceDepartment.h"
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

bool Building::requestElectricity(float units)
{
    cout << "Requesting electricity from Resource Department:";

    if (resourceDept->processResourceRequest("electricity", units))
    {
        electricityUnits += units;
        cout << "Resource department supplied electricity" << endl;
        if(waterUnits>0){
            delete this->state;
            this->state = new CompleteState();
        }
        return true;
    }
    cout << "Resource department could not supply electricity" << endl;
    return false;
}

bool Building::requestWater(float units)
{
    cout << "Requesting water from Resource Department:";
    if (resourceDept->processResourceRequest("water", units))
    {
        waterUnits += units;
        cout << "Resource department supplied water" << endl;
        if(electricityUnits>0){
            delete this->state;
            this->state = new CompleteState();
        }
        return true;
    }
    cout << "Resource department could not supply water" << endl;
    return false;
}

bool Building::useElectricity(float units) // units will always be > 0 'cause this is used by clean, useShower, useStove which have a predefined usage
{
    if (this->electricityUnits - units < 0 || !this->state->canUseElectricity())
        return false;

    electricityUnits -= units;
    return true;
}

bool Building::useWater(float units) // units will always be > 0 'cause this is used by clean, useShower, useStove which have a predefined usage
{
    if (this->waterUnits - units < 0 || !this->state->canUseWater())
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
