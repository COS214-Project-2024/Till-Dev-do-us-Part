/**
 * @file Consulting.h
 * @brief Defines the Consulting class, representing consulting-related businesses such as travel agencies, accounting firms, and medical services.
 * 
 * @details The Consulting class is a concrete implementation of the Business class, specializing in consulting-related businesses and providing default values for attributes such as employee count and income.
 * 
 * @note This class is part of the Observer design pattern as a ConcreteSubject.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef CONSULTING_H
#define CONSULTING_H

#include "Business.h"

// Consulting = Travel Agency, Accounting, Law, Medical, Insurance

/**
 * @class Consulting
 * @brief Represents a consulting business, such as a travel agency or accounting firm.
 * 
 * @details The Consulting class sets specific attributes for consulting businesses, including default maximum employees, initial income, and the option to link a WiseBucks app.
 * Each instance of this business type is registered with the Finance department upon creation.
 */
class Consulting : public Business
{
    public:
        /**
         * @brief Default constructor for Consulting, initializing default attributes for a consulting business.
         * 
         * @details Sets wiseBucksApp to null, assigns a default employee limit, sets initial income, and provides a placeholder name.
         * Registers the new business instance within the Finance department.
         */
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

        /**
         * @brief Parameterized constructor for Consulting, allowing customization of shop name and maximum employees.
         * 
         * @param shopName The name of the consulting business.
         * @param maxEmployees The maximum number of employees allowed for this business.
         * 
         * @details Initializes wiseBucksApp to null, sets employee counts, calculates income based on maxEmployees, and assigns the provided name.
         * Registers the new business instance within the Finance department.
         */
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

        /**
         * @brief Retrieves the type of business, which is "Consulting" for this class.
         * 
         * @return A string indicating the type of business, specifically "Consulting".
         */
        virtual string getBusinessType()
        {
            return "Consulting"; 
        }
}; 

#endif