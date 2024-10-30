#ifndef ADULT_H
#define ADULT_H

#include "Citizen.h"
#include "CitizenObserver.h"
#include <string>

class Adult: public Citizen{

    private:
    std::string name; //CitizenObserver

    protected:
        float balance;
        float netWorth;
        Business* job;
    
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
        // CitizenObserver
        Adult(const std::string& name);
        void update(const std::string& message);

};

#endif