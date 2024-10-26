/*
    Pattern: Strategy
    Participant: Strategy
*/

#ifndef TAXCALCULATOR
#define TAXCALCULATOR

#include <string>
using namespace std; 

class TaxCalculator
{
    public: 
        virtual string getTaxType() = 0; 
        //strategy function (algorithm)
        virtual float calculateTax(float income) = 0; 
};

#endif 