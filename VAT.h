/**
 * @file VAT.h
 * @brief Defines the VAT class, which calculates tax based on VAT and income tax rates.
 * 
 * This class represents a concrete implementation of the TaxCalculator strategy, 
 * applying both VAT and income tax calculations to a given income.
 * 
 */

/*
    Pattern: Strategy
    Participant: ConcreteStrategy

    Pattern: Command
    Participant: ConcreteCommand
*/

#ifndef VAT_H
#define VAT_H

#include "TaxCalculator.h"

/**
 * @class VAT
 * @brief Implements VAT and income tax calculations.
 * 
 * The VAT class provides a concrete implementation of the TaxCalculator strategy 
 * for calculating tax. It first applies VAT, then applies an income-based tax rate 
 * to calculate the total tax amount.
 */
class VAT : public TaxCalculator
{
    public:
        /**
         * @brief Returns the tax type as a string.
         * 
         * @return A string representing the type of tax, in this case "VAT".
         */
        virtual string getTaxType()
        {
            return "VAT"; 
        } 
        
        /**
         * @brief Calculates the total tax by applying VAT and income tax rates.
         * 
         * This method first applies a 15% VAT to the income, then adjusts the 
         * income by further applying income tax based on specified income ranges. 
         * The total tax is then sent to the CRS (Central Revenue Service).
         * 
         * @param income The income on which tax is calculated.
         * @return The income after both VAT and income tax are subtracted.
         */
        //strategy function (algorithm)
        virtual float calculateTax(float income)
        {
            //subtract VAT
            float taxRate = 0.15; 
            //calculate tax amount
            float tax1 = income * taxRate; 
            //remove tax from income
            income -= tax1; 

            //subtract income tax based on income brackets
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
            //send total tax amount to CRS
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getCRS()->getTax(tax); 
            //return income after tax
            return income - tax2; 
        }
};

#endif
