#ifndef MINOR_H
#define MINOR_H

#include "Citizen.h"
#include "Adult.h"
#include "School.h"
#include <string>

class Minor: public Citizen{

    private:
        School* school;
        Adult* parent;
        std::string name;//citizenobserver

    public:
        Minor();
        virtual Citizen* clone();
        virtual void react();
        void goToSchool();
        void setParent(Adult*);
        virtual ~Minor(){}

        // CitizenObserver
        Minor(const std::string& name);
        void update(const std::string& message);
};

#endif