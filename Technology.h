/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H

#include "Business.h"

// Technology = Software, Security, Technical, Cloud Services, ISP

class Technology : public Business
{
    public:
        Technology()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 5; 
            initialIncome = 350000; 
            income = initialIncome;
            name = "Some Technology Shop";
            //owner =  

            //add to dept vector of businesses
            // FinanceDept::newBusiness(this);
        }

        Technology(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*350000/5;
            income = maxEmployess*350000/5;
            name = shopName;  
            //owner =

            //add to dept vector of businesses
            // FinanceDept::newBusiness(this);
        }

        virtual string getBusinessType()
        {
            return "Technology"; 
        }
}; 

#endif