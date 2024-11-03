// #include <iostream>
// #include <queue>
// #include <vector>
// #include "Citizen.h"      
// #include "HaveChild.h"
// #include "SocialAffairsDept.h"
// #include <iostream>


// using namespace std;

// SocialAffairsDept::SocialAffairsDept(float b){
//     budget = b;
// }

// Citizen* SocialAffairsDept::employ(Business* job) {

//     // cout << "Entering employ" << endl;

//     if (!unemployed.empty()) {

//         // cout<< "Employing citizen..." << endl;
//         Adult* employee = (Adult*) (unemployed.front());
//         employee->setJob(job);
//         unemployed.pop();

//         return (Citizen*) employee;
//     } else {
//         std::cout << "There are no citizens to employ " << std::endl;
//         return nullptr;
//     }
// }

// void SocialAffairsDept::addCitizen(Citizen* citizen) {
//     adults.push_back(citizen);
//     // cout << "Added new adult to adults vector " << endl;
// }

// void SocialAffairsDept::addChild(Citizen* citizen) {
//     children.push_back(citizen);
//     // cout << "Added new child to children vector " << endl;
// }

// void SocialAffairsDept::addToUnemployed(Citizen* person) {
//     unemployed.push(person);
//     // cout << "Added new adult to unemployed queue " << endl;
// }

// int SocialAffairsDept::getNumCitizens() {
//     return (adults.size() + children.size());
// }

// void SocialAffairsDept::growPopulation(int n) {
    
//     factory = new AdultPop();
//     Citizen** community = factory->reproduce(n);

//     for (int i = 0; i < n; i++) {
//         addCitizen(community[i]); 
//     }

//     delete[] community;
//     delete factory;

//     factory = new MinorPop();

//     int num = 0;
//     auto it = adults.begin();

//     for (int i = 0; it != adults.end(); ++it, i+=2) {
   
//         if ((i % 3) != 0)
//             continue;

//         num++;
//         HaveChild* parent = new HaveChild(*it); 
//         Citizen* child = factory->getPerson();
//         parent->haveChild(child); 
//         *it = (Citizen*) parent;
//     }

//     delete factory;
//     cout << "Increased current population by 10 adults and " << num << " kids" << endl;
// }

// SocialAffairsDept::~SocialAffairsDept() {
   
//     while (!unemployed.empty()) {
//         Citizen* employee = unemployed.front();
//         employee = nullptr;  
//         unemployed.pop();  
//     }

//     for (auto adult : adults) {
//         delete adult;
//         adult = nullptr;  
//     }

//     for (auto child : children) {
//         delete child;
//         child = nullptr;  
//     }

//     adults.clear();
//     children.clear();  
//     factory = nullptr;
// }

