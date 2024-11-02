#include "TransportDept.h"

void TransportDept::addSationFactory(std::string type, StationFactory* factory)
{
    stationfactories[type]=factory;
}
void TransportDept::addModeFactory(std::string type, ModeFactory* factory)
{
    modefactories[type]=factory;
}
void TransportDept::addFacilitiesFactory(std::string type, FacilitiesFactory* factory)
{
    facilitiesfactories[type]=factory;
}
TransportMode* TransportDept::createMode(std::string type)
{
    if(budget<=0)
    {
        std:: cout <<"Transport Mode not created. No budget in the department\n";
    }
    std::map<std::string,ModeFactory*>::iterator it = modefactories.find(type);
    if (it != modefactories.end()) {
        ModeFactory* factory = it->second;
        budget-=50;//spendmoney
        return factory->createMode(); 
    }
    return nullptr;
}
TransportFacilities* TransportDept::createFacility(std::string type)
{
        if(budget<=0)
    {
        std:: cout <<"Transport Facility not created. No budget in the department\n";
    }
    std:: map<std:: string,FacilitiesFactory*>::iterator it = facilitiesfactories.find(type);
    
    if (it != facilitiesfactories.end()) {
        FacilitiesFactory* factory = it->second;
        budget-=50;//spendmoney
        return factory->createFacilities(); 
    }
    return nullptr;
}
TransportStation* TransportDept::createStation(std::string type)
{
    if(budget<=0)
    {
        std:: cout <<"Transport Station not created. No budget in the department\n";
    }
    std:: map<std:: string,StationFactory*>::iterator it = stationfactories.find(type);
    if (it != stationfactories.end()) {
        StationFactory* factory = it->second;
        budget-=50;//spendmoney
        return factory->createStation(); 
    }
    return nullptr;
}

std:: vector<TransportFacilities*> TransportDept::getDeptFacilities(std::string type)
{
    std:: vector<TransportFacilities*> v;
    for(auto &it: facilities)
    {
        if(it.first==type)
        {
            v.push_back(it.second);
        }
    }
    return v;

}
void TransportDept:: addSation(std::string type, TransportStation* station)
{
    stations[type]= station;
}
void TransportDept:: addMode(std::string type, TransportMode* mode)
{
    vehicles[type]= mode;
}
void TransportDept:: addFacility(std::string type, TransportFacilities* facility)
{
    facilities[type]=facility;
}
