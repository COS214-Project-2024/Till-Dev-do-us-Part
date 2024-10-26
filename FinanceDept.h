#ifndef FINANCEDEPT_H
#define FINANCEDEPT_H

#include <vector>
#include <algorithm>
using namespace std; 

class Business;

class FinanceDept
{
    private:
        static vector<Business*> businesses;  
    
    public: 
        static void newBusiness(Business* business);
        static void removeBusiness(Business* business);
        static vector<Business*> getBusinesses(); 
        
};

#endif