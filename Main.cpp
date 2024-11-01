// #include <cstdlib>
// #include <ctime>
// #include <iostream>

// #include "Adult.h"
// #include "Citizen.h"
// #include "Department.h"
// #include "Government.h"
// #include "Population.h"
// #include "AdultPop.h"
// #include "MinorPop.h"
// #include "SocialAffairsDept.h"

// using namespace std;

// int main(){

//     cout << "====================================================================================================================================================================================================" << endl;

//     std::srand(std::time(0));

//     Government* Gov = Government::getInstance();
//     Department* SA = new SocialAffairsDept(50000);
//     Gov->addDepartment("SocialAffairs", SA);

//     Population* AdultFactory = new AdultPop();
//     Citizen* personPrototype = AdultFactory->getPerson();
//     Citizen* person = AdultFactory->getPerson();
//     cout << "Created a new adult " << endl;

//     Population* MinorFactory = new MinorPop();
//     Citizen* child = MinorFactory->getPerson();
//     cout << "Created a new child " << endl;

//     cout << endl;

//     person->react();
//     child->react();
//     person->react();

//     cout << endl;

//     ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addCitizen(person);
//     ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addChild(child);
//     ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(person);
//     Business* shop = new Business();
//     Citizen* person1 =  ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->employ(shop);

//     cout << endl;

//     Citizen* person2 = personPrototype->clone();
//     person2->react();

//     cout << endl;

//     ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->growPopulation(10);

//     cout << "Currently the city consists of " << ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->getNumCitizens() << " citizens " << endl;  

//     cout << endl;

//     if(((Adult*) person1)->employmentStatus())
//     {
//         cout << "Person1 is employed " << endl;
//     }

//     if(((Adult*) person)->employmentStatus())
//     {
//         cout << "Person is employed " << endl;
//     }

//     delete person2;
//     person2 = nullptr;
   
//     delete shop;
//     shop = nullptr;

//     delete MinorFactory;
//     MinorFactory = nullptr;

//     delete personPrototype;
//     personPrototype = nullptr;

//     delete AdultFactory;
//     AdultFactory = nullptr;

//     Gov->removeDepartment("SocialAffairs");

//     delete SA;
//     SA = nullptr;

//     delete Gov;
//     Gov = nullptr;

//     // Use getFeeling to rever to previous policy in government
//     //

//     cout << "====================================================================================================================================================================================================" << endl;

//     return 0;
// }


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
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
#include "Business.h"
#include "HaveChild.h"

using namespace std;


TEST_SUITE("CITIZEN TESTS") {

    Government* Gov;
    Department* SA;
    Population* adultFactory;
    Population* minorFactory;
    Citizen* adult;
    Citizen* child;

    TEST_CASE("Setup Government and Social Affairs Department") {

        std::srand(std::time(0));
        Gov = Government::getInstance();
        SA = new SocialAffairsDept(50000);
        Gov->addDepartment("SocialAffairs", SA);
        
        adultFactory = new AdultPop();
        adult = adultFactory->getPerson();
        minorFactory = new MinorPop();
        child = minorFactory->getPerson();

        CHECK(adult != nullptr);
        CHECK(child != nullptr);

        SUBCASE("Check adult and child reaction"){
            CHECK_NOTHROW(adult->react());
            CHECK_NOTHROW(child->react());
        }

        SUBCASE("CHECK ADULT AND CHILD ADDED TO SAD"){
            ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addCitizen(adult);
            ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addChild(child);
            CHECK(((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->getNumCitizens() == 2);
        }

        SUBCASE("CHECK THAT EMPLOYMENT WORKS"){

            ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(adult);
            Business* shop = new Business();
            Citizen* person1 = ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->employ(shop);

            CHECK(person1 != nullptr);
            CHECK(((Adult*) person1)->employmentStatus());
            CHECK(((Adult*) adult)->employmentStatus());

            delete shop;
        }

        SUBCASE("CHECK GROW POPULATION"){
            ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->growPopulation(10);
            CHECK(((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->getNumCitizens() == 14);
        }

        SUBCASE("CHECK THAT HAS CHILD WORKS"){
            CHECK(!(((HaveChild*) adult)->hasChild()));
        }

        SUBCASE("CHECK THAT HAVECHILD DECORATOR WORKS"){
            CHECK(!(((HaveChild*) adult)->hasChild()));
            HaveChild* parent = new HaveChild(adult);
            ((Minor*) child)->setParent((Adult*)adult);
            CHECK((((HaveChild*) parent)->hasChild()));
        }

    }


    TEST_CASE("Tear Down") {
        delete adultFactory;
        delete minorFactory;
        Gov->removeDepartment("SocialAffairs");
        delete SA;
    }

}
