/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef FOOD_H
#define FOOD_H

#include "Business.h"

// Food = Restaurants, Coffee Shops, Fast Food Chains, Bakeries

class Food : public Business
{
    public:
        Food()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 10; 
            initialIncome = 500000; 
            income = 500000;
            name = "Some Food Shop"; 

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        Food(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*500000/10;
            income = maxEmployess*500000/10;
            name = shopName;  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        virtual string getBusinessType()
        {
            return "Food"; 
        }
}; 

#endif