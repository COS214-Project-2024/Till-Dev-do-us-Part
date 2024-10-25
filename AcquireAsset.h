#ifndef ACQUIREASSET_H
#define ACQUIREASSET_H

#include "Adult.h"

//Public adult or citizen, check with UML too
class AcquireAsset:public Adult{

    private:
        Citizen* adult;

};

#endif
