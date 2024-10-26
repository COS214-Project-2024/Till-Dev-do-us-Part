#include "CRS.h"

float CRS::taxFund = 100000; //equals budget

void CRS::settleTax()        //collects tax money from all businesses
{
    for (Business* business : FinanceDept::getBusinesses())
    {
        business->handleAccounts(); 
    }
}

void CRS::getTax(float tax)  //adds tax money to taxFund 
{
    taxFund += tax; 
    std::cout << taxFund << std::endl; 
} 

void CRS::distributeTax()
{
    
}