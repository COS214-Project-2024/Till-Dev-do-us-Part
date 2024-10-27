#ifndef CONTENT_H
#define CONTENT_H

#include "Feeling.h"
#include "Distraught.h"
#include <iostream>
#include <stdlib.h>

//Forward declaration to avoid circular dependencies
class Distraught;

class Content: public Feeling{

    public:
        virtual Feeling* reaction(){
            int num = rand();

            /*Attempt to randomize feeling changes in citizens
            Citizen class(Context) to handle setting new State*/
            
            if((num%2)==0)
                return new Neutral();
            else
                return new Distruaght();
            
        }

};

#endif