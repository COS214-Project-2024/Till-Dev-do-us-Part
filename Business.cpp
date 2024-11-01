#include "Business.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std; 

//SEE LINES 88+   ??? who added this comment

/*
    Building* property; 
    Citizen* owner
    float income; 
    int numEmployees [2]; 
    string name; 
    vector<Citizen*> employees; 
    WiseBucks* wiseBucksApp; 
*/

void Business::buyProperty(string propertyType)
{
    property = ((DevelopmentDept*)(Government::getInstance()->getDepartment("Development")))->build(propertyType);
    // if (property != nullptr)
    //     cout << "Bought property: " << propertyType << endl;  
    // else cout << "Property is null" << endl; 
}

void Business::sellProperty()
{
    property = nullptr; 
}

void Business::hireEmployee()
{
    if (owner == nullptr)
    {
        owner = ((SocialAffairsDept*)(Government::getInstance()->getDepartment("SocialAffairs")))->employ(this);
    }
    else if (numEmployees[0] != numEmployees[1])
    {
        //hire employee by adding to vector (NOT FINALISED)
        Citizen* newEmployee = ((SocialAffairsDept*)(Government::getInstance()->getDepartment("SocialAffairs")))->employ(this); 
        if (newEmployee != nullptr)
        {
            employees.push_back(newEmployee);
            numEmployees[0]++; 
        }
    }
    else cout << "Maximum employess reached for " << this->getBusinessName() << endl; 
}

void Business::fireEmployee()
{
    if (employees[0] != 0)
    {
        //remove employee from vector and add to list of unemployed citizens
        // ((SocialAffairsDept*)(Government::getInstance()->getDepartment("SocialAffairs")))->addToUnemployed()
        numEmployees[0]--; 
    }
    else cout << this->getBusinessName() << " has no employees" << endl; 
}

string Business::getBusinessName()
{
    return name; 
}

string Business::getBusinessDetails()
{
    // convert float income to string
    ostringstream streamObj;
    streamObj << fixed << setprecision(2) << income;    // Format to 2 decimal places
    string formattedIncome = streamObj.str();      // Convert to string
    
    string output = "Business Details for "; 
    output += name + "\n";
    output += "Type of Business: " + this->getBusinessType() + "\n";  
    output += "Current Number of Employees: " + to_string(numEmployees[0]) + "\n"; 
    output += "Maximum Number of Employees: " + to_string(numEmployees[1]) + "\n"; 
    output += "Income: CB " + formattedIncome + "\n"; 
    if (wiseBucksApp != nullptr) 
        output += "WiseBucks Service: " + wiseBucksApp->getTaxType() + "\n"; 
    else output += "WiseBucks Service: WiseBucks has not been linked \n"; 
    output += "Property Type: \n"; 
    return output;
}

void Business::earnMoney(float money)
{
    if (money > 0)
    {
        income += money; 
    }
    else 
    {
        cout << "Cannot pay a negative amount" << endl; 
    }
}

void Business::linkWiseBucks(WiseBucks* app)
{
    if (wiseBucksApp == nullptr)
    {
        wiseBucksApp = app; 
    }
    else
    {
        cout << "WiseBucks App already linked" << endl; 
    }
}

void Business::unlinkWiseBucks()
{
    if (wiseBucksApp != nullptr)
    {
        wiseBucksApp = nullptr; 
    }
    else 
    {
        cout << "WiseBucks App has not been linked" << endl; 
    }
}

void Business::handleAccounts()
{
    if (wiseBucksApp != nullptr)
    {
        //cannot pay if there is no work being done
        if (numEmployees[0] != 0 || property == nullptr)
        {
            //get income after tax paid
            income = wiseBucksApp->payTax(income);

            //plus 2 accounts for double pay for owner
            int pay = income / (numEmployees[0] + 2); 
            // pay owner
            ((Adult*) owner)->salary(pay+pay); 
            income -= (pay + pay); 

            //pay employees
            for (int i=0; i<employees.size(); i++)
            {
                ((Adult*) employees[i])->salary(pay);
                income -= pay; 
            }

            //reset income amount 
            income += initialIncome; 
        }
        else 
        {
            cout << "Cannot earn an income without hiring employees to work" << endl;
        }
    } 
    else 
    {
        cout << "WiseBucks App has not been linked" << endl; 
    }
}

Business::~Business()
{
    if (property != nullptr)
        property = nullptr; 
    // FinanceDept::removeBusiness(this); 
} 