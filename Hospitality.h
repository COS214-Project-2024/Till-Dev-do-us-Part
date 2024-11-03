/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef HOSPITALITY_H
#define HOSPITALITY_H

#include "Business.h"

// Hospitality = Hotels, Resorts, B&B, Guesthouses, Conference Centres, Camping

class Hospitality : public Business
{
    public:
        Hospitality()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 5; 
            initialIncome = 250000; 
            income = initialIncome;
            name = "Some Hospitality Shop";  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        Hospitality(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*250000/5;
            income = maxEmployess*250000/5;
            name = shopName;  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        virtual string getBusinessType()
        {
            return "Hospitality"; 
        }
}; 

#endif