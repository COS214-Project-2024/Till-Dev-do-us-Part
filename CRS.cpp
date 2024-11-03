#include "CRS.h"
#include "Government.h"

#include <iomanip>
#include <iostream>

/**
 * @brief Constructs a CRS instance with a specified budget.
 * 
 * @param budget Initial budget allocated for the CRS.
 */
CRS::CRS(float budget)
{
    taxFund = budget; 
}

/**
 * @brief Settles taxes by collecting tax money from all businesses.
 * 
 * This function iterates through all businesses in the Finance Department and calls
 * the handleAccounts method to process tax collection.
 */
void CRS::settleTax()        //collects tax money from all businesses
{
    // cout << fixed << setprecision(2) << taxFund << endl; 
    for (Business* business : ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getBusinesses()) 
    {
        business->handleAccounts(); 
    }
}

/**
 * @brief Adds collected tax to the tax fund.
 * 
 * @param tax The amount of tax to be added to the tax fund.
 */
void CRS::getTax(float tax)  //adds tax money to taxFund 
{
    // cout << fixed << setprecision(2) << taxFund << endl << tax << endl; 
    taxFund += tax; 
    // cout << taxFund << endl; 
} 

/**
 * @brief Distributes the collected tax fund to various departments.
 * 
 * This function will implement the logic for distributing the tax fund to different
 * departments based on predefined percentages.
 */
void CRS::distributeTax()
{
    //RESOURCES = 15%
    //TRANSPORT = 20%
    //DEVELOPMENT = 20%
    //SOCIAL AFFAIRS = 30%
    //HEALTH = 10%
    //FINANCE = 5%
}