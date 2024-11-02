#ifndef TRANSPORTDEPT_H
#define TRANSPORTDEPT_H

#include "Department.h"
#include "StationFactory.h"
#include "ModeFactory.h"
#include "FacilitiesFactory.h"
#include "TransportMode.h"
#include "TransportStation.h"
#include "TransportFacility.h"
#include <vector>


class TransportDept : public Department {
private:
        std::map<std::string, StationFactory*> stationfactories; 
        std::map<std::string, ModeFactory*> modefactories;
        std::map<std::string, FacilitiesFactory*> stationfactories;
        std::vector<TransportMode*> vehicles;
        std::vector<TransportStation*> stations;
        std::map<std::string, TransportFacility*> facilities;
        


public:
    TransportDept(float budget);
    void addSationFactory(std::string type, StationFactory* factory);
    void addModeFactory(std::string type, ModeFactory* factory);
    void addFacilitiesFactory(std::string type, FacilityFactory* factory);
    void createMode(std::string type);
    void createFacility(std::string type);
    void createStation(std::string type);
    vector<TransportFacility*> getDeptFacilities(std::string type);
    void addSation(std::string type, TransportStation* station);
    void addMode(std::string type, TransportMode* mode);
    void addFacility(std::string type, TransportFacility* facility);
    

    

};

// ModeFactory* carfactory= new Carfactory();
// departmentT->addModeFactory("Car", carfactory);
// TransportMode * car= departmentT->createMode("Car");


#endif 
