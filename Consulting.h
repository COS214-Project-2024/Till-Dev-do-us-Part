/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef CONSULTING_H
#define CONSULTING_H

#include "Business.h"

// Consulting = Travel Agency, Accounting, Law, Medical, Insurance

class Consulting : public Business
{
    public:
        Consulting()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 5; 
            initialIncome = 300000; 
            income = initialIncome;
            name = "Some Consulting Shop";  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        Consulting(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*300000/5;
            income = maxEmployess*300000/5;
            name = shopName;  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        virtual string getBusinessType()
        {
            return "Consulting"; 
        }
}; 

#endif