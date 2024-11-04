#ifndef LANDMARK_H
#define LANDMARK_H
#include "Building.h"

class Landmark:public Building
{
    protected: 
        vector<Citizen*> occupants;

    public:
        Landmark(string type);
        virtual void demolish();
        virtual bool clean() = 0;
        virtual bool addOccupant(Citizen *c);
        
};
#endif

