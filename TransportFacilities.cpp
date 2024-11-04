#include "TransportFacilities.h"
#include "TransportMode.h"

TransportFacilities::TransportFacilities() :moVec{}{  

}

std:: string TransportFacilities::getFacilName(){
    return name;
}

TransportFacilities:: ~TransportFacilities(){
    for (auto momo : moVec) {
        delete momo;
    }
    moVec.clear();

    citizens.clear();

    delete currentState;
    currentState = nullptr;


}

void TransportFacilities::setState(TransState* newState) {
   
    if(newState != nullptr){
        
        if (currentState->getStateName() != newState->getStateName()){
          
            std::cout << "Now in:"<<currentState->getStateName() <<"\n";
            delete currentState;
          
            currentState = newState;
           
            notifyCitizens();
           
            return;
        } 
        
        return;

    }
}
void TransportFacilities::decreaseTraffic()
{
    int elementsToDelete = 6; 
    

    for(int i=0; i< elementsToDelete && i < moVec.size(); i++){
       
        moVec.at(i)->stopdrive();//come back 
        
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



void TransportFacilities::add(TransportMode* momo) {
    
    if (!momo) {
        std::cout << "momo is nullptr" << std::endl;
        return;
    }

    if (dynamic_cast<TransportMode*>(momo) == nullptr) {
        std::cout << "momo is not a valid TransportMode instance" << std::endl;
        return;
    }
    
    try {
        
        moVec.push_back(momo);
         
       
    } catch (const std::exception& e) {
        std::cerr << "Error while adding to moVec: " << e.what() << std::endl;
    }

    
    
   
    std::cout << currentState->getStateName()<< std::endl;
    if (currentState != nullptr)  {
        
        currentState->changeState();
    } else {
        std::cout << "currentState is nullptr" << std::endl;
    }


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