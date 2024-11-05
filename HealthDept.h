#ifndef HealthDept_H
#define HealthDept_H
#include <map>
#include "Department.h"
#include "HealthcareFacility.h"

/**
 * @class HealthDept
 * @brief Represents a health department responsible for managing healthcare facilities and patient admissions.
 */
class HealthDept : public Department {
private:
    std::map<std::string, HealthcareFacility*> facilities; /**< Map of facility names to their corresponding healthcare facilities. */

public:
    /**
     * @brief Constructs a HealthDept with a specified budget.
     * @param budget Initial budget for the health department.
     */
    HealthDept(float budget);

    /**
     * @brief Adds a healthcare facility to the department.
     * @param name Name of the facility.
     * @param facility Pointer to the HealthcareFacility instance.
     */
    void addFacility(std::string name, HealthcareFacility* facility);

    /**
     * @brief Admits a patient to the appropriate healthcare facility.
     * @param c Pointer to the Citizen instance to admit.
     */
    void admitPatient(Citizen* c);

    /**
     * @brief Calculates and displays the total number of deaths reported by all facilities.
     */
    void totalDeaths();

    /**
     * @brief Destructor for HealthDept, clears all allocated facilities.
     */
    ~HealthDept();
    
    std::map<std::string, HealthcareFacility*> getFacilities()
    {
        return facilities;
    }
};

#endif
