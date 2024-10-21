#ifndef SOCIALAFFAIRS_H
#define SOCIALAFFAIRS_H

#include <queue>
#include <list>
#include "Department.h"
#include "Citizen.h"

using namespace std;

class SocialAffairsDept: public Department{

    private:

        //Use of citizens lsit??
        list<Citizen> citizens;
        queue<Citizen*> unemployed;

    public:
        SocialAffairsDept(float);
        Citizen* employ();
        int getNumCitizens();
        ~SocialAffairsDept();

};


#endif