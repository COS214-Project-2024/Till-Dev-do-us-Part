#include "House.h"

House::House():Residential("House")
{
    value = 10000;
    area = 500;
    capacity = 5;
}

House::~House()
{
    demolish();
    cout << "House demolished!" << endl;
}

void House::demolish(){
    cout << "Removing everyone from the House" << endl;
    occupants.clear();
}

bool House::useShower(){
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(80) && useElectricity(40))
        {
            cout << "House used shower.\n";
            if (cleanliness - 10 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "House is now in Dilapidated state\n";
            }
            else{
                cleanliness -= 10;
            }
            return true;
        }
        cout << "Not enough water or electricity to use shower:" << endl;
        cout << "Required water to shower: 80" << endl;
        cout << "Required electricity to shower: 40" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "House is in " << this->state->getName() << " and cannot use shower" << endl;
    return false;
}

bool House::useToilet(){
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(16) && useElectricity(5))
        {
            cout << "House used toilet.";
            if (cleanliness - 14 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "House is now in Dilapidated state:\n";
                cout << "Cleanliness: " << cleanliness << "\n";
                cout << "Electricity: " << electricityUnits << "\n";
                cout << "Water: " << waterUnits << "\n";
            }
            else{
                cleanliness -= 14;
            }
            return true;
        }
        cout << "Not enough water to use toilet:" << endl;
        cout << "Required electricity for toilet: 5" << endl;
        cout << "Required water for toilet: 16" << endl;
        cout << "Current water: " << waterUnits << endl;
        return false;
    }

    cout << "House is in " << this->state->getName() << " and cannot use Toilet" << endl;
    return false;
}

bool House::useStove(){
    if (this->state->canUseElectricity())
    {
        if (useElectricity(40))
        {
            cout << "House used stove.";
            if(cleanliness - 15 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "House is now in Dilapidated state:\n";
                cout << "Cleanliness: "<< cleanliness<<"\n";
                cout << "Electricity: "<< electricityUnits<<"\n";
                cout << "Water: "<< waterUnits<<"\n";
            }
            else{
                cleanliness -= 15;
            }
            return true;
        }
        cout << "Not enough electricity to use stove:" << endl;
        cout << "Required electricity for stove: 40" << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "House is in " << this->state->getName() << " and use stove" << endl;
    return false;
}

bool House::clean(){
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(200) && useElectricity(40))
        {
            cout << "House cleaned."<< endl;
            if (cleanliness + 30 >= 100)
            {
                cleanliness = 100;
            }
            else{
                if (cleanliness <= 0 && cleanliness + 30 >= 0 && waterUnits > 0 && electricityUnits > 0)
                {
                    delete state;
                    state = new CompleteState();
                    cout << "House now in Operational state\n";
                }
                cleanliness += 30;
            }
            return true;
        }

        cout << "Not enough water or electricity to clean the House:" << endl;
        cout << "Required water to clean: 200" << endl;
        cout << "Required electricity to clean: 40" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "House is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

bool House::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupants.size() < capacity)
        {
            occupants.push_back(c);
            cout << "Occupant added to House" << endl;
            return true;
        }
        else{
            cout << "Occupant could not be added to House, House at capacity" << endl;
            return false;
        }
    }

    cout << "Citizen does not exist" << endl;
    return false;
}

bool House::removeOccupant(Citizen *c){
    vector<Citizen*>::iterator first = occupants.begin();
    vector<Citizen *>::iterator last = occupants.end();

    vector<Citizen *>::iterator it = find(first, last, c);  
    if(it != last){
        occupants.erase(it);
        cout << "Occupant removed from the House" << endl;
        return true;
    }

    cout << "Occupant not in the House" << endl;
    return false;
}

Building *House::clone()
{
    House *newHouse = new House();
    newHouse->cleanliness = this->cleanliness;
    newHouse->electricityUnits = this->electricityUnits;
    newHouse->waterUnits = this->waterUnits;
    newHouse->value = this->value;
    newHouse->area = this->area;
    newHouse->capacity = this->capacity;

    return newHouse;
}

void House::goToWork()
{
    for (vector<Citizen*>::iterator it = occupants.begin(); it < occupants.end(); it++)
    {

        (*it)->goToWork();
    }
}

bool House::isOccupied(){
    return occupants.size()>0;
}
