#include "Materials.h"

Materials::Materials(string type) 
    : Resources("Material-" + type, 100000), materialType(type) {}
