#include "WiseBucks.h"

#include <iostream>
using namespace std; 

/*
    TaxCalculator* strategy;
*/

WiseBucks::WiseBucks(TaxCalculator* type)
{
    strategy = type; 
}

string WiseBucks::getTaxType()
{
    string output = "WiseBucks App enabled with " + strategy->getTaxType(); 
    return output; 
}

float WiseBucks::payTax(float income)
{
    return strategy->calculateTax(income); 
}

WiseBucks::~WiseBucks()
{
    strategy = nullptr; 
}