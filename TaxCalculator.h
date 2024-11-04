/**
 * @file TaxCalculator.h
 * @brief Header file for the TaxCalculator interface, defining the structure for tax calculation strategies.
 * 
 * This interface allows for the implementation of different tax calculation algorithms, following the Strategy pattern.
 * It also serves as a command for executing tax calculations.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Strategy
    Participant: Strategy

    Pattern: Command
    Participant: Command
*/

#ifndef TAXCALCULATOR
#define TAXCALCULATOR

#include <string>
using namespace std; 

/**
 * @class TaxCalculator
 * @brief An interface for tax calculation strategies.
 * 
 * This class defines the necessary methods for any tax calculation strategy.
 * Implementations of this interface should provide specific algorithms for tax calculations.
 */
class TaxCalculator
{
    public: 
        /**
         * @brief Retrieves the type of tax calculation strategy.
         * 
         * @return A string representing the type of tax strategy.
         */
        virtual string getTaxType() = 0; 
        
        //strategy function (algorithm) and command function (execute)
        /**
         * @brief Calculates the tax based on the provided income.
         * 
         * This function serves as both a strategy function for tax calculation 
         * and a command function to execute the calculation.
         * 
         * @param income The income amount for which the tax needs to be calculated.
         * @return The calculated tax based on the income.
         */
        virtual float calculateTax(float income) = 0; 


        /**
         * @brief Virtual destructor for the TaxCalculator interface.
         * 
         * Ensures proper cleanup of derived class objects through a pointer 
         * to the base class.
         */
        virtual ~TaxCalculator() {}
};

#endif 