
#ifndef RESOURCES_H
#define RESOURCES_H
#include <iostream>
#include "ResourceState.h"
#include "SurplusState.h"

#include <vector>

using namespace std;
class ResourceState;
class ResourceObserver;
#include <chrono>

class Resources
{
    private:
     ResourceState* resState;
     float currentAmount;    
    const float INITIAL_AMOUNT;  
    string resourceName;
       bool isRestoring;
    std::chrono::steady_clock::time_point restoreStartTime;


  

    public :
        Resources(string name, float initialAmount); 

        void trackResources();
        string getState();
         void setState(ResourceState* resourceState);
        virtual ~Resources();
        float getCurrentAmount() const; 
       float getInitialAmount() const ; 
        virtual string getName() const;
        bool consume(float amount);
        void alert();


  
 
   
};

#endif
