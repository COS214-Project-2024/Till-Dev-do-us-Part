#ifndef OFFICE_H
#define OFFICE_H
#include "Commercial.h"

class Office : public Commercial
{
    private:
        Citizen * occupant;
    public:
        Office();
        ~Office();
        virtual void demolish();
        virtual bool clean();
        virtual bool addOccupant(Citizen *c);
        virtual bool removeOccupant(Citizen *c);
        virtual Building* clone();
        virtual bool isOccupied();
};
#endif