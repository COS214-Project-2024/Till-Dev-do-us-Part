#include "Business.h"
    #include "Automotive.h"
    #include "Consulting.h"
    #include "Entertainment.h"
    #include "Food.h"
    #include "Hospitality.h"
    #include "Retail.h"
    #include "Technology.h"
    #include "Wellness.h"
#include "CRS.h"
#include "Department.h"
    #include "DevelopmentDept.h"
    #include "FinanceDept.h"
    #include "SocialAffairsDept.h"
#include "Government.h"
#include "TaxCalculator.h"
    #include "CorporateTax.h"
    #include "Customs.h"
    #include "IncomeTax.h"
    #include "PAYE.h"
    #include "PropertyRates.h"
    #include "VAT.h"
#include "WiseBucks.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

void karabosTest()
{
    cout << "===================================================================================================================================================================================================================================================================================================================" << endl;

    std::srand(std::time(0));

    Government* Gov = Government::getInstance();
    Department* SA = new SocialAffairsDept(50000);
    Gov->addDepartment("SocialAffairs", SA);

    Population* AdultFactory = new AdultPop();
    Citizen* personPrototype = AdultFactory->getPerson();
    Citizen* person = AdultFactory->getPerson();
    cout << "Created a new adult " << endl;

    Population* MinorFactory = new MinorPop();
    Citizen* child = MinorFactory->getPerson();
    cout << "Created a new child " << endl;

    cout << endl;

    person->react();
    child->react();
    person->react();

    cout << endl;

    ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addCitizen(person);
    ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addChild(child);
    ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(person);
    // Business* shop = new Food();
    // Citizen* person1 =  ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->employ(shop);

    cout << endl;

    Citizen* person2 = personPrototype->clone();
    person2->react();

    cout << endl;

    ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->growPopulation(10);

    cout << "Currently the city consists of " << ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->getNumCitizens() << " citizens " << endl;  

    cout << endl;

    // if(((Adult*) person1)->employmentStatus())
    {
        cout << "Person1 is employed " << endl;
    }

    if(((Adult*) person)->employmentStatus())
    {
        cout << "Person is employed " << endl;
    }

    delete person2;
    person2 = nullptr;
   
    // delete shop;
    // shop = nullptr;

    delete MinorFactory;
    MinorFactory = nullptr;

    delete personPrototype;
    personPrototype = nullptr;

    delete AdultFactory;
    AdultFactory = nullptr;

    Gov->removeDepartment("SocialAffairs");

    delete SA;
    SA = nullptr;

    delete Gov;
    Gov = nullptr;

    cout << "====================================================================================================================================================================================================" << endl;

}

