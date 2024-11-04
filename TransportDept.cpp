#include "TransportDept.h"
#include "TransportFacilities.h"
#include "TransportMode.h"

TransportDept:: TransportDept(float budget)
{
    this->budget=budget;
    facilities={};
}




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
 
    if(type=="Road"){
        
        
        return roadroad;
    }
    
    if(type=="Railway"){
        return wayway;
    }
    if(type=="Airport"){
        return portport;
    }
    
}
void TransportDept:: addSation(std::string type, TransportStation* station)
{
    stations[type]= station;
}
void TransportDept:: addMode(std::string type, TransportMode* mode)
{
    vehicles[type]= mode;
}
void TransportDept:: addFacility(TransportFacilities* facility)
{
    if(facility->getFacilName()=="Road"){
        roadroad.push_back(facility);
    }
    if(facility->getFacilName()=="Railway"){
        wayway.push_back(facility);
    }
    if(facility->getFacilName()=="Airport"){
        portport.push_back(facility);
    }
}
