#ifndef CLINIC_H
#define CLINIC_H
#include <string>
#include "Citizen.h"
#include "HealthcareFacility.h"

/**
 * @class Clinic
 * @brief A healthcare facility that provides admission and treatment for patients.
 */
class Clinic : public HealthcareFacility {
public:
    /**
     * @brief Default constructor initializes Clinic.
     */
    Clinic();

    /**
     * @brief Admits a patient if their health is within the treatment range.
     * @param c Pointer to the Citizen being admitted.
     */
    void admitPatient(Citizen*& c);
};

#endif
