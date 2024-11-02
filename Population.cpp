#include "Population.h"

Citizen* Population::getPerson(){
    citizen = createPerson();
    return citizen;
}

Citizen** Population::reproduce(int num){

    Citizen** people = new Citizen*[num];
    citizen = createPerson();

    for(int i=0; i<num; i++){
        people[i] = citizen->clone();
    }

    delete citizen;
    return people;
}