#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "Feeling.h"
#include <iostream>
#include <stdlib.h>

//Forward declaration to avoid circular dependencies
class Distraught;
class Content;

class Neutral: public Feeling{

    public:
        Neutral();
        virtual Feeling* reaction();

};

#endif;
