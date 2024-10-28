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
#include "WiseBucks.h"

#include <string>
#include <vector>
using namespace std; 

class Business
{
    protected: 
        Building* property = nullptr; 
        Citizen* owner = nullptr; 
        float initialIncome; 
        float income; 
        int numEmployees [2]; 
        string name; 
        vector<Citizen*> employees; 
        WiseBucks* wiseBucksApp = nullptr; 

    public: 
        virtual string getBusinessType() = 0; 

        void buyProperty(string propertyType); 
        void sellProperty(); 
        void hireEmployee(); 
        void fireEmployee(); 
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
