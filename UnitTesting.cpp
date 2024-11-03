//INCLUDES:
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest/doctest.h"
#include "Main.h"

//BOITUMELO MTSATSE


//DRIYA GOVENDER
TEST_SUITE("Economy Tests") 
{
    TEST_CASE("Testing Tax Calculators") 
    {
        Government* Gov = Government::getInstance(); 
        Department* FinDept = new FinanceDept(100000); 
        Gov->addDepartment("Finance", FinDept); 

        TaxCalculator* taxes[6];
        taxes[0] = new CorporateTax(); 
        taxes[1] = new Customs(); 
        taxes[2] = new IncomeTax(); 
        taxes[3] = new PAYE(); 
        taxes[4] = new PropertyRates(); 
        taxes[5] = new VAT(); 

        SUBCASE("Verify Available Tax Strategies") 
        {
            string expected[] = { "Corporate Tax", "Customs", "Income Tax", "PAYE", "Property Tax", "VAT"};
                
            for (int i = 0; i < 6; i++) 
            {
                CHECK(taxes[i]->getTaxType() == expected[i]);
            }
        }

        SUBCASE("Verify Tax Calculation In Each Strategy") 
        {
            float expected[] = {730000.00, 800000.00, 610000.00, 610000.00, 980000.00, 544000.00};
                
            for (int i = 0; i < 6; i++) 
            {
                CHECK(taxes[i]->calculateTax(1000000) == expected[i]);
            }
        }

    }

    TEST_CASE("Testing WiseBucks Apps") 
    {
        Government* Gov = Government::getInstance(); 
        Department* FinDept = new FinanceDept(100000); 
        Gov->addDepartment("Finance", FinDept); 

        TaxCalculator* taxes[6];
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

        SUBCASE("Verify Tax Types In WiseBucks Apps") 
        {
            string expected[] = { "WiseBucks App enabled with Corporate Tax", "WiseBucks App enabled with Customs", "WiseBucks App enabled with Income Tax", "WiseBucks App enabled with PAYE", "WiseBucks App enabled with Property Tax", "WiseBucks App enabled with VAT"};
                
            for (int i = 0; i < 6; i++) 
            {
                CHECK(apps[i]->getTaxType() == expected[i]);
            }
        }

        SUBCASE("Verify Tax Payment In WiseBucks Apps") 
        {
            float expected[] = {730000.00, 800000.00, 610000.00, 610000.00, 980000.00, 544000.00};
                
            for (int i = 0; i < 6; i++) 
            {
                CHECK(apps[i]->payTax(1000000) == expected[i]);
            }
        }

    }

    TEST_CASE("Testing Businesses")
    {
        Government* Gov = Government::getInstance(); 
        Department* FinDept = new FinanceDept(100000); 
        Gov->addDepartment("Finance", FinDept); 

        SUBCASE("Testing Businesses Using Constructor")
        {
            Business* businesses [8]; 
            businesses[0] = new Automotive();
            businesses[1] = new Consulting(); 
            businesses[2] = new Entertainment();
            businesses[3] = new Food(); 
            businesses[4] = new Hospitality(); 
            businesses[5] = new Retail(); 
            businesses[6] = new Technology(); 
            businesses[7] = new Wellness();

            SUBCASE("Verify Business Types")
            {
                string expected[] = {"Automotive", "Consulting", "Entertainment", "Food", "Hospitality", "Retail", "Technology", "Wellness"};
                
                for (int i = 0; i < 6; i++) 
                {
                    CHECK(businesses[i]->getBusinessType() == expected[i]);
                }
            }

            SUBCASE("Verify Business Names")
            {
                string expected[] = {"Some Automotive Shop", "Some Consulting Shop", "Some Entertainment Shop", "Some Food Shop", "Some Hospitality Shop", "Some Retail Shop", "Some Technology Shop", "Some Wellness Shop"};
                
                for (int i = 0; i < 6; i++) 
                {
                    CHECK(businesses[i]->getBusinessName() == expected[i]);
                }
            }
        }

        SUBCASE("Testing Businesses Using Parameterised Constructor")
        {
            Business* businesses [8]; 
            businesses[0] = new Automotive("Engen", 10);
            businesses[1] = new Consulting("Deloitte", 100); 
            businesses[2] = new Entertainment("Ster Kinekor", 20);
            businesses[3] = new Food("KFC", 25); 
            businesses[4] = new Hospitality("Protea Hotel", 80); 
            businesses[5] = new Retail("Woolworths", 50); 
            businesses[6] = new Technology("Microsoft", 200); 
            businesses[7] = new Wellness("Virgin Active", 40);

            SUBCASE("Verify Business Types")
            {
                string expected[] = {"Automotive", "Consulting", "Entertainment", "Food", "Hospitality", "Retail", "Technology", "Wellness"};
                
                for (int i = 0; i < 6; i++) 
                {
                    CHECK(businesses[i]->getBusinessType() == expected[i]);
                }
            }

            SUBCASE("Verify Business Names")
            {
                string expected[] = {"Engen", "Deloitte", "Ster Kinekor", "KFC", "Protea Hotel", "Woolworths", "Microsoft", "Virgin Active"};
                
                for (int i = 0; i < 6; i++) 
                {
                    CHECK(businesses[i]->getBusinessName() == expected[i]);
                }
            }
        }

        SUBCASE("Hiring and Firing Employees")
        {
            Department* SAD = new SocialAffairsDept(100000);
            Gov->addDepartment("SocialAffairs", SAD); 

            Population* AdultFactory = new AdultPop();
            Citizen** first100 = AdultFactory->reproduce(100); 
            for (int i=0; i<100; i++)
            {
                ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addCitizen(first100[i]);
                ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(first100[i]);
            }

            Business* businesses [8]; 
            businesses[0] = new Automotive();
            businesses[1] = new Consulting(); 
            businesses[2] = new Entertainment();
            businesses[3] = new Food(); 
            businesses[4] = new Hospitality(); 
            businesses[5] = new Retail(); 
            businesses[6] = new Technology(); 
            businesses[7] = new Wellness();

            for (int i=0; i<8; i++)
            {
                for (int j=0; j<5; j++)
                {
                    businesses[i]->hireEmployee(); 
                }
            }

            for (int i=0; i<8; i++)
            {
                for (int j=0; j<5; j++)
                {
                    businesses[i]->fireEmployee(); 
                }
            }

        }

        SUBCASE("Testing Retrenchment")
        {
            Department* SAD = new SocialAffairsDept(100000);
            Gov->addDepartment("SocialAffairs", SAD); 

            Population* AdultFactory = new AdultPop();
            Citizen** first1000 = AdultFactory->reproduce(1000); 
            for (int i=0; i<1000; i++)
            {
                ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addCitizen(first1000[i]);
                ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(first1000[i]);
            }

            Business* businesses [8]; 
            businesses[0] = new Automotive("Engen", 10);
            businesses[1] = new Consulting("Deloitte", 100); 
            businesses[2] = new Entertainment("Ster Kinekor", 20);
            businesses[3] = new Food("KFC", 25); 
            businesses[4] = new Hospitality("Protea Hotel", 80); 
            businesses[5] = new Retail("Woolworths", 50); 
            businesses[6] = new Technology("Microsoft", 200); 
            businesses[7] = new Wellness("Virgin Active", 40);

            for (int i=0; i<8; i++)
            {
                for (int j=0; j<50; j++)
                {
                    businesses[i]->hireEmployee(); 
                }
            }

            for (int i=0; i<8; i++)
            {
                businesses[i]->retrench(); 
            }
        }
    
    }

    TEST_CASE("Testing CRS")
    {
        Government* Gov = Government::getInstance(); 
        // Department* ResourceDept = new ResourceDepartment(100000); 
        // Gov->addDepartment("Resources", ResourceDept); 
        Department* FinDept = new FinanceDept(100000); 
        Gov->addDepartment("Finance", FinDept);
        Department* DevDept = new DevelopmentDept(1000000); 
        Gov->addDepartment("Development", DevDept); 
        // Department* TransDept = new TransportDept(100000); 
        // Gov->addDepartment("Transport", TransDept); 
        // Department* healthDept = new HealthDept(100000); 
        // Gov->addDepartment("Health", healthDept); 
        Department* SoAffDept = new SocialAffairsDept(100000); 
        Gov->addDepartment("SocialAffairs", SoAffDept); 

        Business* businesses [8]; 
        businesses[0] = new Automotive();
        businesses[1] = new Consulting(); 
        businesses[2] = new Entertainment();
        businesses[3] = new Food(); 
        businesses[4] = new Hospitality(); 
        businesses[5] = new Retail(); 
        businesses[6] = new Technology(); 
        businesses[7] = new Wellness(); 

        TaxCalculator* taxes[6];
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

        businesses[0]->linkWiseBucks(apps[0]);        
        businesses[1]->linkWiseBucks(apps[0]);        
        businesses[2]->linkWiseBucks(apps[1]);        
        businesses[3]->linkWiseBucks(apps[2]);        
        businesses[4]->linkWiseBucks(apps[3]);        
        businesses[5]->linkWiseBucks(apps[4]);        
        businesses[6]->linkWiseBucks(apps[5]);        
        businesses[7]->linkWiseBucks(apps[5]);   

        Population* AdultFactory = new AdultPop();
        Population* MinorFactory = new MinorPop();

        Citizen** first100 = AdultFactory->reproduce(100); 
        for (int i=0; i<100; i++)
        {
            ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addCitizen(first100[i]);
            ((SocialAffairsDept*)(Gov->getDepartment("SocialAffairs")))->addToUnemployed(first100[i]);
        }

        for (int i=0; i<8; i++)
        {
            for (int j=0; j<5; j++)
            {
                businesses[i]->hireEmployee(); 
            }
        }

        SUBCASE("Verifying Distribute Tax")
        {     
            ((FinanceDept*) Government::getInstance()->getDepartment("Finance"))->getCRS()->distributeTax(); 

            // CHECK((Government::getInstance()->getDepartment("Resources"))->getBudget() == 115000);
            // CHECK((Government::getInstance()->getDepartment("Transport"))->getBudget() == 110000);
            CHECK((Government::getInstance()->getDepartment("Development"))->getBudget() == 1030000);
            CHECK((Government::getInstance()->getDepartment("SocialAffairs"))->getBudget() == 120000);
            // CHECK((Government::getInstance()->getDepartment("Health"))->getBudget() == 110000);
            CHECK((Government::getInstance()->getDepartment("Finance"))->getBudget() == 56000);
        } 

        SUBCASE("Verifying Settle Tax")    
        {
            float current = (Government::getInstance()->getDepartment("Finance"))->getBudget(); 
            cout << current << endl; 
            ((FinanceDept*) Government::getInstance()->getDepartment("Finance"))->getCRS()->settleTax(); 
            ((FinanceDept*) Government::getInstance()->getDepartment("Finance"))->getCRS()->distributeTax(); 
            CHECK((Government::getInstance()->getDepartment("Finance"))->getBudget() > current);
        }

    }

}        

