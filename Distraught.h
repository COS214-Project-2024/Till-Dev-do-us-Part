#ifndef DISTRAUGHT_H
#define DISTRAUGHT_H

#include "Neutral.h"
#include <iostream>
#include <stdlib.h>

//Forward declaration to avoid circular dependencies
// class Neutral;

class Distraught: public Feeling{

    public:
        Feeling* reaction(){
            int num = rand();

            /*Attempt to randomize feeling changes in citizens
            Citizen class(Context) to handle setting new State*/

            if ((num%2)==0)
                return new Content();
            else    
                return new Neutral();
            
        }

};

#endif;