void driyasTest()
{
    TaxCalculator* taxes [6]; 
    taxes[0] = new CorporateTax(); 
    taxes[1] = new Customs(); 
    taxes[2] = new IncomeTax(); 
    taxes[3] = new PAYE(); 
    taxes[4] = new PropertyRates(); 
    taxes[5] = new VAT(); 

    cout << endl << "Available Tax Strategies: " << endl; 
    for (int i=0; i<6; i++)
        cout << i+1 <<". " << taxes[i]->getTaxType() << endl; 
    cout << endl; 

    WiseBucks* apps [6]; 
    apps[0] = new WiseBucks(taxes[0]); 
    apps[1] = new WiseBucks(taxes[1]);
    apps[2] = new WiseBucks(taxes[2]); 
    apps[3] = new WiseBucks(taxes[3]); 
    apps[4] = new WiseBucks(taxes[4]); 
    apps[5] = new WiseBucks(taxes[5]); 

    cout << "WiseBucks Apps Available: " << endl; 
    for (int i=0; i<6; i++)
        cout << i+1 <<". " << apps[i]->getTaxType() << endl; 
    cout << endl;

    //testing tax calculations 
    cout << "WiseBucks Apps Pay Tax Function : " << endl;
    cout << "(returns amount after tax has been paid on CB 100 income)" << endl;  
    for (int i=0; i<6; i++)
        cout << i+1 <<". CB " << apps[i]->payTax(100) << endl; 
    cout << endl;

    cout << "WiseBucks Apps Pay Tax Function : " << endl;
    cout << "(returns amount after tax has been paid on CB 1 000 000 income)" << endl;  
    for (int i=0; i<6; i++)
        cout << i+1 <<". CB " << apps[i]->payTax(1000000) << endl; 
    cout << endl;

//MAKING THE GOVERNMENT
    Government* Gov = Government::getInstance(); 
    Department* FinDept = new FinanceDept(100000); 
    Gov->addDepartment("Finance", FinDept); 
    Department* DevDept = new DevelopmentDept(100000); 
    Gov->addDepartment("Development", DevDept); 
    Department* SAD = new SocialAffairsDept(100000);
    Gov->addDepartment("SocialAffairs", SAD);  

/*    //testing businesses
    Business* foodShop1 = new Food(); 
    Business* kfc = new Food("KFC", 12); 
    cout << foodShop1->getBusinessDetails() << endl; 
    cout << kfc->getBusinessDetails() << endl; 

    //testing observer
    foodShop1->linkWiseBucks(apps[2]);
    cout << foodShop1->getBusinessDetails() << endl; 
    foodShop1->linkWiseBucks(apps[3]);
    // foodShop1->handleAccounts();
    // cout << "After handling accounts: " << endl; 
    // cout << foodShop1->getBusinessDetails() << endl; 

    kfc->unlinkWiseBucks(); 
    cout << "end" << endl; 

    for (Business* business : ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getBusinesses()) 
    {
        cout << business->getBusinessName() << endl; 
        business->buyProperty("Mall"); 
    }  

   //testing other businesses
    Business* retailShop1 = new Retail(); 
    cout << retailShop1->getBusinessDetails() << endl;  
    Business* woolworths = new Retail("Woolworths", 30);
    cout << woolworths->getBusinessDetails() << endl; 
    woolworths->linkWiseBucks(apps[5]); 
    woolworths->handleAccounts(); 
    cout << woolworths->getBusinessDetails() << endl; 

    Business* entertainment = new Entertainment(); 
    cout << entertainment->getBusinessDetails() << endl; 
    Business* numetro = new Entertainment("Nu Metro", 25); 
    numetro->linkWiseBucks(apps[0]); 
    cout << numetro->getBusinessDetails() << endl; 

    Business* wellness = new Wellness(); 
    cout << wellness->getBusinessDetails() << endl; 
    Business* virginActive = new Wellness("Virgin Active", 20);
    virginActive->linkWiseBucks(apps[3]); 
    cout << virginActive->getBusinessDetails() << endl;  

    //testing crs settle tax
    CRS::settleTax(); 

    //deletes 
    delete virginActive; 
    virginActive = nullptr; 
    
    delete wellness; 
    wellness = nullptr; 

    delete numetro; 
    numetro = nullptr; 

    delete entertainment; 
    entertainment = nullptr; 

    delete woolworths;
    woolworths = nullptr;

    delete retailShop1; 
    retailShop1 = nullptr; 

    delete kfc; 
    kfc = nullptr; 

    delete foodShop1; 
    foodShop1 = nullptr; 
*/
    Gov->removeDepartment("Finance");
    delete FinDept; 
    FinDept = nullptr; 

    delete DevDept;
    DevDept = nullptr;

    delete SAD;
    SAD = nullptr;

    delete Gov; 
    Gov = nullptr; 

    for (int i=0; i<6; i++)
    {
        delete apps[i];
        apps[i] = nullptr; 
    }

    for (int i=0; i<6; i++)
    {
        delete taxes[i];
        taxes[i] = nullptr; 
    }
}

void DemoMain(); 

int main()
{
    // cout << "===========================================================================================================================================================================" << endl;
    // cout << "Running Driya's test " << endl;
    // driyasTest();
    // cout << "===========================================================================================================================================================================" << endl;
    // cout << "Running Karabo's test " << endl;
    // karabosTest();
    // cout << "===========================================================================================================================================================================" << endl;
    
    DemoMain(); 
    return 0; 
}

