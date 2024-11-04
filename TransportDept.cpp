// // #include "TransportDept.h"

// // TransportDept:: TransportDept(float budget)
// // {
// //     this->budget=budget;
// // }

// void TransportDept::addSationFactory(std::string type, StationFactory* factory)
// {
//     stationfactories[type]=factory;
// }
// void TransportDept::addModeFactory(std::string type, ModeFactory* factory)
// {
//     modefactories[type]=factory;
// }
// void TransportDept::addFacilitiesFactory(std::string type, FacilityFactory* factory)
// {
//     facilitiesfactories[type]=factory;
// }
// void TransportDept::createMode(std::string type)
// {
//     if(budget<=0)
//     {
//         std:: cout <<"Transport Mode not created. No budget in the department\n";
//     }
//     map<string,ModeFactory*>::iterator it = modefactories.find(type);
//     if (it != modefactories.end()) {
//         ModeFactory* factory = it->second;
//         budget-=50;//spendmoney
//         return factory->createMode(); 
//     }
//     return nullptr
// }
// void TransportDept::createFacility(std::string type)
// {
//         if(budget<=0)
//     {
//         std:: cout <<"Transport Facility not created. No budget in the department\n";
//     }
//     map<string,FacilityFactory*>::iterator it = facilityfactories.find(type);
    
//     if (it != modefactories.end()) {
//         FacilityFactory* factory = it->second;
//         budget-=50;//spendmoney
//         return factory->createFacility(); 
//     }
//     return nullptr
// }
// void TransportDept::createStation(std::string type)
// {
//     if(budget<=0)
//     {
//         std:: cout <<"Transport Station not created. No budget in the department\n";
//     }
//     map<string,FacilityFactory*>::iterator it = modefactories.find(type);
//     if (it != modefactories.end()) {
//         StationFactory* factory = it->second;
//         budget-=50;//spendmoney
//         return factory->createMode(); 
//     }
//     return nullptr
// }

// vector<TransportFacility*> TransportDept::getDeptFacilities(std::string type)
// {
//     std:: vector<TransportFacility*> v;
//     for(auto it: facilities)
//     {
//         if(it->first()==type)
//         {
//             v.push_back(it->second());
//         }
//     }
//     return v;

// }
// void TransportDept::addSation(std::string type, TransportStation* station)
// {
//     stations[type]= station;
// }
// void TransportDept::addMode(std::string type, TransportMode* mode)
// {
//     vehicles[type]= mode;
// }
// void TransportDept::addFacility(std::string type, TransportFacility* facility)
// {
//     facilities[type]=facility;
// }
