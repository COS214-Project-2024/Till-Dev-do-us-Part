/**
 * @file Technology.h
 * @brief Defines the Technology class, representing technology-related businesses such as software and cloud services.
 * 
 * @details The Technology class is a concrete implementation of the Business class, specializing in technology-related businesses and providing default values for attributes such as employee count and income.
 * 
 * @note This class is part of the Observer design pattern as a ConcreteSubject.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Observer
    Participant: ConcreteSubject
*/

#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H

#include "Business.h"

// Technology = Software, Security, Technical, Cloud Services, ISP

/**
 * @class Technology
 * @brief Represents a technology business, such as a software company or cloud service provider.
 * 
 * @details The Technology class sets specific attributes for technology businesses, including default maximum employees, initial income, and the option to link a WiseBucks app.
 * Each instance of this business type is registered with the Finance department upon creation.
 */
class Technology : public Business
{
    public:
        /**
         * @brief Default constructor for Technology, initializing default attributes for a technology business.
         * 
         * @details Sets wiseBucksApp to null, assigns a default employee limit, sets initial income, and provides a placeholder name.
         * Registers the new business instance within the Finance department.
         */
        Technology()
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = 5; 
            initialIncome = 350000; 
            income = initialIncome;
            name = "Some Technology Shop";

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        /**
         * @brief Parameterized constructor for Technology, allowing customization of shop name and maximum employees.
         * 
         * @param shopName The name of the technology business.
         * @param maxEmployees The maximum number of employees allowed for this business.
         * 
         * @details Initializes wiseBucksApp to null, sets employee counts, calculates income based on maxEmployees, and assigns the provided name.
         * Registers the new business instance within the Finance department.
         */
        Technology(string shopName, int maxEmployess)
        {
            wiseBucksApp = nullptr; 
            numEmployees[0] = 0; 
            numEmployees[1] = maxEmployess; 
            initialIncome = maxEmployess*350000/5;
            income = maxEmployess*350000/5;
            name = shopName;  

            //add to dept vector of businesses
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->newBusiness(this); 
        }

        /**
         * @brief Retrieves the type of business, which is "Technology" for this class.
         * 
         * @return A string indicating the type of business, specifically "Technology".
         */
        virtual string getBusinessType()
        {
            return "Technology"; 
        }
}; 

#endif