void DemoMain()
{
    cout << "===========================================================================================================================================================================" << endl;
    
    cout << "  WELCOME TO THE GREATEST CITY IN 214" << endl; 
    cout << "~ created by TDP - Till Dev do us Part ~" << endl; 
    cout << "===========================================================================================================================================================================" << endl;

    cout << "Creating Goverment and its Departments:" << endl; 
    Government* Gov = Government::getInstance(); 
    Department* DevDept = new DevelopmentDept(100000); 
    Gov->addDepartment("Development", DevDept); 
    Department* FinDept = new FinanceDept(100000); 
    Gov->addDepartment("Finance", FinDept); 
    Department* SAD = new SocialAffairsDept(100000);
    Gov->addDepartment("SocialAffairs", SAD); 
    cout << "===========================================================================================================================================================================" << endl;

    //instantiate resources and utility objects

    //instantiate transport objects 

    //instantiate citizen objects 
    Population* AdultFactory = new AdultPop();
    Population* MinorFactory = new MinorPop();

    //instantiate finance objects 
    TaxCalculator* taxes [6]; 
    taxes[0] = new CorporateTax(); 
    taxes[1] = new Customs(); 
    taxes[2] = new IncomeTax(); 
    taxes[3] = new PAYE(); 
    taxes[4] = new PropertyRates(); 
    taxes[5] = new VAT(); 

    WiseBucks* apps [6]; 
    apps[0] = new WiseBucks(taxes[0]); 
    apps[1] = new WiseBucks(taxes[1]);
    apps[2] = new WiseBucks(taxes[2]); 
    apps[3] = new WiseBucks(taxes[3]); 
    apps[4] = new WiseBucks(taxes[4]); 
    apps[5] = new WiseBucks(taxes[5]); 

    //instantiate building objects 

//CREATING THE CITY 
    /*TO CREATE CITIZENS: use the functions growPopulation in SAD
      TO CREATE IMMIGRANTS: use the reproduce function in AdultPop/ MinorPop*/
    Citizen** first100 = AdultFactory->reproduce(100); 
    for (int i=0; i<100; i++)
    {
        ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addCitizen(first100[i]);
        ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(first100[i]);
    }

    Business* first8Businesses [8]; 
    first8Businesses[0] = new Automotive();
    first8Businesses[1] = new Consulting(); 
    first8Businesses[2] = new Entertainment();
    first8Businesses[3] = new Food(); 
    first8Businesses[4] = new Hospitality(); 
    first8Businesses[5] = new Retail(); 
    first8Businesses[6] = new Technology(); 
    first8Businesses[7] = new Wellness(); 

    first8Businesses[0]->linkWiseBucks(apps[3]);
    first8Businesses[1]->linkWiseBucks(apps[2]);
    first8Businesses[2]->linkWiseBucks(apps[2]);
    first8Businesses[3]->linkWiseBucks(apps[1]);
    first8Businesses[4]->linkWiseBucks(apps[1]);
    first8Businesses[5]->linkWiseBucks(apps[5]);
    first8Businesses[6]->linkWiseBucks(apps[1]);
    first8Businesses[7]->linkWiseBucks(apps[2]);

    for (Business* business : ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getBusinesses()) 
    {
        //NOT DESTRUCTED 
        business->buyProperty("Shop"); 
    }

    for (int i=0; i<8; i++)
    {
        for (int j=0; j<5; j++)
        {
            first8Businesses[i]->hireEmployee(); 
        }
    }

    ((FinanceDept*)(Government::getInstance()->getDepartment("Finance")))->getCRS()->settleTax(); 

//MAIN LOOP 

    //deletes
    for (int i=0; i<8; i++)
    {
        delete first8Businesses[i]; 
        first8Businesses[i] = nullptr; 
    }

    delete [] first100; 
    first100 = nullptr; 

    for (int i=0; i<6; i++)
    {
        delete apps[i];
        apps[i] = nullptr; 
    }

    for (int i=0; i<6; i++)
    {
        delete taxes[i];
        taxes[i] = nullptr; 
    }

    delete MinorFactory;
    MinorFactory = nullptr;

    delete AdultFactory; 
    AdultFactory = nullptr;

    Gov->removeDepartment("Development");
    delete DevDept;
    DevDept = nullptr;

    Gov->removeDepartment("Finance");
    delete FinDept; 
    FinDept = nullptr; 

    Gov->removeDepartment("SocialAffairs");
    delete SAD;
    SAD = nullptr;

    delete Gov; 
    Gov = nullptr;

}