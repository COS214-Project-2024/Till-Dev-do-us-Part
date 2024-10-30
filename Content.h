#ifndef CONTENT_H
#define CONTENT_H

#include "Feeling.h"
#include "Neutral.h"
#include "Distraught.h"
#include <cstdlib>

class Content : public Feeling {
    public:
        Content();
        virtual Feeling* reaction(); 
};

#endif 