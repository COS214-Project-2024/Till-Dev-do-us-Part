#ifndef Hospital1_H
#define Hospital1_H
#include <string>
#include "Citizen.h"
#include "HealthcareFacility.h"

/**
 * @class Hospital1
 * @brief Represents a mid-level healthcare facility for treating moderately ill patients.
 */
class Hospital1 : public HealthcareFacility {
public:
    /**
     * @brief Default constructor initializes Hospital1.
     */
    Hospital1();

    /**
     * @brief Admits a patient if their health is within the treatment range for this facility.
     * @param c Pointer to the Citizen being admitted.
     */
    void admitPatient(Citizen*& c);
};

#endif
