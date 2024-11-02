#ifndef HOSPITAL2_H
#define HOSPITAL2_H
#include <string>
#include "Citizen.h"
#include "Clinic.h"
#include "HealthcareFacility.h"


class Hospital2: public HealthcareFacility {


public:
    Hospital2() ;
    //~Hospital2();
    void admitPatient(Citizen* c); 
};
#endif
