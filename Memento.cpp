#include "Memento.h"

// float Memento::getBudget() const {
//     return budget;
// }

// void Memento::setBudget(float budget) {
//     this->budget = budget;
// }

std::vector<Policy*> Memento::getActivePolicies(){
    return activePolicies;
}

void Memento::setActivePolicies(const std::vector<Policy*> policies) {
    activePolicies = policies;
}
