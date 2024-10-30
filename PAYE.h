/*
    Pattern: Strategy
    Participant: ConcreteStrategy

    Pattern: Command
    Participant: ConcreteCommand
*/

#ifndef PAYE_H
#define PAYE_H

#include "TaxCalculator.h"

class PAYE : public TaxCalculator
{
    public: 
        virtual string getTaxType()
        {
            return "PAYE"; 
        }

        //strategy function (algorithm)
        virtual float calculateTax(float income)
        {
            float taxRate = 0; 
            if (income >= 237101 && income <= 370500) 
                taxRate = 0.18; // 18%
            else if (income > 370500 && income <= 512800) 
                taxRate = 0.26; // 26%
            else if (income > 512800 && income <= 673000) 
                taxRate = 0.31; // 31%
            else if (income > 673000 && income <= 857900) 
                taxRate = 0.36; // 36%
            else if (income > 857900 && income <= 1817000) 
                taxRate = 0.39; // 39%
            else if (income > 1817000) 
                taxRate = 0.45; // 45% 

            //calculate tax amount
            float tax = income * taxRate; 
            //send tax amount to crs
            CRS::getTax(tax); 
            //return amount after tax
            return income - tax; 
        }
};

#endif