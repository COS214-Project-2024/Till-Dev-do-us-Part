#include "Hospital.h"

Hospital::Hospital():Public("Hospital"){
    cout << "Hospital created" << endl;
}

Hospital::~Hospital(){
    delete this->state;
    state = nullptr;
    demolish();
    cout << "Hospital demolished" << endl;
}

bool Hospital::addOccupant(Citizen *c){
    if(c != nullptr){
        if(patients.size() < capacity){
            patients.push_back(c);
            cout << "Patient admitted" << endl;
            return true;
        }

        cout << "Patient could not be admitted, hospital at capacity" << endl;
        return false;
    }

    cout << "The citizen ran away or is non-existent" << endl;
    return false;
}

void Hospital::demolish(){
    //TODO: cin to ask it they sure they want to demolish hospital when patients.size > 0
    cout << "Removing patients from hospital" << endl;
    patients.clear();
    cout << "Patients removed" << endl;
}

bool Hospital::clean(){
    if(this->state->canUseWater() && this->state->canUseElectricity()){
        if (useWater(1000) && useElectricity(600)){
            cout << "Hospital cleaned.";
            return true;
        }
        cout << "Not enough water or electricity to clean the hospital:" << endl;
        cout << "Required water to clean: 1000" << endl;
        cout << "Required electricity to clean: 600" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return false;
    }

    cout << "Hospital is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

bool Hospital::removeOccupant(Citizen *c)
{
    vector<Citizen *>::iterator first = patients.begin();
    vector<Citizen *>::iterator last = patients.end();

    vector<Citizen *>::iterator it = find(first, last, c);
    if (it != last)
    {
        patients.erase(it);
        cout << "Patient removed from the Hospital" << endl;
        return true;
    }

    cout << "Patient not in the Hospital" << endl;
    return false;
}

Building *Hospital::clone()
{
    Hospital *newHospital = new Hospital();
    newHospital->cleanliness = this->cleanliness;
    newHospital->electricityUnits = this->electricityUnits;
    newHospital->waterUnits = this->waterUnits;
    newHospital->value = this->value;
    newHospital->area = this->area;
    newHospital->capacity = this->capacity;

    return newHospital;
}

bool Hospital::isOccupied(){
    return patients.size() > 0;
}