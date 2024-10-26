/*
    Pattern: Strategy
    Participant: ConcreteStrategy

    Pattern: Command
    Participant: ConcreteCommand
*/

#ifndef CUSTOMS_H
#define CUSTOMS_H

#include "TaxCalculator.h"

class Customs : public TaxCalculator
{
    public: 
        virtual string getTaxType()
        {
            return "Customs"; 
        }

        //strategy function (algorithm)
        virtual float calculateTax(float income)
        {
            float taxRate = 0.2; 
            //calculate tax amount
            float tax = income * taxRate; 
            //return amount after tax
            return income - tax; 
        }
};

#endif