/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef WELLNESS_H
#define WELLNESS_H

#include "Business.h"

// Wellness = Gyms, Spas, Wellness Tourism

class Wellness : public Business
{
    public:
        Wellness()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 8; 
            initialIncome = 700000; 
            income = 700000;
            name = "Some Wellness Shop";
            //owner =  

            //add to dept vector of businesses
            // FinanceDept::newBusiness(this);
        }

        Wellness(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*700000/8;
            income = maxEmployess*700000/8;
            name = shopName;  
            //owner =

            //add to dept vector of businesses
            // FinanceDept::newBusiness(this);
        }

        virtual string getBusinessType()
        {
            return "Wellness"; 
        }
}; 

#endif