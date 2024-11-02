#include "TransportFacilities.h"

// Constructor definition, matching the declaration in the header
TransportFacilities::TransportFacilities(TransState* state)
    : currentState(state) {}

void TransportFacilities::setState(TransState* newState) {
   if (currentState) delete currentState;
    currentState = nullptr;
    currentState = newState;
    notifyCitizens();

}
void TransportFacilities::decreaseTraffic()
{
    int elementsToDelete = 6; 
    for(int i=0; i< elementsToDelete && i < moVec.size(); i++){
        moVec.at(i)->divertingRoute();//come back 
    }
}
 int TransportFacilities::getModeCount()
 {
    return moVec.size();
 }

TransState* TransportFacilities:: getState()
{
    return this->currentState;
}

void TransportFacilities::add(TransportMode* momo){
    moVec.push_back(momo);
    currentState->changeState();

 }
void TransportFacilities::remove(TransportMode* momo){
      auto it = std::find(moVec.begin(), moVec.end(), momo);
    if (it != moVec.end()) {
        moVec.erase(it);
        currentState->changeState();  // Reevaluate state whenever a plane is removed
    }
}

int TransportFacilities::GetModeCount(){
    return moVec.size();
}

std::vector<TransportMode*> TransportFacilities::GetModes(){
    return moVec;
}

void TransportFacilities::notifyCitizens()
{
    for(auto citizen:citizens)
    {
        citizen->react();/////fix thix
    }
}
void TransportFacilities::attach(Citizen* c)
{
    citizens.push_back(c);
}
void TransportFacilities::detach(Citizen* c)
{
    citizens.erase(std::remove(citizens.begin(),citizens.end(),c),citizens.end());
}