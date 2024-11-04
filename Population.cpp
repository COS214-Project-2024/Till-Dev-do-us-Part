#include "Population.h"

Citizen* Population::getPerson(){
    citizen = createPerson();
    return citizen;
}

Citizen** Population::reproduce(){

    Citizen** people = new Citizen*[10];
    citizen = createPerson();

    for(int i=0; i<10; i++){
        people[i] = citizen->clone();
    }

    delete citizen;
    return people;
}