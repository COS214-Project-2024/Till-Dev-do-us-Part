#ifndef DISTRAUGHT_H
#define DISTRAUGHT_H

#include "Feeling.h"
#include "Content.h"
#include "Neutral.h"
#include <cstdlib>

class Distraught : public Feeling {
    public:
        Distraught();
        virtual Feeling* reaction(); 
};

#endif 
