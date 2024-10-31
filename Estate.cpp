#include "Estate.h"

Estate::Estate():Residential("Estate"){
    noBuildings = 0;
    value = 200000;
    area = 500;
    capacity = 9;
}

Estate::~Estate()
{
    demolish();
    cout << "Estate demolished" << endl;
}

bool Estate::addHouse(Residential *building)
{
    if(building != nullptr)
    {
        if(building->getType() == "Estate")
        {
            cout << "Cannot add an Estate to an Estate\n";
            return false;
        }
        else
        {
            if (noBuildings + 1 <= capacity){
                buildings.push_back(building);
                noBuildings++;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cleanliness = (cleanliness + building->getCleanliness()) / noBuildings;
                cout << "Building added to the Estate" << endl;
                return true;
            }
            else{
                cout << "Building could not be added to the Estate" << endl;
                return false;
            }
        }
    }

    cout << "Building is non-existent" << endl;
    return false;

}

void Estate::demolish()
{
    cout << "Clearing and demolishing all the buildings in the Estate:" << endl;
    for (int i = 0; i < buildings.size(); ++i)
    {
        delete buildings.at(i);
        buildings[i] = nullptr;
    }
    buildings.clear();
    cout << "All buildings in the Estate cleared" << endl;
}

bool Estate::useShower()
{
    bool usedAll = true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->useShower())
        {
            usedAll = false;
        }
    }

    if (!usedAll)
    {
        cout << "Could not use all showers" << endl;
        return false;
    }

    cout << "Used all showers in the Estate" << endl;
    return true;
}

bool Estate::useToilet()
{
    bool usedAll = true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->useToilet())
        {
            usedAll = false;
        }
    }

    if (!usedAll)
    {
        cout << "Could not use all toilets" << endl;
        return false;
    }

    cout << "Used all toilets in the Estate" << endl;
    return true;
}

bool Estate::useStove()
{
    bool usedAll = true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->useStove())
        {
            usedAll = false;
        }
    }

    if (!usedAll)
    {
        cout << "Could not use all stoves" << endl;
        return false;
    }

    cout << "Used all stoves in the Estate" << endl;
    return true;
}

bool Estate::clean()
{
    bool cleanedAll=true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->clean())
        {
            cleanedAll = false;
        }
    }

    if (!cleanedAll)
    {
        cout << "Could not clean all buildings " << endl;
        return false;
    }
    cout << "Cleaned all buildings in the Estate" << endl;
    return true;
}

bool Estate::addOccupant(Citizen *c)
{
    if(c != nullptr)
    {
        for (vector<Residential*>::iterator it = buildings.begin(); it!= buildings.end(); it++)
        {
            if(!(Residential*)(*it)->isOccupied())
            {
                if((*it)->addOccupant(c)){
                    cout << "Citizen added to Estate\n";
                    return true;
                }
            }
        }

        cout << "Citizen could not be added to Estate\n";
        return false;
    }

    cout << "Citizen is non-existent\n";
    return false;
}

void Estate::goToWork(){
    cout << "Taking citizens in estate to work\n" ;
    for(vector<Residential*>::iterator it = buildings.begin(); it != buildings.end(); it++){
        (*it)->goToWork();
    }
    cout << "Citizens are at work!";
}

int Estate::getNoBuildings(){
    return noBuildings;
}

Building* Estate::clone()
{
    Estate* newEstate = new Estate();
    newEstate->area = this->area;
    newEstate->capacity = this->capacity;
    for (vector<Residential*>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        newEstate->addHouse((Residential*)(*it)->clone());
    }
    newEstate->cleanliness = this->getCleanliness();
    newEstate->electricityUnits = this->getElectricity();
    newEstate->waterUnits = this->getWater();
    newEstate->state = this->state->clone();
    return newEstate;

}

bool Estate::removeOccupant(Citizen *c)
{
    for (vector<Residential*>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if((*it)->removeOccupant(c)){
            cout << "Occupant removed!\n";
            return true;
        }
    }
    cout << "Occupant not found in any of the buildings in the estate\n";
    return false;
}

bool Estate::removeBuilding(Residential* building){
    vector<Residential *>::iterator first = buildings.begin();
    vector<Residential *>::iterator last = buildings.end();

    vector<Residential *>::iterator it = find(first, last, building);
    if (it != last)
    {
        
        buildings.erase(it);
        value -= building->getValue();
        waterUnits -= building->getWater();
        electricityUnits -= building->getElectricity();
        cleanliness = (cleanliness - building->getCleanliness()) / noBuildings;
        delete building;
        building = nullptr;
        noBuildings--;
        cout << "Building removed from the Estate" << endl;
        return true;
    }

    cout << "Building not in the Estate" << endl;
    return false;
}

bool Estate::isOccupied()
{
    for (vector<Residential*>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if(!(*it)->isOccupied()){
            return false;
        }
    }
    
    return true;
}

float Estate::getCleanliness()
{
    int count = 0;
    int accumCleanliness = 0;
    for (vector<Residential *>::iterator it =buildings.begin(); it !=buildings.end(); ++it)
    {
        accumCleanliness += (*it)->getCleanliness();
        count++;
    }
    cleanliness = accumCleanliness / count;
    return cleanliness;
}

float Estate::getWater()
{
    int accumWater = 0;
    for (vector<Residential *>::iterator it =buildings.begin(); it !=buildings.end(); ++it)
    {
        accumWater += (*it)->getWater();
    }
    waterUnits = accumWater;
    return waterUnits;
}

float Estate::getElectricity()
{
    int accumElec = 0;
    for (vector<Residential *>::iterator it =buildings.begin(); it !=buildings.end(); ++it)
    {
        accumElec += (*it)->getElectricity();
    }
    electricityUnits = accumElec;
    return electricityUnits;
}