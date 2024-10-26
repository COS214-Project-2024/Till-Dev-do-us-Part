#include "Business.h"
    #include "Entertainment.h"
    #include "Food.h"
    #include "Retail.h"
    #include "Wellness.h"
#include "TaxCalculator.h"
    #include "CorporateTax.h"
    #include "Customs.h"
    #include "IncomeTax.h"
    #include "PAYE.h"
    #include "PropertyRates.h"
    #include "VAT.h"
#include "WiseBucks.h"

#include <iostream>
using namespace std; 

int main()
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
    
    //testing businesses
    Business* foodShop1 = new Food(); 
    Business* kfc = new Food("KFC", 12); 
    cout << foodShop1->getBusinessDetails() << endl; 
    cout << kfc->getBusinessDetails() << endl; 

    //testing observer
    foodShop1->linkWiseBucks(apps[2]);
    cout << foodShop1->getBusinessDetails() << endl; 
    foodShop1->linkWiseBucks(apps[3]);
    foodShop1->handleAccounts();
    cout << "After handling accounts: " << endl; 
    cout << foodShop1->getBusinessDetails() << endl; 

    kfc->unlinkWiseBucks(); 
    cout << endl; 

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

    return 0; 
}