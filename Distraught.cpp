#include "Neutral.h"
#include "Content.h"  
#include "Distraught.h"

Distraught::Distraught(){
    name = "Distraught";
}

Feeling* Distraught::reaction() {
    int num = rand();

    // Attempt to randomize feeling changes in citizens
    // Citizen class (Context) to handle setting new State

    if ((num % 2) == 0)
        return (Feeling*) new Content();
    else    
        return (Feeling*) new Neutral();
}