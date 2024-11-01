#ifndef ADULTPOP_H
#define ADULTPOP_H

#include "Population.h"
#include "Adult.h"

class Adult;

class AdultPop: public Population{

    public:
        virtual Citizen* createPerson(){
            return (Citizen*) new Adult();
        }

};

#endif 

