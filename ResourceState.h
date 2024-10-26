#ifndef RESOURCESTATE_H
#define RESOURCESTATE_H
#include <iostream>
using namespace std;



class Resources;
class ResourceState{
    public :
        virtual void checkAvailability(Resources* resource)=0;
        virtual string getStatus()=0;
        virtual ~ResourceState()=default;
};

#endif