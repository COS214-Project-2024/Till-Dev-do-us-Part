#ifndef CULTURALCENTER_H
#define CULTURALCENTER_H
#include "Landmark.h"

class CulturalCenter : public Landmark
{
    
    public:
        CulturalCenter();
        // virtual void demolish();
        virtual bool clean();
        // virtual bool addOccupant(Citizen *c);
};
#endif
