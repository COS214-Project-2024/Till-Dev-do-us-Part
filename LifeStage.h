#ifndef LIFESTAGE_H
#define LIFESTAGE_H

#include "Adult.h"

class LifeStage: public Adult{

    private:
        Citizen* adult;

    public:
       virtual void increaseNW(float value){
            netWorth += value;
       };
       virtual bool hasChild(){
            return false;
       }
       virtual ~LifeStage(){}

};

#endif
