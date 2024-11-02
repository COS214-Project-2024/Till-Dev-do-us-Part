#ifndef MATERIALS_H
#define MATERIALS_H

#include "Resources.h"

class Materials : public Resources {
private:
    string materialType;
public:
    Materials(string type);
};

#endif
