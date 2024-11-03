#ifndef MINOR_H
#define MINOR_H

#include "Citizen.h"
#include "Adult.h"
#include "School.h"

class Minor: public Citizen{

    private:
        School* school;
        Adult* parent;

    public:
        Minor();
        virtual Citizen* clone();
        virtual void react();
        void goToSchool();
        void setParent(Adult*);
        virtual ~Minor(){}
};

#endif