#ifndef CRS_H
#define CRS_H

#include "Business.h"

class CRS
{
    private: 
        float taxFund;          //equals budget

    public:
        CRS(float); 
        void settleTax();       //collects tax money from all businesses
        void getTax(float);     //adds tax money to taxFund 
        void distributeTax();   //sends tax money to finance dept
        
};

#endif