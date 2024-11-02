#ifndef MINORPOP_H
#define MINORPOP_H

#include "Population.h"
#include "Minor.h"


class MinorPop : public Population{

    public:
        virtual Citizen* createPerson(){
            return  (Citizen*) new Minor();
        }
};

#endif 

