/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef RETAIL_H
#define RETAIL_H

#include "Business.h"

// Retail = Clothing, Groceries, etc. 

class Retail : public Business
{
    public:
        Retail()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 12; 
            initialIncome = 600000; 
            income = 600000;
            name = "Some Retail Shop";  
            //owner =

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        Retail(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*600000/12;
            income = maxEmployess*600000/12;
            name = shopName;  
            //owner =

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        virtual string getBusinessType()
        {
            return "Retail"; 
        }
}; 

#endif