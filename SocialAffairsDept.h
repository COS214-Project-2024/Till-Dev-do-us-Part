/**
 * @file SocialAffairsDept.h
 * @brief Header file for the SocialAffairsDept class, which manages citizens in a social affairs department.
 * @author Karabo
 */

#ifndef SOCIALAFFAIRS_H
#define SOCIALAFFAIRS_H

#include <queue>
#include <list>
#include "Department.h"
#include "Citizen.h"
#include "AdultPop.h"
#include "MinorPop.h"
#include "Business.h"

using namespace std;

/**
 * @class SocialAffairsDept
 * @brief Class representing the social affairs department managing citizens and their employment.
 */
class SocialAffairsDept : public Department {
    
private:
    list<Citizen*> adults;              ///< List of adult citizens.
    list<Citizen*> children;            ///< List of child citizens.
    queue<Citizen*> unemployed;         ///< Queue of unemployed citizens.
    Population* factory;                ///< Factory for creating citizens.

public:
    /**
     * @brief Constructor for the SocialAffairsDept class.
     * 
     * @param b Initial budget for the department.
     */
    SocialAffairsDept(float b);

    /**
     * @brief Employs a citizen from the unemployed queue.
     * 
     * @param job The Business instance representing the job to be assigned.
     * @return Citizen* Pointer to the employed Citizen, or nullptr if no citizens are available.
     */
    Citizen* employ(Business* job);

    /**
     * @brief Adds a citizen to the adults vector.
     * 
     * @param citizen Pointer to the Citizen instance to be added.
     */
    void addCitizen(Citizen* citizen);

    /**
     * @brief Adds a citizen to the children vector.
     * 
     * @param citizen Pointer to the Citizen instance to be added.
     */
    void addChild(Citizen* citizen);

    /**
     * @brief Adds a citizen to the unemployed queue.
     * 
     * @param person Pointer to the Citizen instance to be added.
     */
    void addToUnemployed(Citizen* person);

    /**
     * @brief Gets the total number of citizens (adults + children).
     * 
     * @return int Total number of citizens in the department.
     */
    int getNumCitizens();

    int getNumUnemployed();

    int getSatisfactionLevel();

    void sendAdultsToWork();

    /**
     * @brief Increases the population by creating new adult and child citizens.
     * 
     * @param n The number of adults to be added to the population.
     */
    void growPopulation(int n);

    /**
     * @brief Destructor for the SocialAffairsDept class.
     * 
     * Cleans up resources by deleting all citizens and clearing the department's records.
     */
    virtual ~SocialAffairsDept();
};

#endif // SOCIALAFFAIRS_H