#include "IndustrialSite.h"

IndustrialSite::IndustrialSite():Industrial("IndustrialSite"){
    area = 10000;
    capacity = 50;
    noBuildings = 0;
    value = 12000;
}

void IndustrialSite::loadElectricity(float units){
    
    for (vector<Industrial*>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->loadElectricity(units);
    }
    
}

void IndustrialSite::loadWater(float units){
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->loadWater(units);
    }
}

bool IndustrialSite::useElectricity(float units){
    bool usedAll = true;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if(!(*it)->useElectricity(units)){
            usedAll = false;
        }
    }
    if(!usedAll)
        cout << "Could not use "<< units<< " of electricity in all the buildings\n";
    else
        cout << "Used "<< units<<" of electricity in all the buildings\n";

    return usedAll;
}

bool IndustrialSite::useWater(float units){
    bool usedAll = true;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if (!(*it)->useWater(units))
        {
            usedAll = false;
        }
    }

    if(!usedAll)
        cout << "Could not use " << units << " of water in all the buildings\n";
    else
        cout << "Used " << units << " of water in all the buildings\n";

    return usedAll;
}

float IndustrialSite::getPrice(){
    return value;
}

string IndustrialSite::getType(){
    return type;
}

void IndustrialSite::demolish(){
    cout << "Demolishing all the buildings in the IndustrialSite\n";
    for (vector<Industrial*>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        delete(*it);
        (*it) = nullptr;
    }

    cout << "Demolished  all the buildings in the IndustrialSite\n";
}

bool IndustrialSite::clean(){
    bool usedAll = true;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        if(!(*it)->clean())
        {
            usedAll = false;
        }
    }

    if (!usedAll)
        cout << "Could not clean all the buildings\n";
    else
        cout << "Cleaned all the buildings\n";

    return usedAll;
}

bool IndustrialSite::addOccupant(Citizen* c){
    if (c != nullptr)
    {
        for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if ((*it)->addOccupant(c))
            {
                return true;
            }
        }
    }
    
    return false;
}

Building *IndustrialSite::clone()
{
    IndustrialSite* newIndustrialSite = new IndustrialSite();

    for(vector<Industrial* >::iterator it = buildings.begin(); it != buildings.end(); it++){
        newIndustrialSite->addBuilding((Industrial*)(*it)->clone());
    }

    return newIndustrialSite;
}

IndustrialSite::~IndustrialSite(){
    demolish();
    cout << "Destroyed the IndustrialSite\n";
}

int IndustrialSite::getNoBuildings()
{
    return noBuildings;
}

bool IndustrialSite::addBuilding(Industrial *building)
{
    if(building!= nullptr){
        if(building->getType() == "Plant"){
            int plantBuildings = ((Plant*)building)->getNoBuildings();
            if (plantBuildings+noBuildings <= capacity)
            {
                buildings.push_back(building);
                noBuildings += plantBuildings;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cout << "Plant added to the Industrial Site" << endl;
                return true;
            }
            else{
                cout << "Plant could not be added to the Industrial Site" << endl;
                return false;
            }
        }
        else{
            if(noBuildings + 1 <= capacity){
                buildings.push_back(building);
                noBuildings++;
                value += building->getValue();
                waterUnits += building->getWater();
                electricityUnits += building->getElectricity();
                cleanliness = (cleanliness + building->getCleanliness()) / noBuildings;
                cout << "Building added to the Industrial Site" << endl;
                return true;
            }
            else{
                cout << "Building could not be added to the Industrial Site" << endl;
                return false;
            }
        }
    }

    cout << "Building is non-existent" << endl;
    return false;
}

bool IndustrialSite::removeBuilding(Industrial *building)
{
    vector<Industrial *>::iterator first = buildings.begin();
    vector<Industrial *>::iterator last = buildings.end();

    vector<Industrial *>::iterator it = find(first, last, building);
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
        cout << "Building removed from the Industrial Site" << endl;
        return true;
    }

    cout << "Building not in the Industrial Site" << endl;
    return false;
}

bool IndustrialSite::removeOccupant(Citizen *c)
{
    for (vector<Industrial*>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if((*it)->removeOccupant(c)){
            cout << "Citizen removed\n";
            return true;
        }
    }

    cout << "Citizen was not found in any of the buildings in the IndustrialSite\n";
    return false;
    
}

Building *IndustrialSite::clone()
{
    IndustrialSite *newBuilding = new IndustrialSite();
    newBuilding->cleanliness = this->getCleanliness();
    newBuilding->electricityUnits = this->getElectricity();
    newBuilding->waterUnits = this->getWater();
    newBuilding->area = this->area;
    newBuilding->capacity = this->capacity;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        newBuilding->addBuilding((Industrial *)(*it)->clone());
    }
    newBuilding->state = this->state->clone();
    return newBuilding;
}

float IndustrialSite::getCleanliness()
{
    int count = 0;
    int accumCleanliness = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumCleanliness += (*it)->getCleanliness();
        count++;
    }
    cleanliness = accumCleanliness;
    return cleanliness;
}

float IndustrialSite::getWater()
{
    int accumWater = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumWater += (*it)->getWater();
    }
    waterUnits = accumWater;
    return waterUnits;
}

float IndustrialSite::getElectricity()
{
    int accumElec = 0;
    for (vector<Industrial *>::iterator it = buildings.begin(); it != buildings.end(); ++it)
    {
        accumElec += (*it)->getElectricity();
    }
    electricityUnits = accumElec;
    return electricityUnits;
}

int IndustrialSite::getNoBuildings()
{
    return noBuildings;
}

bool IndustrialSite::isOccupied()
{
    for (vector<Industrial *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->isOccupied())
        {
            return false;
        }
    }

    return true;
}