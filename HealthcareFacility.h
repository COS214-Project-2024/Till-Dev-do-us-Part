#ifndef HealthcareFacility_H
#define HealthcareFacility_H
#include <string>
#include "Citizen.h"


class HealthcareFacility {
protected:

    //citizens
    HealthcareFacility* successor;
    int deathtoll;

public:
    HealthcareFacility() ;
    virtual ~HealthcareFacility() = default;

    virtual void admitPatient(Citizen* c)=0;
    
    void dischargePatient(Citizen* c) ;
    virtual void treatPatient(Citizen* c);
    void addSuccessor(HealthcareFacility* s);
    int generateRandomValue();
    int getDeathToll();

    //virtual std::string getType() = 0; 
};
#endif