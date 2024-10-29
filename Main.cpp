#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Adult.h"
#include "Citizen.h"
#include "Department.h"
#include "Government.h"
#include "Population.h"
#include "AdultPop.h"
#include "MinorPop.h"
#include "SocialAffairsDept.h"

using namespace std;

int main(){

    cout << "====================================================================================================================================================================================================" << endl;

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
    Business* shop = new Business();
    Citizen* person1 =  ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->employ(shop);

    cout << endl;

    Citizen* person2 = personPrototype->clone();
    person2->react();

    cout << endl;

    ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->growPopulation(10);

    cout << "Currently the city consists of " << ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->getNumCitizens() << " citizens " << endl;  

    cout << endl;

    if(((Adult*) person1)->employmentStatus())
    {
        cout << "Person1 is employed " << endl;
    }

    if(((Adult*) person)->employmentStatus())
    {
        cout << "Person is employed " << endl;
    }

    delete person2;
    person2 = nullptr;
   
    delete shop;
    shop = nullptr;

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

    return 0;
}