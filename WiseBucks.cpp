#include "WiseBucks.h"

#include <iostream>
using namespace std; 

/*
    TaxCalculator* strategy;
*/

/**
 * @brief Constructor for the WiseBucks class.
 * 
 * @param type A pointer to a TaxCalculator strategy that will be used for tax calculations.
 * 
 * @details Initializes the WiseBucks app with the specified tax calculation strategy.
 */
WiseBucks::WiseBucks(TaxCalculator* type)
{
    strategy = type; 
}

/**
 * @brief Retrieves the type of tax calculation strategy being used.
 * 
 * @return A string indicating the type of tax strategy that the WiseBucks app is currently enabled with.
 */
string WiseBucks::getTaxType()
{
    string output = "WiseBucks App enabled with " + strategy->getTaxType(); 
    return output; 
}

/**
 * @brief Calculates the tax based on the provided income using the selected strategy.
 * 
 * @param income The income amount for which the tax needs to be calculated.
 * @return The calculated tax based on the income and the current tax strategy.
 */
float WiseBucks::payTax(float income)
{
    return strategy->calculateTax(income); 
}

/**
 * @brief Destructor for the WiseBucks class.
 * 
 * @details Cleans up the resources by setting the strategy pointer to null.
 */
WiseBucks::~WiseBucks()
{
    strategy = nullptr; 
}