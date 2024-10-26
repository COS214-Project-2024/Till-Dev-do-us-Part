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
     float currentAmount;
    const float INITIAL_AMOUNT;  // >=100% level
    string resourceName;
    //vector<ResourceObserver*> observers;

    public :
        Resources(string name, float initialAmount);
        void trackResources();
        string getState();
         void setState(ResourceState* resourceState);
        virtual ~Resources();
        float getCurrentAmount() const;
       float getInitialAmount() const ;
       // void setCurrentAmount(float amount);
    string getName() const;
        bool consume(float amount);

    
    // void attachObserver(ResourceObserver* observer);
     void notifyObservers();
};

#endif