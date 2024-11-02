#ifndef ADULT_H
#define ADULT_H

#include "Building.h"
#include "Citizen.h"

class Adult: public Citizen{

    protected:
        float balance;
        float netWorth;
        Business* job;
        Building* house;
    
    public:
        Adult();
        virtual Citizen* clone();
        virtual void react();
        virtual void goToWork();
        virtual bool employmentStatus();
        virtual bool hasChild();
        virtual void salary(float);
        virtual void setJob(Business*);
        virtual ~Adult(){};

};

#endif