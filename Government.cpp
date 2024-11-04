#include "Government.h"
#include <iostream>

/**
 * @brief Initializes the Government singleton instance if not already created.
 * @return A pointer to the singleton Government instance.
 */
Government* Government:: instance=nullptr;

Government::Government() {
    memento=nullptr;

}

Government* Government::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Government();
    }
    return instance;
}

/**
 * @brief Deletes the singleton instance if it exists.
 */
void Government::deleteInstance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

/**
 * @brief Destructor for Government. Cleans up policies and departments.
 */
Government::~Government()
{
    if(memento)
    {
        delete memento;
        memento = nullptr;
    }

    for (Policy* policy : policies)
    {
        delete policy;
    }
    policies.clear();

    for (auto department : departments)
    {
        delete department.second;
    }
    departments.clear();
}

/**
 * @brief Creates a memento to store the current state of policies.
 * @return A pointer to the created Memento object.
 */
Memento* Government::createMemento()
{
    memento = new Memento();
    std::vector<Policy*> policiesCopy;
    for (Policy* policy : policies)
    {
        policiesCopy.push_back(new Policy(*policy));
    }
    memento->setActivePolicies(policiesCopy);

    for (Policy* policy : policiesCopy)
    {
        delete policy;
    }
    policiesCopy.clear();
    return memento;
}

/**
 * @brief Sets policies from a given memento to restore a previous state.
 * @param memento Pointer to the Memento containing policies to restore.
 */
void Government::setMemento(Memento* memento)
{
    policies.clear();
    std::vector<Policy*> restoredPolicies = memento->getActivePolicies();
    policies = restoredPolicies;
}

/**
 * @brief Adds a new department to the Government.
 * @param name Name of the department.
 * @param department Pointer to the Department being added.
 */
void Government::addDepartment(std::string name, Department* department)
{
    departments[name] = department;
    std::cout << "  Added " << name << " Department to Government" << std::endl;
}

/**
 * @brief Enacts a new policy by adding it to the government's list of policies.
 * @param policy Pointer to the Policy object being enacted.
 */
void Government::enactPolicy(Policy* policy) {
    policies.push_back(policy);
    ((SocialAffairsDept *)(getDepartment("SocialAffairs")))->reactPolicy();
}

/**
 * @brief Reverts a policy by removing it from the list of active policies based on its name.
 * @param name The name of the policy to revert.
 * 
 * If the policy with the specified name exists in the list, it will be removed.
 */
void Government::revertPolicy(std::string name) {
    if (policies.empty()) {
        return;
    }
    for (auto it = policies.begin(); it != policies.end(); ) {
        if ((*it)->getName() == name) {
            // Uncomment the next line if ownership and deletion of policies is required.
            // delete *it; 
            it = policies.erase(it);  
        } else {
            ++it;  
        }
    }
    
}

/**
 * @brief Removes a department from the government by name.
 * @param name The name of the department to remove.
 * 
 * If the department with the specified name exists, it is removed from the list of departments.
 */
void Government::removeDepartment(std::string name) {
    auto it = departments.find(name);
    if (it != departments.end()) {
        departments.erase(it);
    } 
}

/**
 * @brief Retrieves a department by its name.
 * @param name The name of the department to retrieve.
 * @return Pointer to the Department object if found, otherwise nullptr.
 */
Department* Government::getDepartment(std::string name) {
    if (departments.find(name) != departments.end()) {
        return departments[name];
    }
    return nullptr;
}
