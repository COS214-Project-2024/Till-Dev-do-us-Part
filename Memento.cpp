#include "Memento.h"
#include "Policy.h"
#include <iostream>

Memento:: Memento()
{
    
}
std::vector<Policy*> Memento::getActivePolicies(){
    std::vector<Policy*> policiesCopy;
    for (Policy* policy : activePolicies) {
        policiesCopy.push_back(new Policy(*policy)); 
    }
    return policiesCopy;
}

void Memento::setActivePolicies(std::vector<Policy*> policies) {
        for (Policy* policy : activePolicies) {
        // if(policy!=nullptr)
        // {
            delete policy;
        // }
    }
    activePolicies.clear();

    for (Policy* policy : policies) {
        activePolicies.push_back(new Policy(*policy));
    }
}

Memento:: ~Memento()
{
    if(activePolicies.empty())
    {
        return;
    }
    for(auto policy:activePolicies)
    {

        delete policy;

    }//not sure about this
    activePolicies.clear();
}
