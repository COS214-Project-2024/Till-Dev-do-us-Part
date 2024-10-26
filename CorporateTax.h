/*
    Pattern: Strategy
    Participant: ConcreteStrategy
*/

#ifndef CORPORATETAX_H
#define CORPORATETAX_H

#include "TaxCalculator.h"

class CorporateTax : public TaxCalculator
{
    public: 
        virtual string getTaxType()
        {
            return "Corporate Tax"; 
        }
        
        //strategy function (algorithm)
        virtual float calculateTax(float income)
        {
            float taxRate = 0.27; 
            //calculate tax amount
            float tax = income * taxRate; 
            //return amount after tax
            return income - tax; 
        }
};

#endif