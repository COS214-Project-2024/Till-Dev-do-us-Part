/**
 * @file Automotive.h
 * @brief Defines the Automotive class, representing automotive-related businesses like petrol stations, car dealerships, and more.
 * 
 * @details The Automotive class is a concrete implementation of the Business class, providing initialization for automotive businesses and defining specific attributes such as maximum employees, initial income, and integration with WiseBucks.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef AUTOMOTIVE_H
#define AUTOMOTIVE_H

#include "Business.h"

// Automotive = Petrol Station, Car Dealership, Mechanic, Accessories, Car Rental, Car Wash

/**
 * @class Automotive
 * @brief Represents an automotive business, such as a petrol station, car dealership, mechanic, accessories shop, car rental, or car wash.
 * 
 * @details The Automotive class initializes the business with attributes like income, employee count, and a link to the WiseBucks app for financial handling. It also registers the business within the Finance department.
 * 
 * @note This class participates in the Observer design pattern as a ConcreteSubject.
 */
class Automotive : public Business
{
    public:
        /**
         * @brief Default constructor for Automotive, setting default attributes for the automotive business.
         * 
         * @details Initializes the wiseBucksApp to null, sets employee counts, and assigns initial income and a default name.
         * The new business is registered within the Finance department.
         */
        Automotive()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 6; 
            initialIncome = 450000; 
            income = initialIncome;
            name = "Some Automotive Shop";  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        /**
         * @brief Parameterized constructor for Automotive, allowing customization of shop name and maximum employees.
         * 
         * @param shopName The name of the automotive business.
         * @param maxEmployees The maximum number of employees allowed for this automotive business.
         * 
         * @details Initializes the wiseBucksApp to null, sets employee counts, calculates income based on maxEmployees, and assigns the provided name.
         * Registers the new business within the Finance department.
         */
        Automotive(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*450000/6;
            income = maxEmployess*450000/6;
            name = shopName;  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        /**
         * @brief Retrieves the type of business, which is "Automotive" for this class.
         * 
         * @return A string indicating the type of business, specifically "Automotive".
         */
        virtual string getBusinessType()
        {
            return "Automotive"; 
        }
}; 

#endif