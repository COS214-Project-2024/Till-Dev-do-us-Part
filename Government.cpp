#include "Government.h"

#include <iostream>

Government* Government::instance = nullptr;

Government::Government() {
    
    
}

Government* Government::getInstance() {
    if (instance == nullptr) {
        instance = new Government();
    }
    return instance;
}

Department* Government::getDepartment(const std::string& name) {
    if (departments.find(name) != departments.end()) {
        return departments[name];
    }
    return nullptr;
}

void Government::enactPolicy(const Policy& policy) {
    // policies.push_back(policy);
    
}

void Government::revertPolicy(const std::string& name) {
   
    // for (auto it = policies.begin(); it != policies.end(); ) {
    //     if (it->getName() == name) {
    //         it = policies.erase(it);  
    //     } else {
    //         ++it;  
    //     }
    // }
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



