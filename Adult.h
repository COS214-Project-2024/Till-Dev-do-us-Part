#ifndef ADULT_H
#define ADULT_H

#include "Citizen.h"

//Need to verify neccesity of salary function
class Adult: public Citizen{

    //Should be private if no longer parent of Acquire Asset
    protected:
        Business* employer; 
        float balance;
        float netWorth;
    
    public:
        Adult();
        void react();
        Citizen* clone();
        void goToWork();
        bool employmentStatus();
        void salary(float);
        void setEmployer(Business*);


        //will implement when combining and attributes added
        void observeTransport();
        void chooseMode(TransportStrategy*);
        void update();

        //Will update with Utilities
        void requestElectricity(int amount);

};

#endif