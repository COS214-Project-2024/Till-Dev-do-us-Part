#ifndef POPULATION_H
#define POPULATION_H

#include "Citizen.h"

//Not sure about implementation of Population factory, will consult group - Add Minor pop
class Population{

    private:
        Citizen** citizens;

    protected:
        virtual Citizen* createPerson() = 0;
        virtual Citizen reproduce() = 0;

};

#endif