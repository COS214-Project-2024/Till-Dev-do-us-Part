#include "HealthcareFacility.h"
#include <iostream>
#include <random>

/**
 * @brief Default constructor initializes successor to nullptr and death toll to zero.
 */
HealthcareFacility::HealthcareFacility()
{
    successor = nullptr;
    deathtoll = 0;
}

/**
 * @brief Adds a successor facility for treatment delegation.
 * @param s Pointer to the successor HealthcareFacility.
 */
void HealthcareFacility::addSuccessor(HealthcareFacility* s)
{
    if (s != this)
    {
        successor = s;
    }
}

/**
 * @brief Treats a patient by attempting discharge or increasing death toll.
 * @param c Pointer to the Citizen being treated.
 */
void HealthcareFacility::treatPatient(Citizen*& c)
{
    int outcome = generateRandomValue();
    if (outcome == 1 || outcome == 2)
    {
        dischargePatient(c);
    }
    else
    {
        std::cout << "Citizen died, RIP\n";
        deathtoll++;
        c = nullptr; // Mark as deceased
    }
}

/**
 * @brief Discharges a patient and sets their health to 100.
 * @param c Pointer to the Citizen being discharged.
 */
void HealthcareFacility::dischargePatient(Citizen* c)
{
    c->setHealth(100);
}

/**
 * @brief Generates a random integer between 1 and 3 to simulate treatment outcome.
 * @return A random integer between 1 and 3.
 */
int HealthcareFacility::generateRandomValue()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(1, 3);
    return dist(gen);
}

/**
 * @brief Gets the total number of deaths recorded at the facility.
 * @return The death toll as an integer.
 */
int HealthcareFacility::getDeathToll()
{
    return deathtoll;
}
