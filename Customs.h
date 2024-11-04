/**
 * @file Customs.h
 * @brief Header file for the Customs class, implementing the TaxCalculator interface.
 * 
 * This class represents a concrete strategy for calculating customs taxes, following the Strategy pattern.
 * It also acts as a command for executing tax calculations specific to customs duties.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Strategy
    Participant: ConcreteStrategy

    Pattern: Command
    Participant: ConcreteCommand
*/

#ifndef CUSTOMS_H
#define CUSTOMS_H

#include "TaxCalculator.h"

/**
 * @class Customs
 * @brief A concrete implementation of the TaxCalculator for customs tax calculations.
 * 
 * This class provides the algorithm to calculate customs tax based on income.
 */
class Customs : public TaxCalculator
{
    public: 
         /**
         * @brief Retrieves the type of tax calculation strategy.
         * 
         * @return A string indicating the strategy is for customs tax.
         */
        virtual string getTaxType()
        {
            return "Customs"; 
        }

        //strategy function (algorithm)
        /**
         * @brief Calculates the customs tax based on the provided income.
         * 
         * This function computes the tax amount using a fixed tax rate and
         * sends the calculated tax to the CRS (Central Revenue Service).
         * 
         * @param income The income amount for which the customs tax needs to be calculated.
         * @return The income amount after the customs tax has been deducted.
         */
        virtual float calculateTax(float income)
        {
            float taxRate = 0.2; 
            //calculate tax amount
            float tax = income * taxRate; 
            //send tax amount to crs
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getCRS()->getTax(tax); 
            //return amount after tax
            return income - tax; 
        }
};

#endif