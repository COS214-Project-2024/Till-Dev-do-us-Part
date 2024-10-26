#ifndef CRS_H
#define CRS_H

#include "Business.h"

class CRS
{
    private: 
        static float taxFund;          //equals budget

    public:
        static void settleTax();       //collects tax money from all businesses
        static void getTax(float);     //adds tax money to taxFund 
        static void distributeTax();   //sends tax money to finance dept
        
};

#endif