#ifndef HOSPITAL2_H
#define HOSPITAL2_H
#include <string>
#include "Citizen.h"
#include "HealthcareFacility.h"

/**
 * @class Hospital2
 * @brief Represents an advanced healthcare facility for critically ill patients.
 */
class Hospital2 : public HealthcareFacility
{
public:
    /**
     * @brief Default constructor initializes Hospital2.
     */
    Hospital2();

    /**
     * @brief Admits a patient if their health is within the treatment range for critical cases.
     * @param c Pointer to the Citizen being admitted.
     */
    void admitPatient(Citizen*& c);
};

#endif
