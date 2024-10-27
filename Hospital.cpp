#include "Hospital.h"

Hospital::Hospital():Public("Hospital"){
    cout << "Hospital created" << endl;
}

Hospital::~Hospital(){
    demolish();
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
