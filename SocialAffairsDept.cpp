#include "SocialAffairsDept.h"

//Budget value to be allocated by government 
SocialAffairsDept::SocialAffairsDept(float b){
    budget = b;
}

//Return a citizen to be employed where needed
Citizen* SocialAffairsDept::employ(){

    if(!unemployed.empty()){
        Citizen* employee = unemployed.front();
        unemployed.pop();
        // cout<<"Successfully employed " << employee.getName() << endl; //Should cout in class that is employing 
        return employee;
    }
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