#ifndef SOCIALAFFAIRS_H
#define SOCIALAFFAIRS_H

#include <queue>
#include <list>
#include "Department.h"
#include "Citizen.h"
#include "AdultPop.h"
#include "MinorPop.h"
#include "Population.h"
#include "Business.h"

using namespace std;
class Citizen;

class SocialAffairsDept: public Department{

    private:
        list<Citizen*> adults;
        list<Citizen*> children;
        queue<Citizen*> unemployed;
        Population* factory;

    public:
        SocialAffairsDept(float);
        Citizen* employ(Business*);
        void addCitizen(Citizen*);
        void addChild(Citizen*);
        void addToUnemployed(Citizen*);
        int getNumCitizens();
        void growPopulation(int);
        virtual ~SocialAffairsDept();

};


#endif