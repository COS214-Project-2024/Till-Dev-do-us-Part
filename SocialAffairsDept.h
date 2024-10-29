#ifndef SOCIALAFFAIRSDEPT_H
#define SOCIALAFFAIRSDEPT_H
#include <vector>
#include "Department.h"
#include "Citizen.h"

class SocialAffairsDept : public Department {

private: 
    std::vector<Citizen*> citizens;
    std::vector<Citizen*> unemployed;
    std::vector<Citizen*> employed;
    std::vector<Citizen*> minors;
    
public:
    SocialAffairsDept(float budget);
    void addCitizen(Citizen* citizen);
    void addToEmployed(Citizen* citizen);
    void addToUnemployed(Citizen* citizen);
    void addToMinors(Citizen* citizen);
    ///send everyone to work
    ~SocialAffairsDept();

};

#endif 
