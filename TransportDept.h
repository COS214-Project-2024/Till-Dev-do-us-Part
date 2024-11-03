#ifndef TRANSPORTDEPT_H
#define TRANSPORTDEPT_H

#include "Department.h"
#include "StationFactory.h"
#include "ModeFactory.h"
#include "FacilitiesFactory.h"
#include "TransportMode.h"
#include "TransportStation.h"
#include "TransportFacilities.h"
#pragma once
#include <vector>
#include <map>

class TransportMode;
class TransportFacilities;
class FacilitiesFactory;
class ModeFactory;

class TransportDept : public Department {
private:
        std::map<std::string, StationFactory*> stationfactories; 
        std::map<std::string, ModeFactory*> modefactories;
        std::map<std::string, FacilitiesFactory*> facilitiesfactories;
        std::map<std::string, TransportMode*> vehicles;
        std::map<std::string, TransportStation*> stations;
        std::map<std::string, TransportFacilities*> facilities;
        


public:
    TransportDept(float budget);
    void addSationFactory(std::string type, StationFactory* factory);
    void addModeFactory(std::string type, ModeFactory* factory);
    void addFacilitiesFactory(std::string type, FacilitiesFactory* factory);
    TransportMode* createMode(std::string type);
    TransportFacilities* createFacility(std::string type);
    TransportStation* createStation(std::string type);
    std:: vector<TransportFacilities*> getDeptFacilities(std::string type);
    void addSation(std::string type, TransportStation* station);
    void addMode(std::string type, TransportMode* mode);
    void addFacility(std::string type, TransportFacilities* facility);
    

    

};

#endif 
