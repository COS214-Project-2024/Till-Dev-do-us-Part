#ifndef SOCIALAFFAIRS_H
#define SOCIALAFFAIRS_H

#include <queue>
#include <list>
#include "Department.h"
#include "Citizen.h"
#include "Population.h"
#include "Business.h"

using namespace std;

class SocialAffairsDept: public Department{

    private:

        //What is the use of citizens list??
        list<Citizen*> citizens;
        queue<Citizen*> unemployed;
        Population* factory;

    public:
        SocialAffairsDept(float);
        Citizen* employ(Business*);
        void addCitizen(Citizen*);
        int getNumCitizens();
        void growPopulation();
        ~SocialAffairsDept();

};


#endif