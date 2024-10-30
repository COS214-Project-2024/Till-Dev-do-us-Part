/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef AUTOMOTIVE_H
#define AUTOMOTIVE_H

#include "Business.h"

// Automotive = Petrol Station, Car Dealership, Mechanic, Accessories, Car Rental, Car Wash

class Automotive : public Business
{
    public:
        //need to add Citizen*
        Automotive()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 6; 
            initialIncome = 450000; 
            income = initialIncome;
            name = "Some Automotive Shop";  
            //owner =

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        Automotive(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*450000/6;
            income = maxEmployess*450000/6;
            name = shopName;  
            //owner =

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        virtual string getBusinessType()
        {
            return "Automotive"; 
        }
}; 

#endif