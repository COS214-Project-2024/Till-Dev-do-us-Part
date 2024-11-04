/**
 * @file SocialAffairsDept.cpp
 * @brief Implements the SocialAffairsDept class for managing citizens in a social affairs department.
 * 
 * This file defines the methods for managing adult and child citizens, assigning jobs, tracking employment and housing status,
 * and managing population growth.
 * 
 * Author: Karabo
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
 * Initializes the department's budget with the provided value.
 * 
 * @param b Initial budget for the department.
 */
SocialAffairsDept::SocialAffairsDept(float b) {
    budget = b;
}

/**
 * @brief Employs a citizen from the unemployed queue.
 * 
 * If there are unemployed citizens, this method assigns a job to the first citizen in the queue.
 * 
 * @param job The Business instance representing the job to be assigned.
 * @return Citizen* Pointer to the employed Citizen, or nullptr if no citizens are available.
 */
Citizen* SocialAffairsDept::employ(Business* job) {
    if (!unemployed.empty()) {
        // Assign job to the first unemployed adult in the queue.
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
 * This method stores an adult citizen in the department's records for future reference.
 * 
 * @param citizen Pointer to the Citizen instance to be added.
 */
void SocialAffairsDept::addCitizen(Citizen* citizen) {
    adults.push_back(citizen);
}

/**
 * @brief Adds a citizen to the children vector.
 * 
 * This method stores a child citizen in the department's records for future reference.
 * 
 * @param citizen Pointer to the Citizen instance to be added.
 */
void SocialAffairsDept::addChild(Citizen* citizen) {
    children.push_back(citizen);
}

/**
 * @brief Reacts to a policy change within the department.
 * 
 * This method iterates over the list of adult citizens, calling the react() method
 * for each. The react() method triggers each adult's individual response to recent 
 * policy changes, which could affect their behavior or state, such as employment 
 * status or satisfaction levels.
 */
void SocialAffairsDept::reactPolicy() {
    for (auto adult : adults) 
        adult->react();
}

/**
 * @brief Adds a citizen to the unemployed queue.
 * 
 * This queue maintains a record of citizens who are currently unemployed and seeking jobs.
 * 
 * @param person Pointer to the Citizen instance to be added.
 */
void SocialAffairsDept::addToUnemployed(Citizen* person) {
    if (person == nullptr)
        cout << "PERSON IS NULL" << endl;
    unemployed.push(person);
}

/**
 * @brief Gets the total number of citizens (adults only).
 * 
 * @return int Total number of adult citizens in the department.
 */
int SocialAffairsDept::getNumCitizens() {
    return adults.size();
}

/**
 * @brief Gets the total number of children in the department.
 * 
 * @return int Number of child citizens in the department.
 */
int SocialAffairsDept::getNumChildren() {
    return children.size();
}

/**
 * @brief Gets the number of unemployed citizens.
 * 
 * @return int Number of citizens in the unemployed queue.
 */
int SocialAffairsDept::getNumUnemployed() {
    return unemployed.size();
}

/**
 * @brief Gets the count of homeless adults.
 * 
 * @return int Number of adults without assigned housing.
 */
int SocialAffairsDept::getHomeless() {
    int num = 0;

    for (auto adult : adults) {
        if (!((Adult*)adult)->hasHouse())
            num++;
    }

    return num;
}

/**
 * @brief Sends employed adults to work.
 * 
 * This method iterates through the adults vector and invokes the goToWork method for each employed citizen.
 */
void SocialAffairsDept::sendAdultsToWork() {
    cout << "Citizens going to work." << endl;
    for (auto adult : adults) {
        if (((Adult*)adult)->employmentStatus())
            ((Adult*)adult)->goToWork();
    }
}

/**
 * @brief Increases the population by creating new adult and child citizens.
 * 
 * This method creates new adult citizens and assigns parents to children. It pairs adults with the potential to have children.
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

    // Iterate through the adults and pair some with children
    for (int i = 0; it != adults.end(); ++it, i += 2) {
        if ((i % 3) != 0)  // Conditional pairing for varied family sizes
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

/**
 * @brief Calculates the satisfaction level of the citizens.
 * 
 * Satisfaction is derived from the feelings of the citizens and expressed as a percentage.
 * 
 * @return int Satisfaction level in percentage.
 */
int SocialAffairsDept::getSatisfactionLevel() {
    int N = 0, C = 0, D = 0;

    for (auto adult : adults) {
        string feeling = ((Citizen*)adult)->getFeeling();
        if (feeling == "Content") C++;
        if (feeling == "Distraught") D++;
        if (feeling == "Neutral") N++;
    }

    return ((C * 100) / (C + N + D));
}

/**
 * @brief Destructor for the SocialAffairsDept class.
 * 
 * Cleans up resources by deleting all citizens and clearing the department's records, ensuring no memory leaks.
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
