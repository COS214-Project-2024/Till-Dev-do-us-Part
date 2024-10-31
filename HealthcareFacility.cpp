#include <string>
#include "HealthcareFacility.h"
#include <iostream>
#include <random>


HealthcareFacility:: HealthcareFacility() 
{
   
    successor=nullptr;
}

void HealthcareFacility:: addSuccessor(HealthcareFacility* s)
{
    if(s!=this)
    {
        successor=s;
    }
}
void HealthcareFacility::treatPatient(Citizen* c)
{
    int outcome=generateRandomValue();
    if(outcome==1 || outcome==2)
    {
        dischargePatient(c);
    }
    else
    {
        delete c;/// o sure?????????
        deathtoll++;

    }
    
}

void HealthcareFacility:: dischargePatient(Citizen* c) {

    c->setHealth(100);
}

int HealthcareFacility:: generateRandomValue() {
    static std::random_device rd; 
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(1, 3);

    return dist(gen); 
}

int HealthcareFacility:: getDeathToll()
{
    return deathtoll;
}
// HealthcareFacility:: ~HealthcareFacility()
// {
//     // if(successor!=nullptr)
//     // {
//     //     delete successor;
//     //     successor=nullptr;
//     // }
// }
