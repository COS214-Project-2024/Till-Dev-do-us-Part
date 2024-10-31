
#ifndef RESOURCES_H
#define RESOURCES_H
#include <iostream>
#include "ResourceState.h"
#include "SurplusState.h"

#include <vector>

using namespace std;
class ResourceState;
class ResourceObserver;

class Resources{
    private:
     ResourceState* resState;
     float currentAmount;    //    float available;
    const float INITIAL_AMOUNT;  //  float maxCapacity;
    string resourceName;

// std::string name;

  

    public :
        Resources(string name, float initialAmount);   //    Resources(std::string name, float available, float maxCapacity)
        //: name(name), available(available), maxCapacity(maxCapacity) {}

        void trackResources();
        string getState();
         void setState(ResourceState* resourceState);
        virtual ~Resources();
        float getCurrentAmount() const; //  float getAvailable() const { return available; }
       float getInitialAmount() const ;  // float getMax() const { return maxCapacity; }
        virtual string getName() const;
        bool consume(float amount);
        void alert();



 
   
};

#endif