//KARABO SEROTHOANE
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
            Business* shop = new Food();
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

//KATLEGO MOSITI


//PABALLO DIYASE


//RETHABILE BORE


//THENDO MBEDZI
TEST_SUITE("Resource Management System Tests") {
    TEST_CASE("Water Resource Tests") {
        Water* water = new Water();
        
        SUBCASE("Initial State") {
            CHECK(water->getName() == "Water");
            CHECK(water->getState() == "Surplus State");
            CHECK(water->getInitialAmount() == 100000);
        }
        
        SUBCASE("First Consumption") {
            water->consume(18000);
            CHECK(water->getState() == "Balanced State" );
        }
        
        SUBCASE("second State") {
            water->consume(40000);
            CHECK(water->getState() == "Balanced State");
        }
        
        SUBCASE("Critical State") {
            water->consume(40000);
            water->consume(40000);
            CHECK(water->getState() == "Critical State");
        }
        
        SUBCASE("Resource Tracking") {
            water->consume(1000);
            CHECK_NOTHROW(water->trackResources());
        }
        
        delete water;
    }

    TEST_CASE("Energy Resource Tests") {
        Energy* energy = new Energy();
        
        SUBCASE("Initial State") {
            CHECK(energy->getName() == "Energy");
            CHECK(energy->getState() == "Surplus State");
            CHECK(energy->getInitialAmount() == 100000);
        }
        
        SUBCASE("Large Consumption") {
            energy->consume(100002);
            CHECK(energy->getState() == "Surplus State");
        }
        
        SUBCASE("Small Consumption") {
            energy->consume(800);
            CHECK(energy->getState() == "Balanced State");
        }
        
        SUBCASE("Resource Tracking") {
            energy->consume(1000);
            CHECK_NOTHROW(energy->trackResources());
        }
        
        delete energy;
    }

    TEST_CASE("Materials Resource Tests") {
        Materials* steel = new Materials("Steel");
        Materials* wood = new Materials("Wood");
        
        SUBCASE("Initial States") {
            CHECK(steel->getName() == "Material-Steel");
            CHECK(wood->getName() == "Material-Wood");
            CHECK(steel->getState() == "Surplus State");
            CHECK(wood->getState() == "Surplus State");
        }
        
        SUBCASE("Consumption Patterns") {
            steel->consume(5000);
            wood->consume(3000);
            CHECK(steel->getState() == "Balanced State");
            CHECK(wood->getState() == "Balanced State");
        }
        
        delete steel;
        delete wood;
    }

    TEST_CASE("Edge Cases") {
        Water* water = new Water();
        
        SUBCASE("Zero Consumption") {
            water->consume(0);
            CHECK(water->getState() == "Surplus State");
        }
        
        SUBCASE("Very Small Consumption") {
            water->consume(1);
            CHECK(water->getState() == "Balanced State");
        }
        
        SUBCASE("Very Large Consumption") {
            water->consume(999999);
            CHECK(water->getState() == "Surplus State");
        }
        
        delete water;
    }
}