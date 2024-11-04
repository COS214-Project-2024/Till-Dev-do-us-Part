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
    (Government::getInstance()->getDepartment("Resources"))->receiveTax(taxFund*0.15); 

    //TRANSPORT = 10%
    // (Government::getInstance()->getDepartment("Transport"))->receiveTax(taxFund*0.1); 

    //DEVELOPMENT = 30%
    (Government::getInstance()->getDepartment("Development"))->receiveTax(taxFund*0.3); 

    //SOCIAL AFFAIRS = 20%
    (Government::getInstance()->getDepartment("SocialAffairs"))->receiveTax(taxFund*0.2); 
    
    //HEALTH = 10%
    (Government::getInstance()->getDepartment("Health"))->receiveTax(taxFund*0.1); 

    taxFund -= taxFund*0.15;
    // taxFund -= taxFund*0.1;
    taxFund -= taxFund*0.3;
    taxFund -= taxFund*0.2; 
    taxFund -= taxFund*0.1;

    //FINANCE 
    (Government::getInstance()->getDepartment("Finance"))->receiveTax(taxFund);
}