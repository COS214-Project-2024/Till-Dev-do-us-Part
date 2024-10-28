#ifndef MINOR_H
#define MINOR_H

#include "Citizen.h"
#include "School.h"

class Minor: public Citizen{

    private:
        School* school;

    public:
        Minor();
        virtual Citizen* clone();
        void goToSchool();
        bool employmentStatus();

        // void observeTransport();
        // void chooseMode(TransportStrategy*);
        // void update();

};

#endif