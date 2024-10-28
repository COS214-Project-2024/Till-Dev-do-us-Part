#include "TransportDept.h"

TransportDept:: TransportDept(float budget)
{
    this->budget=budget;
}

void addSationFactory(std::string type, StationFactory* factory)
{
    stationfactories[type]=factory;
}
void addModeFactory(std::string type, ModeFactory* factory)
{
    modefactories[type]=factory;
}
void addFacilitiesFactory(std::string type, FacilityFactory* factory)
{
    facilitiesfactories[type]=factory;
}
void createMode(std::string type)
{
    if(budget<=0)
    {
        std:: cout <<"Transport Mode not created. No budget in the department\n";
    }
    vector<ModeFactory*>::iterator it = modefactories.find(type);
    if (it != modefactories.end()) {
        ModeFactory* factory = it->second;
        budget-=50;//spendmoney
        return factory->createMode(); 
    }
    return nullptr
}
void createFacility(std::string type)
{
        if(budget<=0)
    {
        std:: cout <<"Transport Facility not created. No budget in the department\n";
    }
    vector<FacilityFactory*>::iterator it = facilityfactories.find(type);
    if (it != modefactories.end()) {
        FacilityFactory* factory = it->second;
        budget-=50;//spendmoney
        return factory->createFacility(); 
    }
    return nullptr
}
void createStation(std::string type)
{
    if(budget<=0)
    {
        std:: cout <<"Transport Station not created. No budget in the department\n";
    }
    vector<StationFactory*>::iterator it = modefactories.find(type);
    if (it != modefactories.end()) {
        StationFactory* factory = it->second;
        budget-=50;//spendmoney
        return factory->createMode(); 
    }
    return nullptr
}