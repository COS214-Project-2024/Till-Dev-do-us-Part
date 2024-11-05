#include <string>
#include "Hospital2.h"
#include <iostream>
#include <random>

Hospital2::Hospital2()
{
    successor = nullptr;
    deathtoll = 0;
}

void Hospital2::admitPatient(Citizen*& c)
{ /// take in citizen
    if (c->getHealth() >= 15)
    {
        return;
    }

    if (c->getHealth() < 15 && c->getHealth() > 0)
    {
        std::cout << "Patient admitted\n";
        treatPatient(c);
    }
    else
    {

        if (successor != nullptr)
        {
            successor->admitPatient(c);
        }
        else
        {
            c = nullptr; /// die again?shame
        }
    }
}
