#include "SocialAffairsDept.h"
#include <iostream>


//Budget value to be allocated by government 
SocialAffairsDept::SocialAffairsDept(float b){
    budget = b;
}

//Return a citizen to be employed where needed
Citizen* SocialAffairsDept::employ(Business* employer){

    if(!unemployed.empty()){
        
        Citizen* employee = unemployed.front();
        employee->setEmployer(employer);
        unemployed.pop();
        // cout<<"Successfully employed " << employee.getName() << endl; //Should cout in class that is employing 
        return employee;
    }
    else{
        std::cout<< "There are no available citizens to employ " << std::endl; 
        return nullptr;
    }
}

void SocialAffairsDept::addCitizen(Citizen* person){
    // citizens.pushback(person);

    // if(person->employmentStatus)

    //Most effective way to implement??
}

//Get number of citizens
int SocialAffairsDept::getNumCitizens(){
    return citizens.size();
}

//Destruct 
SocialAffairsDept::~SocialAffairsDept(){
    for(int i=0; i<unemployed.size();i++){
        Citizen* employee = unemployed.front();
        delete employee;
        unemployed.pop();
    }
}

void SocialAffairsDept::growPopulation(){
    //call on factory to create mmore people
}