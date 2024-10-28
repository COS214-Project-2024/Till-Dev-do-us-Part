#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include "Feeling.h"
#include "Business.h"
// #include "Health.h"
#include "TransportStrategy.h"

class Citizen{

    protected:
        Feeling* mood;
        // Health* health;
        //To keep or not to keep
        std::string name;
        Business* employer;

    public:
        virtual Citizen* clone() = 0;
        virtual void react(){
            delete mood;
            mood = mood->reaction();
        }
        virtual void observeTransport() = 0;
        virtual void chooseMode(TransportStrategy*) = 0;
        virtual void update() = 0;
        virtual bool employmentStatus() = 0;
        virtual void setEmployer(Business*){
            employer = 0;
        }
    
        //Transport attribute not added, not sure of new changes

};

#endif