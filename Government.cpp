#include "Government.h"
#include <iostream>

Government* Government::instance = nullptr;

Government::Government() {
    memento=nullptr;
}
void Government::deleteInstance()
{
    
    if(instance!=nullptr)
    {
        delete instance;
        instance=nullptr;
    }
}

Government::~Government() {
    
    if(memento)
    {
        delete memento;/////////
        memento=nullptr;
    }
    for (Policy* policy : policies) {
        delete policy;  // Free each policy
    }
    policies.clear();

    for (auto department : departments) {
        delete department.second;  // Free each department
    }
    departments.clear();


}

Memento* Government::createMemento() {
     memento = new Memento();
    std::vector<Policy*> policiesCopy;
    for (Policy* policy : policies) {
        policiesCopy.push_back(new Policy(*policy));
    }
    memento->setActivePolicies(policiesCopy);


    for (Policy* policy : policiesCopy) {
        delete policy;  // Free each policy
    }
    policiesCopy.clear();
    return memento;
}

void Government::setMemento(Memento* memento) {
    if(memento=nullptr)
    {
        return;
    }
        for (Policy* policy : policies) {
        //delete policy;
    }
    policies.clear();

    // Get copy of policies from memento
    std::vector<Policy*> restoredPolicies = memento->getActivePolicies();
    policies = restoredPolicies;  // Assign the new policies
}

Government* Government::getInstance() {
    if (instance == nullptr) {
        instance = new Government();
    }
    return instance;
}

Department* Government::getDepartment(std::string name) {
    if (departments.find(name) != departments.end()) {
        return departments[name];
    }
    return nullptr;
}

void Government::enactPolicy(Policy* policy) {
    policies.push_back(policy);
    
}

void Government::revertPolicy(std::string name) {
   
    if(policies.empty())
    {
        return;
    }
    for (auto it = policies.begin(); it != policies.end(); ) {
        if ((*it)->getName() == name) {
            //delete *it;////yes?
            it = policies.erase(it);  
        } else {
            ++it;  
        }
    }
}
void Government::addDepartment(std::string name, Department* department)
{
    departments[name]=department;
    std::cout << "  Added " << name << " Department to Government" << std::endl; 
}

void Government::removeDepartment(std::string name)
{
    auto it = departments.find(name);
    if (it != departments.end()) {
       departments.erase(it) ;
    } 

}
std::vector<Policy*> Government::getPolicies()
{
    return policies;
}




