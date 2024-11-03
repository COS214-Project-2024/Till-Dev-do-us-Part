#include "Clinic.h"
#include <iostream>

/**
 * @brief Default constructor for Clinic, sets successor to nullptr and initializes death toll.
 */
Clinic::Clinic()
{
    successor = nullptr;
    deathtoll = 0;
}

/**
 * @brief Attempts to admit a patient to the clinic based on health status.
 * @param c Pointer to the Citizen being admitted.
 */
void Clinic::admitPatient(Citizen*& c)
{
    // if(c->getHealth() <= 0)
    // {
    //     c = nullptr; // Patient is dead
    //     return;
    // }
    if(c->getHealth()>=50)
    {
        return;
    }
    else if (c->getHealth() < 50 && c->getHealth() >= 30)
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
    }
}
