/**
 * @file Food.h
 * @brief Defines the Food class, representing food-related businesses such as restaurants, coffee shops, and bakeries.
 * 
 * @details The Food class is a concrete implementation of the Business class, specializing in food-related businesses and providing default values for attributes such as employee count and income.
 * 
 * @note This class is part of the Observer design pattern as a ConcreteSubject.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef FOOD_H
#define FOOD_H

#include "Business.h"

// Food = Restaurants, Coffee Shops, Fast Food Chains, Bakeries

/**
 * @class Food
 * @brief Represents a food business, such as a restaurant, coffee shop, or bakery.
 * 
 * @details The Food class sets specific attributes for food businesses, including default maximum employees, initial income, and the option to link a WiseBucks app.
 * Each instance of this business type is registered with the Finance department upon creation.
 */
class Food : public Business
{
    public:
        /**
         * @brief Default constructor for Food, initializing default attributes for a food business.
         * 
         * @details Sets wiseBucksApp to null, assigns a default employee limit, sets initial income, and provides a placeholder name.
         * Registers the new business instance within the Finance department.
         */
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

        /**
         * @brief Parameterized constructor for Food, allowing customization of shop name and maximum employees.
         * 
         * @param shopName The name of the food business.
         * @param maxEmployees The maximum number of employees allowed for this business.
         * 
         * @details Initializes wiseBucksApp to null, sets employee counts, calculates income based on maxEmployees, and assigns the provided name.
         * Registers the new business instance within the Finance department.
         */
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

        /**
         * @brief Retrieves the type of business, which is "Food" for this class.
         * 
         * @return A string indicating the type of business, specifically "Food".
         */
        virtual string getBusinessType()
        {
            return "Food"; 
        }
}; 

#endif