#include "Memento.h"
#include "Policy.h"
#include <iostream>

/**
 * @brief Default constructor for Memento.
 */
Memento::Memento() {}

/**
 * @brief Retrieves a copy of the active policies.
 * @return A vector containing pointers to copied active policies.
 */
std::vector<Policy*> Memento::getActivePolicies() {
    std::vector<Policy*> policiesCopy;
    for (Policy* policy : activePolicies) {
        policiesCopy.push_back(new Policy(*policy)); 
    }
    return policiesCopy;
}

/**
 * @brief Sets active policies to a given list of policies.
 * This function clears the existing active policies and replaces them with copies
 * of the policies in the given list.
 * @param policies A vector of Policy pointers to be set as active policies.
 */
void Memento::setActivePolicies(std::vector<Policy*> policies) {
    for (Policy* policy : activePolicies) {
        delete policy;  // Delete existing policies to avoid memory leaks
    }
    activePolicies.clear();

    for (Policy* policy : policies) {
        activePolicies.push_back(new Policy(*policy)); // Add copies of policies
    }
}

/**
 * @brief Destructor for Memento.
 * Responsible for cleaning up all policies in the active policies list.
 */
Memento::~Memento() {
    for (Policy* policy : activePolicies) {
        delete policy;
    }
    activePolicies.clear();
}
