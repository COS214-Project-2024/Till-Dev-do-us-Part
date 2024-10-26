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