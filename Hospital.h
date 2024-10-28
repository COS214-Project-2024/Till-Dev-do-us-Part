#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Public.h"
// #include "Citizens.h"
class Citizen;

class Hospital :public Public
{
    private:
        vector<Citizen*> patients;
        
    public:
        Hospital();
        ~Hospital();
        virtual bool addOccupant(Citizen *c) = 0;
        virtual void demolish() = 0;
        virtual bool clean() = 0;
        void heal(); //dk what to do with this but must be used to remove patients from the hospital
};
#endif