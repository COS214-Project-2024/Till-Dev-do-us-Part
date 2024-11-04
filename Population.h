#ifndef POPULATION_H
#define POPULATION_H

#include "Citizen.h"

class Population {

    private:
        Citizen* citizen;

    public:
        virtual Citizen* getPerson();
        virtual Citizen* createPerson() = 0;
        virtual Citizen** reproduce(int);
        virtual ~Population(){}

};

#endif