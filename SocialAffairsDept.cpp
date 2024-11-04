/**
 * @file SocialAffairsDept.cpp
 * @brief Implements the SocialAffairsDept class for managing citizens in a social affairs department.
 * @author Karabo
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "Citizen.h"      
#include "HaveChild.h"
#include "SocialAffairsDept.h"

using namespace std;

/**
 * @brief Constructor for the SocialAffairsDept class.
 * 
 * @param b Initial budget for the department.
 */
SocialAffairsDept::SocialAffairsDept(float b) {
    budget = b;
}

/**
 * @brief Employs a citizen from the unemployed queue.
 * 
 * This method checks if there are any unemployed citizens and assigns a job to the first one in the queue.
 * 
 * @param job The Business instance representing the job to be assigned.
 * @return Citizen* Pointer to the employed Citizen, or nullptr if no citizens are available.
 */
Citizen* SocialAffairsDept::employ(Business* job) {
    // cout << "Entering employ" << endl;

    if (!unemployed.empty()) {
        // cout << "Employing citizen..." << endl;
        Adult* employee = (Adult*)(unemployed.front());
        employee->setJob(job);
        unemployed.pop();
        return (Citizen*) employee;
    } else {
        std::cout << "There are no citizens to employ " << std::endl;
        return nullptr;
    }
}

/**
 * @brief Adds a citizen to the adults vector.
 * 
 * This method stores an adult citizen in the department's records.
 * 
 * @param citizen Pointer to the Citizen instance to be added.
 */
void SocialAffairsDept::addCitizen(Citizen* citizen) {
    adults.push_back(citizen);
    // cout << "Added new adult to adults vector " << endl;
}

/**
 * @brief Adds a citizen to the children vector.
 * 
 * This method stores a child citizen in the department's records.
 * 
 * @param citizen Pointer to the Citizen instance to be added.
 */
void SocialAffairsDept::addChild(Citizen* citizen) {
    children.push_back(citizen);
    // cout << "Added new child to children vector " << endl;
}

/**
 * @brief Adds a citizen to the unemployed queue.
 * 
 * @param person Pointer to the Citizen instance to be added.
 */
void SocialAffairsDept::addToUnemployed(Citizen* person) {
    if (person == nullptr)
        cout << "PERSON IS NULL" << endl;
    unemployed.push(person);
    // cout << "Added new adult to unemployed queue " << endl;
}

/**
 * @brief Gets the total number of citizens (adults + children).
 * 
 * @return int Total number of citizens in the department.
 */
int SocialAffairsDept::getNumCitizens() {
    return (adults.size() + children.size());
}


int SocialAffairsDept::getNumUnemployed(){
    return unemployed.size();
}

void SocialAffairsDept::sendAdultsToWork(){

    cout << "Citizens going to work." << endl;
    for (auto adult : adults) {
        if(((Adult*)adult)->employmentStatus())
            ((Adult*)adult)->goToWork();
    }
}


/**
 * @brief Increases the population by creating new adult and child citizens.
 * 
 * This method generates new adults and pairs them with parents to create children.
 * 
 * @param n The number of adults to be added to the population.
 */
void SocialAffairsDept::growPopulation(int n) {
    factory = new AdultPop();
    Citizen** community = factory->reproduce(n);

    for (int i = 0; i < n; i++) {
        addCitizen(community[i]);
    }

    delete[] community;
    delete factory;

    factory = new MinorPop();

    int num = 0;
    auto it = adults.begin();

    for (int i = 0; it != adults.end(); ++it, i += 2) {
        if ((i % 3) != 0)
            continue;

        num++;
        HaveChild* parent = new HaveChild(*it);
        Citizen* child = factory->getPerson();
        parent->haveChild(child);
        addChild(child);
        *it = (Citizen*) parent;
    }

    delete factory;
    cout << "Increased current population by 10 adults and " << num << " kids" << endl;
}

int SocialAffairsDept::getSatisfactionLevel(){

    int N,C,D;

    for (auto adult : adults) {
        if(((Citizen*)adult)->getFeeling() == "Content")
            C++;
        if(((Citizen*)adult)->getFeeling() == "Distraught")
            D++;
        if(((Citizen*)adult)->getFeeling() == "Distraught"){
            N++;
        }
    }

    return ((C/(C+N+D))*100);
}

/**
 * @brief Destructor for the SocialAffairsDept class.
 * 
 * Cleans up resources by deleting all citizens and clearing the department's records.
 */
SocialAffairsDept::~SocialAffairsDept() {
    while (!unemployed.empty()) {
        Citizen* employee = unemployed.front();
        employee = nullptr;  
        unemployed.pop();  
    }

    for (auto adult : adults) {
        delete adult;
        adult = nullptr;  
    }

    for (auto child : children) {
        delete child;
        child = nullptr;  
    }

    adults.clear();
    children.clear();  
    factory = nullptr;
}