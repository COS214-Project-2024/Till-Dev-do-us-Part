/**
 * @file Hospitality.h
 * @brief Defines the Hospitality class, representing hospitality-related businesses such as hotels and guesthouses.
 * 
 * @details The Hospitality class is a concrete implementation of the Business class, specializing in hospitality-related businesses and providing default values for attributes such as employee count and income.
 * 
 * @note This class is part of the Observer design pattern as a ConcreteSubject.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef HOSPITALITY_H
#define HOSPITALITY_H

#include "Business.h"

// Hospitality = Hotels, Resorts, B&B, Guesthouses, Conference Centres, Camping

/**
 * @class Hospitality
 * @brief Represents a hospitality business, such as a hotel, resort, or guesthouse.
 * 
 * @details The Hospitality class sets specific attributes for hospitality businesses, including default maximum employees, initial income, and the option to link a WiseBucks app.
 * Each instance of this business type is registered with the Finance department upon creation.
 */
class Hospitality : public Business
{
    public:
        /**
         * @brief Default constructor for Hospitality, initializing default attributes for a hospitality business.
         * 
         * @details Sets wiseBucksApp to null, assigns a default employee limit, sets initial income, and provides a placeholder name.
         * Registers the new business instance within the Finance department.
         */
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

        /**
         * @brief Parameterized constructor for Hospitality, allowing customization of shop name and maximum employees.
         * 
         * @param shopName The name of the hospitality business.
         * @param maxEmployees The maximum number of employees allowed for this business.
         * 
         * @details Initializes wiseBucksApp to null, sets employee counts, calculates income based on maxEmployees, and assigns the provided name.
         * Registers the new business instance within the Finance department.
         */
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

        /**
         * @brief Retrieves the type of business, which is "Hospitality" for this class.
         * 
         * @return A string indicating the type of business, specifically "Hospitality".
         */
        virtual string getBusinessType()
        {
            return "Hospitality"; 
        }
}; 

#endif