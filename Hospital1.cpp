#include <string>
#include "Hospital1.h"
#include <iostream>
#include <random>


Hospital1:: Hospital1() 
{
    successor=nullptr;
}

void Hospital1:: admitPatient(Citizen* c) {///take in citizen
    if (c.getHealth()<30 && c.getHealth()>=15) {
        std::cout << "Patient admitted\n";
        treatPatient(c);
    } else {
        if(successor!=nullptr)
        {
            successor->admitPatient(c);
        }

    }
}




