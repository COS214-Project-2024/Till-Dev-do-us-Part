#ifndef CITIZEN_H
#define CITIZEN_H

#include "Feeling.h"

class Citizen{

    protected:
        Feeling* mood;

    public:
        virtual Citizen* clone() = 0;

};

#endif