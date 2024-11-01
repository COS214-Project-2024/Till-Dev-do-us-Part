#ifndef BUYCAR_H
#define BUYCAR_H

#include "LifeStage.h"
#include "Transport.h"

//Need to update class names on UML and classes present
class BuyCar : public LifeStage{

    private:
        Transport* car;

    public:
        BuyCar(Citizen*);
        void buyCar(Transport*);
        virtual ~BuyCar();
};

#endif