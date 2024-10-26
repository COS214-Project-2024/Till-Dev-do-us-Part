#include "Resources.h"

Resources::Resources(string name, float initialAmount): INITIAL_AMOUNT(initialAmount), resourceName(name)
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
    notifyObservers();
}

float Resources::getCurrentAmount() const
{
    return currentAmount;
}

float Resources::getInitialAmount() const
{
    return INITIAL_AMOUNT;
}

// void Resources::attachObserver(ResourceObserver* observer) {
//     observers.push_back(observer);
// }

void Resources::notifyObservers() {
    float percentage = (currentAmount / INITIAL_AMOUNT) * 100;
        cout << "ALERT: " << resourceName 
             << " is now in " << resState->getStatus() 
             << " at " << currentAmount 
             << " units (" << percentage << "%)" << endl;
}

// void Resources::setCurrentAmount(float amount) {
//     currentAmount = amount;
//     trackResources();
// }

string Resources::getName() const {
    return resourceName;
}

bool Resources:: consume(float amount) {
        if (amount <= 0) {
            cout << "Invalid consumption amount" << endl;
            return false;
        }
        if (amount > currentAmount) {
            cout << "Insufficient " << resourceName << " available" << endl;
            return false;
        }
        
        currentAmount -= amount;
        cout << amount << " units of " << resourceName << " consumed" << endl;
        trackResources();
        return true;
    }