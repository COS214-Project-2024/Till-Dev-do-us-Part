#ifndef ADULTPOP_H
#define ADULTPOP_H

#include "Population.h"
#include "Adult.h"

class AdultPop: public Population{

    public:
        virtual Citizen* createPerson(){
            return new Adult();
        }

};

#endif 

