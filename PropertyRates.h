/*
    Pattern: Strategy
    Participant: ConcreteStrategy

    Pattern: Command
    Participant: ConcreteCommand
*/

#ifndef PROPERTYRATES_H
#define PROPERTYRATES_H

#include "TaxCalculator.h"

class PropertyRates : public TaxCalculator
{
    public: 
        virtual string getTaxType()
        {
            return "Property Tax"; 
        }
        
        //strategy function (algorithm)
        virtual float calculateTax(float income)
        {
            float taxRate = 0.02; 
            //calculate tax amount
            float tax = income * taxRate; 
            //send tax amount to crs
            CRS::getTax(tax); 
            //return amount after tax
            return income - tax; 
        }
};

#endif