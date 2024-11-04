#include "Business.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std; 

/*
    Building* property; 
    Citizen* owner
    float income; 
    int numEmployees [2]; 
    string name; 
    vector<Citizen*> employees; 
    WiseBucks* wiseBucksApp; 
*/

/**
 * @brief Purchases a property of a specified type for the business.
 * @param propertyType The type of property to purchase.
 */
void Business::buyProperty(string propertyType)
{
    property = ((DevelopmentDept*)(Government::getInstance()->getDepartment("Development")))->build(propertyType);
    // if (property != nullptr)
    //     cout << "Bought property: " << propertyType << endl;  
    // else cout << "Property is null" << endl; 
}

/**
 * @brief Sells the current property owned by the business, if any.
 */
void Business::sellProperty()
{
    delete property;
    property = nullptr;
}

/**
 * @brief Hires an employee for the business.
 * If there is no owner, it assigns one. Otherwise, it hires additional employees up to a maximum limit.
 */
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

/**
 * @brief Fires a random employee from the business.
 */
void Business::fireEmployee()
{
    if (!employees.empty())
    {
        //remove employee from vector and add to list of unemployed citizens
        int randomIndex = 0 + rand() % ((numEmployees[0]-1) - 0 + 1);
        Citizen* fired = employees[randomIndex]; 
        employees.erase(employees.begin() + randomIndex);        
        ((SocialAffairsDept*)(Government::getInstance()->getDepartment("SocialAffairs")))->addToUnemployed(fired); 
        numEmployees[0]--; 
    }
    else cout << this->getBusinessName() << " has no employees to fire" << endl; 
}

/**
 * @brief Retrenches half of the business's employees if there are 20 or more.
 */
void Business::retrench()
{
    if (numEmployees[0] >= 20)
    {
        int half = numEmployees[0]/2; 
        for (int i=0; i<half; i++)
        {
            fireEmployee(); 
        }
        cout << "Retrenched " << half << " employees from " << name << endl; 
    }
    else 
    {
        cout << "Cannot retrench employees in a business with less than 20 employees. " << endl; 
    }
}

/**
 * @brief Calculates the number of employees actively working.
 * @return The number of employees currently working.
 */
int Business::activelyWorking()
{
    return (rand() % (numEmployees[0] + 1)); 
}

/**
 * @brief Retrieves the name of the business.
 * @return The name of the business.
 */
string Business::getBusinessName()
{
    return name; 
}

/**
 * @brief Retrieves details about the business, including income, employee count, and linked services.
 * @return A formatted string containing business details.
 */
string Business::getBusinessDetails()
{
    // convert float income to string
    ostringstream streamObj;
    streamObj << fixed << setprecision(2) << income;    // Format to 2 decimal places
    string formattedIncome = streamObj.str();           // Convert to string
    
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

/**
 * @brief Increases the business income by the specified amount.
 * @param money The amount to add to the business's income.
 */
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

/**
 * @brief Links a WiseBucks app to the business if not already linked.
 * @param app Pointer to the WiseBucks app to link.
 */
void Business::linkWiseBucks(WiseBucks* app)
{
    if (wiseBucksApp == nullptr)
    {
        wiseBucksApp = app; 
        // cout << "WiseBucks App linked for " << name << endl; 
    }
    else
    {
        cout << "WiseBucks App already linked for " << name << endl; 
    }
}

/**
 * @brief Unlinks the WiseBucks app from the business, if currently linked.
 */
void Business::unlinkWiseBucks()
{
    if (wiseBucksApp != nullptr)
    {
        wiseBucksApp = nullptr; 
    }
    else 
    {
        cout << "WiseBucks App has not been linked for " << name << endl; 
    }
}

/**
 * @brief Handles business accounts, including paying employees and owner after tax deductions.
 */
void Business::handleAccounts()
{
    if (wiseBucksApp != nullptr)
    {
        //cannot pay if there is no work being done - if (numEmployees[0] != 0 || property == nullptr)
        if (numEmployees[0] != 0)
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
        cout << "WiseBucks App has not been linked for " << name << endl; 
    }
}

/**
 * @brief Destructor for Business, cleans up any owned property.
 */
Business::~Business()
{
    if (property != nullptr)
        property = nullptr; 
    owner = nullptr; 
    while (!employees.empty())
    {
        fireEmployee(); 
    }
    wiseBucksApp = nullptr; 
    // FinanceDept::removeBusiness(this); 
} 
