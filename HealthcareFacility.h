#ifndef HealthcareFacility_H
#define HealthcareFacility_H
#include <string>
#include "Citizen.h"

/**
 * @class HealthcareFacility
 * @brief Abstract class for healthcare facilities providing patient admission and treatment.
 */
class HealthcareFacility
{
protected:
    HealthcareFacility *successor; /**< Pointer to the next facility in the chain of responsibility. */
    int deathtoll;                 /**< Tracks the number of deaths in the facility. */

public:
    /**
     * @brief Default constructor initializes successor and deathtoll.
     */
    HealthcareFacility();

    /**
     * @brief Virtual destructor.
     */
    virtual ~HealthcareFacility() { successor = nullptr; }

    /**
     * @brief Pure virtual method to admit a patient.
     * @param c Pointer to the Citizen being admitted.
     */
    virtual void admitPatient(Citizen*& c) = 0;

    /**
     * @brief Discharges a patient after treatment.
     * @param c Pointer to the Citizen being discharged.
     */
    void dischargePatient(Citizen *c);

    /**
     * @brief Treats a patient and determines the outcome.
     * @param c Pointer to the Citizen being treated.
     */
    void treatPatient(Citizen *&c);

    /**
     * @brief Sets the successor facility in the chain of responsibility.
     * @param s Pointer to the successor HealthcareFacility.
     */
    void addSuccessor(HealthcareFacility *s);

    /**
     * @brief Generates a random outcome value for treatment.
     * @return Integer representing the treatment outcome.
     */
    int generateRandomValue();

    /**
     * @brief Gets the death toll of the facility.
     * @return Integer death toll count.
     */
    int getDeathToll();
};

#endif
