#include "Suburb.h"

Suburb::Suburb():Residential("Suburb"){
    area = 10000;
    capacity = 50;
    noBuildings = 0;
    value = 12000;
}

void Suburb::loadElectricity(float units){
    
    for (vector<Residential*>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->loadElectricity(units);
    }
    
}

void Suburb::loadWater(float units){
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        (*it)->loadWater(units);
    }
}

bool Suburb::useElectricity(float units){
    bool usedAll = true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
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

bool Suburb::useWater(float units){
    bool usedAll = true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
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

float Suburb::getPrice(){
    return value;
}

string Suburb::getType(){
    return type;
}

void Suburb::demolish(){
    cout << "Demolishing all the buildings in the suburb\n";
    for (vector<Residential*>::iterator it = buildings.begin(); it != buildings.end(); it++)
    {
        delete(*it);
        (*it) = nullptr;
    }

    cout << "Demolished  all the buildings in the suburb\n";
}

bool Suburb::clean(){
    bool usedAll = true;
    for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
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

bool Suburb::addOccupant(Citizen* c){
    if (c != nullptr)
    {
        for (vector<Residential *>::iterator it = buildings.begin(); it != buildings.end(); it++)
        {
            if ((*it)->addOccupant(c))
            {
                return true;
            }
        }
    }
    
    return false;
}

Building *Suburb::clone()
{
    Suburb* newSuburb = new Suburb();

    for(vector<Residential* >::iterator it = buildings.begin(); it != buildings.end(); it++){
        newSuburb->addBuilding((Residential*)(*it)->clone());
    }

    return newSuburb;
}

Suburb::~Suburb(){
    demolish();
    cout << "Destroyed the suburb\n";
}

int Suburb::getNoBuildings()
{
    return noBuildings;
}

bool Suburb::addBuilding(Residential *building)
{
    if(building!= nullptr){
        if(building->getType() == "Estate"){
            int estateBuildings = ((Estate *)building)->getNoBuildings();
            if (estateBuildings+noBuildings <= capacity)
            {
                buildings.push_back(building);
                noBuildings+=estateBuildings;
                value += building->getValue();
                waterUnits += building->getWater();
                cout << "Estate added to the Suburb" << endl;
                return true;
            }
            else{
                cout << "Estate could not be added to the Suburb" << endl;
                return false;
            }
        }
        else{
            if(noBuildings + 1 <= capacity){
                buildings.push_back(building);
                noBuildings++;
                value += building->getValue();
                cout << "Building added to the Suburb" << endl;
                return true;
            }
            else{
                cout << "Building could not be added to the Suburb" << endl;
                return false;
            }
        }
    }

    cout << "Building is non-existent" << endl;
    return false;
}

bool Suburb::removeOccupant(Citizen *c)
{
    for (vector<Residential*>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if((*it)->removeOccupant(c)){
            cout << "Citizen removed\n";
            return true;
        }
    }

    cout << "Citizen was not found in any of the buildings in the suburb\n";
    return false;
    
}

bool Suburb::useShower(){
    bool usedAll = true;
    for (vector<Residential*>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if(!(*it)->useShower()){
            usedAll = false;
        }
    }

    if(usedAll){
        cout << "Used all Showers in the Suburb\n";
    }
    else{
        cout << "Could not used all Showers in the Suburb\n";
    }
    
}

bool Suburb::useToilet(){
    bool usedAll = true;
    for (vector<Residential*>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if(!(*it)->useToilet()){
            usedAll = false;
        }
    }

    if(usedAll){
        cout << "Used all Toilets in the Suburb\n";
    }
    else{
        cout << "Could not used all Toilets in the Suburb\n";
    }
    
}

bool Suburb::useStove(){
    bool usedAll = true;
    for (vector<Residential*>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if(!(*it)->useStove()){
            usedAll = false;
        }
    }

    if(usedAll){
        cout << "Used all Stoves in the Suburb\n";
    }
    else{
        cout << "Could not used all Stoves in the Suburb\n";
    }
    
}

void Suburb::goToWork(){
    for (vector<Residential*>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        (*it)->goToWork();
    }

    cout << "Took all citizens in the Suburb to work\n";    
}

bool Suburb::isOccupied()
{
    for (vector<Residential *>::iterator it = buildings.begin(); it < buildings.end(); it++)
    {
        if ((*it)->isOccupied())
        {
            return false;
        }
    }

    return true;
}