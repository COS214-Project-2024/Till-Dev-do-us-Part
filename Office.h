#ifndef OFFICE_H
#define OFFICE_H
#include "Commercial.h"

class Office : public Commercial
{
    private:
        vector<Citizen *> occupants;
        
    public:
        Office();
        ~Office();
        virtual void demolish();
        virtual bool clean();
        virtual bool addOccupant(Citizen *c);
        virtual Building* clone();
};
#endif

