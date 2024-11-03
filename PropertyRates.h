/**
 * @file PropertyRates.h
 * @brief Header file for the PropertyRates class, implementing the TaxCalculator interface.
 * 
 * This class provides a concrete strategy for calculating property tax based on a fixed rate,
 * following the Strategy pattern. It also acts as a command for executing property tax calculations.
 * 
 * @author Driya Govender
 *

/*
    Pattern: Strategy
    Participant: ConcreteStrategy

    Pattern: Command
    Participant: ConcreteCommand
*/

#ifndef PROPERTYRATES_H
#define PROPERTYRATES_H

#include "TaxCalculator.h"

/**
 * @class PropertyRates
 * @brief A concrete implementation of the TaxCalculator for property tax calculations.
 * 
 * This class provides the algorithm to calculate property tax based on a fixed rate.
 */
class PropertyRates : public TaxCalculator
{
    public: 
        /**
         * @brief Retrieves the type of tax calculation strategy.
         * 
         * @return A string indicating the strategy is for Property Tax.
         */
        virtual string getTaxType()
        {
            return "Property Tax"; 
        }
        
        //strategy function (algorithm)
        /**
         * @brief Calculates the property tax based on the provided income.
         * 
         * This function computes the tax amount using a fixed tax rate and sends the calculated tax
         * to the CRS (Central Revenue Service).
         * 
         * @param income The income amount for which the property tax needs to be calculated.
         * @return The income amount after the property tax has been deducted.
         */
        virtual float calculateTax(float income)
        {
            float taxRate = 0.02; 
            //calculate tax amount
            float tax = income * taxRate; 
            //send tax amount to crs
            ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getCRS()->getTax(tax); 
            //return amount after tax
            return income - tax; 
        }
};

#endif