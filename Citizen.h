#ifndef CITIZEN_H
#define CITIZEN_H

#include <iostream>
#include <string>
#include "Feeling.h"
#include "Business.h"
#include "TransportStrategy.h"

class Citizen{

    protected:
        Feeling* mood;
        int health;

    public:
        virtual Citizen* clone() = 0;
        virtual void react() = 0;
        virtual int getHealth();
        virtual void setHealth(int);
        // virtual void setJob(Business*);
        virtual ~Citizen();

};

#endif