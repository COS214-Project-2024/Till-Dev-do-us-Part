#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Public.h"
#include "Clinic.h"
// #include "Citizens.h"
class Citizen;

class Hospital :public Public
{
    private:
        vector<Citizen*> patients;
        
    public:
        Hospital();
        ~Hospital();
        //Karabo removed purity. What inherits from hospital?
        virtual bool addOccupant(Citizen *c) ;
        virtual void demolish();
        virtual bool clean();
        virtual Building* clone();
        // void heal(); //dk what to do with this but must be used to remove patients from the hospital
};
#endif