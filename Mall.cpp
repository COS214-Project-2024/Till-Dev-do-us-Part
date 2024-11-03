#include "Mall.h"

Mall::Mall():Commercial("Mall")
{
    area = 40000;
    value = 1200000;
    capacity = 15;
}

bool Mall::addBuilding(Commercial *building)
{
    if (building != nullptr){
        if (building->getType() == "Mall"){
            cout << "Cannot add a Mall to a Mall" << endl;
            return false;
        }
        else{
            if (noBuildings + 1 <= capacity){
                stores.push_back(building);
                noBuildings++;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cleanliness = (cleanliness + building->getCleanliness()) / noBuildings;
                cout << "Building added to the Mall" << endl;
                return true;
            }
            else
            {
                cout << "Could not build, not enough land/space" << endl;
                return false;
            }
        }
    }
    cout << "Cannot add non-existent building to the Mall" << endl;
    return false;
}
bool Mall::removeBuilding(Commercial *building)
{
    vector<Commercial *>::iterator first = stores.begin();
    vector<Commercial *>::iterator last = stores.end();

    vector<Commercial *>::iterator it = find(first, last, building);
    if (it != last)
    {

        stores.erase(it);
        value -= building->getValue();
        waterUnits -= building->getWater();
        electricityUnits -= building->getElectricity();
        cleanliness = (cleanliness - building->getCleanliness()) / noBuildings;
        building = nullptr;
        noBuildings--;
        cout << "Building removed from the Mall" << endl;
        return true;
    }

    cout << "Building not in the Mall" << endl;
    return false;
}

void Mall::demolish()
{
    cout << "====Demolishing buildings in the Mall====" << endl;
    for (int i = 0; i < stores.size(); ++i)
    {
        delete stores.at(i);
        stores[i] = nullptr;
    }
    stores.clear();
    cout << "Demolished all buildings in the Mall" << endl;
}

bool Mall::clean()
{
    int count = 0;
    int accumCleanliness = 0;
    for (vector<Commercial*>::iterator it = stores.begin(); it != stores.end(); ++it)
    {
        if(!(*it)->clean()){
            cout << "Building " << (*it) <<" could not be cleaned (not enough water or electricity)" << endl;
            return false;
        }
        count++;
        accumCleanliness += (*it)->getCleanliness();
    }
    cleanliness = accumCleanliness/count;
    cout << "All buildings in " << this << " were cleaned";
    return true;
}

bool Mall::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); it++)
        {
            
            if ((*it)->addOccupant(c))
            {
                cout << "Citizen added to Mall\n";
                return true;
            }
        }
        cout << "Citizen could not be added to Mall, all bulidings at capacity\n";
        return false;
    }

    cout << "Citizen is non-existent\n";
    return false;
}

bool Mall::removeOccupant(Citizen *c)
{
    for (vector<Commercial *>::iterator it = stores.begin(); it < stores.end(); it++)
    {
        if ((*it)->removeOccupant(c))
        {
            cout << "Occupant removed!\n";
            return true;
        }
    }
    cout << "Occupant not found in any of the buildings in the mall\n";
    return false;
}

Building *Mall::clone()
{
    Mall *newBuilding = new Mall();
    newBuilding->area = this->area;
    newBuilding->capacity = this->capacity;
    for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); it++)
    {
        newBuilding->addBuilding((Commercial*)(*it)->clone());
    }
    newBuilding->cleanliness = this->getCleanliness();
    newBuilding->electricityUnits = this->getElectricity();
    newBuilding->waterUnits = this->getWater();
    newBuilding->state = this->state->clone();
    return newBuilding;
}

float Mall::getCleanliness(){
    int count = 0;    
    int accumCleanliness = 0;
    for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); ++it)
    {
        accumCleanliness += (*it)->getCleanliness();
        count++;
    }
    cleanliness = accumCleanliness / count;
    return cleanliness;
}

float Mall::getWater(){
    int accumWater = 0;
    for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); ++it)
    {
        accumWater += (*it)->getWater();
    }
    waterUnits = accumWater;
    return waterUnits;
}

float Mall::getElectricity(){
    int accumElec = 0;
    for (vector<Commercial *>::iterator it = stores.begin(); it != stores.end(); ++it)
    {
        accumElec += (*it)->getElectricity();
    }
    electricityUnits = accumElec;
    return electricityUnits;
}

int Mall::getNoBuildings(){
    return noBuildings;
}

Mall::~Mall()
{
    delete this->state;
    state = nullptr;
    demolish();
    cout << "Destroyed the Mall\n";
}

bool Mall::isOccupied(){
    for (vector<Commercial *>::iterator it = stores.begin(); it < stores.end(); it++)
    {
        if (!(*it)->isOccupied())
        {
            return false;
        }
    }

    return true;
}
