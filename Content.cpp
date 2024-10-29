#include "Neutral.h"
#include "Content.h"  
#include "Distraught.h"

Content::Content(){
    name = "Content";
}

Feeling* Content:: reaction(){
    int num = rand();

    /*Attempt to randomize feeling changes in citizens
    Citizen class(Context) to handle setting new State*/
    
    if((num%2)==0)
        return (Feeling*) new Neutral();
    else
        return (Feeling*) new Distraught();
        
}