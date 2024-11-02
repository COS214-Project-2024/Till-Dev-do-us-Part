#ifndef CLINIC_H
#define CLINIC_H
#include <string>
#include "Citizen.h"
#include "HealthcareFacility.h"


class Clinic: public HealthcareFacility {


public:
    Clinic() ;

    //~Clinic(){};

    void admitPatient(Citizen* c);

};

#endif
