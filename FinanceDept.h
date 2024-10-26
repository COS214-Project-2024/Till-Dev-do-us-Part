#ifndef FINANCEDEPT_H
#define FINANCEDEPT_H

#include <vector>
#include <algorithm>
using namespace std; 

#include "Department.h"
class Business;

class FinanceDept : public Department
{
    private:
        vector<Business*> businesses;  
    
    public: 
        void newBusiness(Business* business);
        void removeBusiness(Business* business);
        vector<Business*> getBusinesses(); 
        
};

#endif