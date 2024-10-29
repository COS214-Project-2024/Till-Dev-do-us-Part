#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "Feeling.h"
#include "Content.h"
#include "Distraught.h"
#include <cstdlib>

class Neutral : public Feeling {
    public:
        Neutral();
        virtual Feeling* reaction() override; 
};

#endif 
