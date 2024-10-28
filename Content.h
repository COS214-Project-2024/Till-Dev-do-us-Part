#ifndef CONTENT_H
#define CONTENT_H

#include "Feeling.h"
#include <iostream>
#include <stdlib.h>

class Neutral;
class Distraught;

//Forward declaration to avoid circular dependencies

class Content: public Feeling{

    public:
        Feeling* reaction();

};

#endif