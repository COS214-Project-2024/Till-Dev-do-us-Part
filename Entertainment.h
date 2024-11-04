/**
 * @file Entertainment.h
 * @brief Defines the Entertainment class, representing entertainment-related businesses such as theaters, clubs, and theme parks.
 * 
 * @details The Entertainment class is a concrete implementation of the Business class, specializing in entertainment-related businesses and providing default values for attributes such as employee count and income.
 * 
 * @note This class is part of the Observer design pattern as a ConcreteSubject.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H

#include "Business.h"

// Entertainment = Movies, Theatres, Clubs, Theme Parks, Stadiums, Galleries, Casinos  

/**
 * @class Entertainment
 * @brief Represents an entertainment business, such as a movie theater, club, or theme park.
 * 
 * @details The Entertainment class sets specific attributes for entertainment businesses, including default maximum employees, initial income, and the option to link a WiseBucks app.
 * Each instance of this business type is registered with the Finance department upon creation.
 */
class Entertainment : public Business
{
    public:
        /**
         * @brief Default constructor for Entertainment, initializing default attributes for an entertainment business.
         * 
         * @details Sets wiseBucksApp to null, assigns a default employee limit, sets initial income, and provides a placeholder name.
         * Registers the new business instance within the Finance department.
         */
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

        /**
         * @brief Parameterized constructor for Entertainment, allowing customization of shop name and maximum employees.
         * 
         * @param shopName The name of the entertainment business.
         * @param maxEmployees The maximum number of employees allowed for this business.
         * 
         * @details Initializes wiseBucksApp to null, sets employee counts, calculates income based on maxEmployees, and assigns the provided name.
         * Registers the new business instance within the Finance department.
         */
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

        /**
         * @brief Retrieves the type of business, which is "Entertainment" for this class.
         * 
         * @return A string indicating the type of business, specifically "Entertainment".
         */
        virtual string getBusinessType()
        {
            return "Entertainment"; 
        }
}; 

#endif