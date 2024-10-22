#include "Government.h"

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
    policies.push_back(policy);
    
}

void Government::revertPolicy(const std::string& name) {
   
    for (auto it = policies.begin(); it != policies.end(); ) {
        if (it->getName() == name) {
            it = policies.erase(it);  
        } else {
            ++it;  
        }
    }
}



