#include <string>
#include "Clinic.h"
#include <iostream>
#include <random>


Clinic::Clinic() 
{
    successor=nullptr;
}

void Clinic::admitPatient(Citizen* c) {///take in citizen
    if(c->getHealth()<=0)
    {
        delete c;///dead!!
    }
    if (c->getHealth()<50 && c->getHealth()>=30) {
        std::cout << "Patient admitted\n";
        treatPatient(c);
    } else {
        if(successor!=nullptr)
        {
            successor->admitPatient(c);
        }

    }
}

// void Clinic::treatPatient(Citizen* c)
// {
//     int outcome=generateRandomValue();
//     if(outcome==1 || outcome==2)
//     {
//         dischargePatient(c);
//     }
//     else
//     {
        
//     }
    
// }




