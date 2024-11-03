/*
    Pattern: Strategy
    Participant: ConcreteStrategy

    Pattern: Command
    Participant: ConcreteCommand
*/

#ifndef VAT_H
#define VAT_H

#include "TaxCalculator.h"

class VAT : public TaxCalculator
{
    public:
        virtual string getTaxType()
        {
            return "VAT"; 
        } 
        
        //strategy function (algorithm)
        virtual float calculateTax(float income)
        {
            //subtract VAT
            float taxRate = 0.15; 
            //calculate tax amount
            float tax1 = income * taxRate; 
            //remove tax from income
            income -= tax1; 

            //subtract income tax
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
            float tax2 = income * taxRate; 
            //combine tax
            float tax = tax1 + tax2; 
            //send tax amount to crs
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getCRS()->getTax(tax); 
            //return amount after tax
            return income - tax2; 
        }
};

#endif