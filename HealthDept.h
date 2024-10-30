#ifndef HealthDept_H
#define HealthDept_H
#include <map>

#include "Department.h"
#include "HealthcareFacility.h"

class HealthDept : public Department {
private:
    std::map<std::string,HealthcareFacility*> facilities;
public:
    HealthDept(float budget);
    void addFacility(std:: string name,HealthcareFacility* facility);
    void admitPatient(Citizen* c);
    void totalDeaths();
    ~HealthDept();
    
};

#endif 
