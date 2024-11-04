/**
 * @file FinanceDept.h
 * @brief Implementation of the Finance Department class.
 * 
 * The Finance Department manages business registrations and oversees
 * the City Revenue Service (CRS) for tax collection and distribution.
 * 
 * @author Driya Govender
 */

#ifndef FINANCEDEPT_H
#define FINANCEDEPT_H

#include <vector>
#include <algorithm>
using namespace std; 

#include "Department.h"
#include "CRS.h"

class Business;
class CRS;

/**
 * @class FinanceDept
 * @brief Represents the Finance Department in the system.
 */
class FinanceDept : public Department
{
    private:
        vector<Business*> businesses;  
        CRS* crs = nullptr; 

    public: 
        FinanceDept(float); 
        void newBusiness(Business* business);
        void removeBusiness(Business* business);
        vector<Business*> getBusinesses(); 
        CRS* getCRS(); 
        ~FinanceDept(); 
        
};

#endif