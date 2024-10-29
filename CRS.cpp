#include "CRS.h"
#include "Government.h"

#include <iomanip>
#include <iostream>

float CRS::taxFund = 100000; //equals budget

void CRS::settleTax()        //collects tax money from all businesses
{
    // cout << fixed << setprecision(2) << taxFund << endl; 
    for (Business* business : ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getBusinesses()) 
    {
        business->handleAccounts(); 
    }
}

void CRS::getTax(float tax)  //adds tax money to taxFund 
{
    // cout << fixed << setprecision(2) << taxFund << endl << tax << endl; 
    taxFund += tax; 
    // cout << taxFund << endl; 
} 

void CRS::distributeTax()
{
    //RESOURCES = 15%
    //TRANSPORT = 20%
    //DEVELOPMENT = 25%
    //SOCIAL AFFAIRS = 30%
    //HEALTH = 10%
    //FINANCE = 
}