#ifndef Hospital2_H
#define Hospital2_H
#include <string>
#include "Citizen.h"
#include "HealthcareFacility.h"


class Hospital2: public HealthcareFacility {


public:
    Hospital2() ;
    ~Hospital2();
    void admitPatient(Citizen* c); 
};
#endif
