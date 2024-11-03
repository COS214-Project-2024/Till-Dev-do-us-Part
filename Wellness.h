/**
 * @file Wellness.h
 * @brief Defines the Wellness class, representing wellness-related businesses such as gyms, spas, and wellness tourism centers.
 * 
 * @details The Wellness class is a specific implementation of the Business class, providing initialization for wellness businesses and setting attributes such as maximum employees, initial income, and integration with the WiseBucks app.
 * 
 * @note This class participates in the Observer design pattern as a ConcreteSubject.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef WELLNESS_H
#define WELLNESS_H

#include "Business.h"

// Wellness = Gyms, Spas, Wellness Tourism

/**
 * @class Wellness
 * @brief Represents a wellness business, such as a gym, spa, or wellness tourism center.
 * 
 * @details The Wellness class initializes the business with specific attributes, including income, employee count, and a potential WiseBucks app link for financial handling. The business is also registered within the Finance department.
 */
class Wellness : public Business
{
    public:
        /**
         * @brief Default constructor for Wellness, setting default attributes for the wellness business.
         * 
         * @details Initializes wiseBucksApp to null, sets employee counts, assigns initial income, and provides a default name.
         * Registers the new business within the Finance department.
         */
        Wellness()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 8; 
            initialIncome = 700000; 
            income = 700000;
            name = "Some Wellness Shop";

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        /**
         * @brief Parameterized constructor for Wellness, allowing customization of shop name and maximum employees.
         * 
         * @param shopName The name of the wellness business.
         * @param maxEmployees The maximum number of employees allowed for this wellness business.
         * 
         * @details Initializes wiseBucksApp to null, sets employee counts, calculates income based on maxEmployees, and assigns the provided name.
         * Registers the new business within the Finance department.
         */
        Wellness(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*700000/8;
            income = maxEmployess*700000/8;
            name = shopName;  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        /**
         * @brief Retrieves the type of business, which is "Wellness" for this class.
         * 
         * @return A string indicating the type of business, specifically "Wellness".
         */
        virtual string getBusinessType()
        {
            return "Wellness"; 
        }
}; 

#endif