#include "Resources.h"
#include <thread>

Resources::Resources(string name, float initialAmount): INITIAL_AMOUNT(initialAmount), resourceName(name),isRestoring(false)
{
    currentAmount=INITIAL_AMOUNT;
    resState=new SurplusState();
}

Resources::~Resources()
{
    delete resState;
}

void Resources::trackResources()
{
    resState->checkAvailability(this);
}

string  Resources::getState()
{
    return resState->getStatus();
}

void Resources::setState(ResourceState* resourceState)
{
    	if (resState != nullptr)
		delete resState;
    resState = resourceState ;
    alert();
}

float Resources::getCurrentAmount() const
{
    return currentAmount;
}

float Resources::getInitialAmount() const
{
    return INITIAL_AMOUNT;
}


void Resources::alert() {
    float percentage = (currentAmount / INITIAL_AMOUNT) * 100;
        cout << "ALERT: " << resourceName 
             << " is now in " << resState->getStatus() 
             << " at " << currentAmount 
             << " units (" << percentage << "%)" << endl;
}


string Resources::getName() const {
    return resourceName;
}

bool Resources:: consume(float amount) 
{

    if (isRestoring) 
    {
        cout << resourceName << " is currently being restored. Production halted.\n";
        return false;
    }
        if (amount <= 0) {
            cout << "Invalid consumption amount" << endl;
            return false;
        }

    float lowerThreshold = INITIAL_AMOUNT * 0.25; 
    float upperThreshold = INITIAL_AMOUNT * 0.50; 

 
    if (currentAmount < lowerThreshold) 
    {
        cout << "Critical state: " << resourceName << " is below 25% capacity. Please wait while restoring.\n";
        
        
        std::this_thread::sleep_for(std::chrono::seconds(6));
         currentAmount=INITIAL_AMOUNT;
        setState(new SurplusState());
    
        cout << "Restoration completed. You may try to consume again.\n";
        return false; 
    }

   
    if (currentAmount >= lowerThreshold && currentAmount < upperThreshold) 
    {
        cout << "Warning: Current " << resourceName << " level is in shortage state." << endl;
    }
        if (amount > currentAmount) 
        {
            cout << "Insufficient " << resourceName << " available" << endl;
            return false;
        }
        
        currentAmount -= amount;
        cout << amount << " units of " << resourceName << " consumed" << endl;
        trackResources();
       

         return true;
}
