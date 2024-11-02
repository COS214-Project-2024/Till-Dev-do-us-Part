#ifndef LANDMARK_H
#define LANDMARK_H
#include "Building.h"

class Landmark:public Building
{
    protected: 
        vector<Citizen*> occupants;

    public:
        Landmark(string type);
        virtual bool addOccupant(Citizen *c) = 0;
        virtual void demolish() = 0;
        virtual bool clean() = 0;
        virtual bool removeOccupant(Citizen *c) = 0;
        virtual Building *clone() = 0;
        virtual bool isOccupied();
};
#endif