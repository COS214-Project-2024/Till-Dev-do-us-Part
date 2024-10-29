#include "HealthDept.h"
#include <iostream>

HealthDept:: HealthDept(float budget)
{
    this->budget=budget;
}
void HealthDept::addFacility(std:: string name,HealthcareFacility* facility)
{
    if(budget<=0)
    {
        std::cout<<"No budget to build Health Facility\n";
    }
        facilities[name]=facility;
        budget-=500;//for now
    
}
void HealthDept::admitPatient(Citizen* c)
{

    auto clinicIt = facilities.find("Clinic");

    if (clinicIt != facilities.end()) {  // Check if a clinic facility exists
        HealthcareFacility* clinic = clinicIt->second;

            clinic->admitPatient(c);
            return;

    }
        
}