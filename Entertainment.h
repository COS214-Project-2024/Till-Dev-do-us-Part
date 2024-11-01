/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H

#include "Business.h"

// Entertainment = Movies, Theatres, Clubs, Theme Parks, Stadiums, Galleries, Casinos  

class Entertainment : public Business
{
    public:
        Entertainment()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 10; 
            initialIncome = 700000; 
            income = 700000;
            name = "Some Entertainment Shop";  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        Entertainment(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*700000/10;
            income = maxEmployess*700000/10;
            name = shopName;  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        virtual string getBusinessType()
        {
            return "Entertainment"; 
        }
}; 

#endif