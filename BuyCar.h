#ifndef BUYCAR_H
#define BUYCAR_H

#include "AcquireAsset.h"
#include "Transport.h"

//Need to update class names on UML and classes present
class BuyCar : public AcquireAsset{

    private:
        Citizen* person;
        Transport* car;

    public:
        BuyCar(Citizen* adult){
            person =  adult;
        }

        void buyCar(Transport* car){
            this->car = car;
        }

        void increaseNW(float value){
            Adult::netWorth += value;
            //Not sure if this is the correct way to do it
        }

        virtual Citizen* clone(){}

};

#endif