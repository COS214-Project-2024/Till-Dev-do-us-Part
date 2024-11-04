/**
 * @file CorporateTax.h
 * @brief Header file for the CorporateTax class, implementing the TaxCalculator interface.
 * 
 * This class represents a concrete strategy for calculating corporate taxes, following the Strategy pattern.
 * It also acts as a command for executing tax calculations specific to corporate income.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Strategy
    Participant: ConcreteStrategy

    Pattern: Command
    Participant: ConcreteCommand
*/

#ifndef CORPORATETAX_H
#define CORPORATETAX_H

#include "TaxCalculator.h"

/**
 * @class CorporateTax
 * @brief A concrete implementation of the TaxCalculator for corporate tax calculations.
 * 
 * This class provides the algorithm to calculate corporate tax based on income.
 */
class CorporateTax : public TaxCalculator
{
    public: 
        /**
         * @brief Retrieves the type of tax calculation strategy.
         * 
         * @return A string indicating the strategy is for corporate tax.
         */
        virtual string getTaxType()
        {
            return "Corporate Tax"; 
        }
        
        //strategy function (algorithm)
        /**
         * @brief Calculates the corporate tax based on the provided income.
         * 
         * This function computes the tax amount using a fixed tax rate and
         * sends the calculated tax to the CRS (Central Revenue Service).
         * 
         * @param income The income amount for which the corporate tax needs to be calculated.
         * @return The income amount after the corporate tax has been deducted.
         */
        virtual float calculateTax(float income)
        {
            float taxRate = 0.27; 
            //calculate tax amount
            float tax = income * taxRate; 
            //send tax amount to crs
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getCRS()->getTax(tax); 
            //return amount after tax
            return income - tax; 
        }
};

#endif