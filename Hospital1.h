#ifndef Hospital1_H
#define Hospital1_H
#include <string>
#include "Citizen.h"
#include "Clinic.h"
#include "HealthcareFacility.h"


class Hospital1: public HealthcareFacility {

    public:
        Hospital1() ;
        ~Hospital1(){};
        void admitPatient(Citizen* c);

};

#endif
