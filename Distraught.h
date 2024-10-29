#ifndef DISTRAUGHT_H
#define DISTRAUGHT_H

#include <iostream>
#include <stdlib.h>

#include "Feeling.h"

// Forward declarations to avoid circular dependencies
class Neutral;
class Content;

class Distraught : public Feeling {

    public:
        Distraught();
        virtual Feeling* reaction();
};

#endif // DISTRAUGHT_H
