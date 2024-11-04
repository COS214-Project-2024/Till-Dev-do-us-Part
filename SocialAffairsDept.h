/**
 * @file SocialAffairsDept.h
 * @brief Header file for the SocialAffairsDept class, which manages citizens in a social affairs department.
 * 
 * This file declares the SocialAffairsDept class, responsible for managing citizens, 
 * including employment, housing, and population growth within the department.
 * 
 * Author: Karabo
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
 * @brief Class representing the social affairs department responsible for managing citizens and their employment.
 * 
 * This class provides methods to handle employment, track homeless citizens, 
 * increase the population, and assess citizen satisfaction within the social affairs department.
 */
class SocialAffairsDept : public Department {
    
private:
    list<Citizen*> adults;              ///< List of adult citizens within the department.
    list<Citizen*> children;            ///< List of child citizens within the department.
    queue<Citizen*> unemployed;         ///< Queue of unemployed citizens looking for jobs.
    Population* factory;                ///< Factory for creating new citizens.

public:
    /**
     * @brief Constructor for the SocialAffairsDept class.
     * 
     * Initializes the department with a specified budget.
     * 
     * @param b Initial budget for the department.
     */
    SocialAffairsDept(float b);

    /**
     * @brief Employs a citizen from the unemployed queue.
     * 
     * If there are citizens in the unemployed queue, this method assigns a job to one of them.
     * 
     * @param job The Business instance representing the job to be assigned.
     * @return Citizen* Pointer to the employed Citizen, or nullptr if no citizens are available.
     */
    Citizen* employ(Business* job);

    /**
     * @brief Adds a citizen to the adults list.
     * 
     * Stores an adult citizen in the department's record.
     * 
     * @param citizen Pointer to the Citizen instance to be added.
     */
    void addCitizen(Citizen* citizen);

    /**
     * @brief Adds a citizen to the children list.
     * 
     * Stores a child citizen in the department's record.
     * 
     * @param citizen Pointer to the Citizen instance to be added.
     */
    void addChild(Citizen* citizen);

    /**
     * @brief Adds a citizen to the unemployed queue.
     * 
     * Stores a citizen in the queue of unemployed citizens seeking jobs.
     * 
     * @param person Pointer to the Citizen instance to be added.
     */
    void addToUnemployed(Citizen* person);

    /**
     * @brief Gets the total number of citizens in the department.
     * 
     * Returns the combined count of adult and child citizens.
     * 
     * @return int Total number of citizens in the department.
     */
    int getNumCitizens();

    /**
     * @brief Gets the number of children in the department.
     * 
     * @return int Total number of children.
     */
    int getNumChildren();

    /**
     * @brief Gets the number of unemployed citizens.
     * 
     * @return int Number of unemployed citizens in the queue.
     */
    int getNumUnemployed();

    /**
     * @brief Gets the number of homeless adult citizens.
     * 
     * Returns the count of adults who do not have housing assigned.
     * 
     * @return int Number of homeless adults.
     */
    int getHomeless();

    /**
     * @brief Calculates the satisfaction level of the citizens.
     * 
     * Computes a satisfaction level based on citizen feelings, represented as a percentage.
     * 
     * @return int Satisfaction level in percentage.
     */
    int getSatisfactionLevel();

    /**
     * @brief Sends all employed adults to work.
     * 
     * Iterates over the adults list and calls the goToWork method for each employed citizen.
     */
    void sendAdultsToWork();

    /**
     * @brief Increases the population by creating new adult and child citizens.
     * 
     * Adds a specified number of adult citizens and pairs adults with children when possible.
     * 
     * @param n The number of adults to be added to the population.
     */
    void growPopulation(int n);

    /**
     * @brief Destructor for the SocialAffairsDept class.
     * 
     * Cleans up resources by deleting all citizens and clearing the department's records, preventing memory leaks.
     */
    virtual ~SocialAffairsDept();
};

#endif // SOCIALAFFAIRS_H
