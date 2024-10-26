/*
    Pattern: Strategy
    Participant: Strategy

    Pattern: Command
    Participant: Command
*/

#ifndef TAXCALCULATOR
#define TAXCALCULATOR

#include <string>
using namespace std; 

class TaxCalculator
{
    public: 
        virtual string getTaxType() = 0; 
        //strategy function (algorithm) and command function (execute)
        virtual float calculateTax(float income) = 0; 
};

#endif 