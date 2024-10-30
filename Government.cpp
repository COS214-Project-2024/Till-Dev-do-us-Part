#include "Government.h"

Government* Government::instance = nullptr;

Government::Government() {
    
    
}
Memento* Government::createMemento() {
    return new Memento();
}

void Government::setMemento(Memento* memento) {
    this->memento = memento;
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
   
    for (auto it = policies.begin(); it != policies.end(); ) {
        if ((*it)->getName() == name) {
            delete *it;////yes?
            it = policies.erase(it);  
        } else {
            ++it;  
        }
    }
}
void Government::addDepartment(std::string name, Department* department)
{
    departments[name]=department;
    std::cout << "Added " << name << " Department to Government" << std::endl; 
}

void Government::removeDepartment(std::string name)
{
    auto it = departments.find(name);
    if (it != departments.end()) {
       departments.erase(it) ;
    } 

}


