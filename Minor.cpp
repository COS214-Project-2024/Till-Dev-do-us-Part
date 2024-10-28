#include "Minor.h"
#include "Content.h"

Minor::Minor(){
    mood = new Content(); //Children generally happy
    employer =0;
}

Citizen* Minor::clone(){
    return new Minor();
}

void Minor::goToSchool(){
    //Need to decide on implementation
}

bool Minor::employmentStatus(){
    return false;
}