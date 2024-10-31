#ifndef CULTURALCENTER_H
#define CULTURALCENTER_H
#include "Landmark.h"

class CulturalCenter : public Landmark
{
    
    public:
        CulturalCenter();
        ~CulturalCenter();
        virtual bool addOccupant(Citizen *c);
        virtual void demolish();
        virtual bool clean();
        virtual bool removeOccupant(Citizen *c);
        virtual Building *clone();
};
#endif
