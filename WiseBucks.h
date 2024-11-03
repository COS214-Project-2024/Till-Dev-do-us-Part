/**
 * @file WiseBucks.h
 * @brief Header file for the WiseBucks class, which manages tax calculations using the Strategy pattern.
 * 
 * This class serves as a context in the Strategy pattern and acts as an observer in the Observer pattern.
 * It utilizes a TaxCalculator strategy to perform tax calculations based on different algorithms.
 * 
 * @author Driya Govender
 */

/*
    Pattern: Observer
    Participant: Observer

    Pattern: Strategy
    Participant: Context

    Pattern: Command
    Participant: Invoker
*/

#ifndef WISEBUCKS_H
#define WISEBUCKS_H

#include "TaxCalculator.h"

/**
 * @class WiseBucks
 * @brief Represents a tax calculation application that uses a strategy for different tax calculation algorithms.
 * 
 * This class can be linked with an observer to notify when tax-related events occur.
 */
class WiseBucks
{
    private: 
        TaxCalculator* strategy; 

    public: 
        WiseBucks(TaxCalculator* type); 
        string getTaxType(); 
        // observer (update) and strategy (algorithm) functions 
        float payTax(float income); 
        //destructor
        ~WiseBucks(); 
}; 

#endif 