#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "Content.h"
#include <iostream>
#include <stdlib.h>

//Forward declaration to avoid circular dependencies
class Content;

class Neutral: public Feeling{

    public:
        virtual Feeling* reaction(){
            int num = rand();

            /*Attempt to randomize feeling changes in citizens
            Citizen class(Context) to handle setting new State*/

            if((num%2)==0)
                return new Content();
            else
                return new Distruaght();
            
        }

};

#endif;
