/**
 * @file PAYE.h
 * @brief Header file for the PAYE class, implementing the TaxCalculator interface.
 * 
 * This class provides a concrete strategy for calculating PAYE (Pay As You Earn) tax based on different income brackets,
 * following the Strategy pattern. It also acts as a command for executing tax calculations specific to PAYE tax.
 * 
 * @author Driya
 */

/*
    Pattern: Strategy
    Participant: ConcreteStrategy

    Pattern: Command
    Participant: ConcreteCommand
*/

#ifndef PAYE_H
#define PAYE_H

#include "TaxCalculator.h"

/**
 * @class PAYE
 * @brief A concrete implementation of the TaxCalculator for PAYE tax calculations.
 * 
 * This class provides the algorithm to calculate PAYE tax based on varying tax rates for different income levels.
 */
class PAYE : public TaxCalculator
{
    public: 
        /**
         * @brief Retrieves the type of tax calculation strategy.
         * 
         * @return A string indicating the strategy is for PAYE tax.
         */
        virtual string getTaxType()
        {
            return "PAYE"; 
        }

        //strategy function (algorithm)
        /**
         * @brief Calculates the PAYE tax based on the provided income.
         * 
         * This function computes the tax amount using progressive tax rates for different income levels
         * and sends the calculated tax to the CRS (Central Revenue Service).
         * 
         * @param income The income amount for which the PAYE tax needs to be calculated.
         * @return The income amount after the PAYE tax has been deducted.
         */
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
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getCRS()->getTax(tax); 
            //return amount after tax
            return income - tax; 
        }
};

#endif