// #ifndef BUSINESS_H
// #define BUSINESS_H

// class Business{

// };

// #endif

/**
 * @file Business.h
 * @brief Defines the Business class, representing a business entity that manages employees, income, property, and integrates with WiseBucks for tax handling.
 * @author Driya Govender
 */

/*
    Pattern: Observer
    Participant: Subject
*/

#ifndef BUSINESS_H
#define BUSINESS_H

#include "Building.h"
#include "Citizen.h"
#include "Department.h"
#include "FinanceDept.h"
#include "DevelopmentDept.h"
#include "Government.h"
#include "SocialAffairsDept.h"
#include "WiseBucks.h"

#include <string>
#include <vector>
using namespace std; 

/**
 * @class Business
 * @brief Represents an abstract business entity that can own property, hire/fire employees, and interact with the WiseBucks app.
 */
class Business
{
    protected: 
        /**
         * @var property
         * @brief Pointer to the Building object owned by the business.
         */
        Building* property = nullptr; 

        /**
         * @var owner
         * @brief Pointer to the Citizen who owns the business.
         */
        Citizen* owner = nullptr; 

        /**
         * @var initialIncome
         * @brief Initial income value for the business.
         */
        float initialIncome;

        /**
         * @var income
         * @brief Current income of the business.
         */
        float income; 

        /**
         * @var numEmployees
         * @brief Array where [0] is the current number of employees, and [1] is the maximum number of employees allowed.
         */
        int numEmployees[2]; 

        /**
         * @var name
         * @brief Name of the business.
         */
        string name; 

        /**
         * @var employees
         * @brief Vector of pointers to Citizen objects representing employees of the business.
         */
        vector<Citizen*> employees; 

        /**
         * @var wiseBucksApp
         * @brief Pointer to the WiseBucks app used for tax management.
         */
        WiseBucks* wiseBucksApp = nullptr; 

        /**
         * @var strike
         * @brief Boolean indicating if the business is currently on strike.
         */
        bool strike = false; 

    public: 
        virtual string getBusinessType() = 0; 
        void buyProperty(string propertyType); 
        void sellProperty(); 
        void hireEmployee(); 
        void fireEmployee(); 
        void retrench(); 
        int activelyWorking(); 
        string getBusinessName(); 
        void earnMoney(float money); 
        string getBusinessDetails(); 
        //observer functions (attach, detach, notify)
        void linkWiseBucks(WiseBucks* app);
        void unlinkWiseBucks(); 
        void handleAccounts();  
        //destructor
        virtual ~Business(); 

}; 

#endif
