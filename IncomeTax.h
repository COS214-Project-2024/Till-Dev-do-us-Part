/**
 * @file IncomeTax.h
 * @brief Header file for the IncomeTax class, implementing the TaxCalculator interface.
 * 
 * This class provides a concrete strategy for calculating income tax based on different income brackets, following the Strategy pattern.
 * It also acts as a command for executing tax calculations specific to income tax.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Strategy
    Participant: ConcreteStrategy

    Pattern: Command
    Participant: ConcreteCommand
*/

#ifndef INCOMETAX_H
#define INCOMETAX_H

#include "TaxCalculator.h"

/**
 * @class IncomeTax
 * @brief A concrete implementation of the TaxCalculator for income tax calculations.
 * 
 * This class provides the algorithm to calculate income tax based on varying tax rates for different income brackets.
 */
class IncomeTax : public TaxCalculator
{
    public: 
        /**
         * @brief Retrieves the type of tax calculation strategy.
         * 
         * @return A string indicating the strategy is for income tax.
         */
        virtual string getTaxType()
        {
            return "Income Tax"; 
        }
        
        //strategy function (algorithm)
        /**
         * @brief Calculates the income tax based on the provided income.
         * 
         * This function computes the tax amount using progressive tax rates for different income levels
         * and sends the calculated tax to the CRS (Central Revenue Service).
         * 
         * @param income The income amount for which the income tax needs to be calculated.
         * @return The income amount after the income tax has been deducted.
         */
        virtual float calculateTax(float income)
        {
            //determine taxRate
            float taxRate = 0.0; 
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
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getCRS()->getTax(tax); 
            //return amount after tax
            return income - tax; 
        }
};

#endif 