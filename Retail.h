/**
 * @file Retail.h
 * @brief Defines the Retail class, representing retail-related businesses such as clothing and grocery stores.
 * 
 * @details The Retail class is a concrete implementation of the Business class, specializing in retail-related businesses and providing default values for attributes such as employee count and income.
 * 
 * @note This class is part of the Observer design pattern as a ConcreteSubject.
 * 
 * @author Driya Govender
 */
/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef RETAIL_H
#define RETAIL_H

#include "Business.h"

// Retail = Clothing, Groceries, etc. 

/**
 * @class Retail
 * @brief Represents a retail business, such as a clothing store or grocery shop.
 * 
 * @details The Retail class sets specific attributes for retail businesses, including default maximum employees, initial income, and the option to link a WiseBucks app.
 * Each instance of this business type is registered with the Finance department upon creation.
 */
class Retail : public Business
{
    public:
        /**
         * @brief Default constructor for Retail, initializing default attributes for a retail business.
         * 
         * @details Sets wiseBucksApp to null, assigns a default employee limit, sets initial income, and provides a placeholder name.
         * Registers the new business instance within the Finance department.
         */
        Retail()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 12; 
            initialIncome = 600000; 
            income = 600000;
            name = "Some Retail Shop";  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        /**
         * @brief Parameterized constructor for Retail, allowing customization of shop name and maximum employees.
         * 
         * @param shopName The name of the retail business.
         * @param maxEmployees The maximum number of employees allowed for this business.
         * 
         * @details Initializes wiseBucksApp to null, sets employee counts, calculates income based on maxEmployees, and assigns the provided name.
         * Registers the new business instance within the Finance department.
         */
        Retail(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*600000/12;
            income = maxEmployess*600000/12;
            name = shopName;  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        /**
         * @brief Retrieves the type of business, which is "Retail" for this class.
         * 
         * @return A string indicating the type of business, specifically "Retail".
         */
        virtual string getBusinessType()
        {
            return "Retail"; 
        }
}; 

#endif