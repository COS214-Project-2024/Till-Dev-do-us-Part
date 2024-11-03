#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Public.h"
#include "Citizen.h"
// class Citizen;

class Hospital :public Public
{
    private:
        vector<Citizen*> patients;
        
    public:
        Hospital();
        ~Hospital();
        virtual bool addOccupant(Citizen *c);
        virtual void demolish();
        virtual bool clean();
        virtual bool removeOccupant(Citizen *c);
        virtual Building *clone();
        virtual bool isOccupied();
};
#endif