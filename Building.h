// = Original
//// = My Comments
#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <vector>
#include "ResourceDepartment.h"
using namespace std;

class Citizen;       // for now since Citizen is not defined
class BuildingState; // for now since Citizen is not defined

class Building
{
protected:
    // BuildingState* state;
    // string type;
    // float area;
    // float value;
    // int floor; //dk how im going to use it now, 'cause im planning on adding a floor decorator
    // float electricityUnits;
    // float waterUnits;
    // int capacity;

    ////  Pointer to the resource department so buildings don't communicate with utilities directly

    ResourceDepartment *resourceDepartment;

    //// And I'm assuming that we access citizens through the buildings they occcupy -
    //// (i feel like its easier  that way because we attach a citizens to homes and not vice versa idk :\ )
    std::vector<Citizen *> residents; //// for now im assuming only residential buildings consume resources
//// Accumulated waste in the building
    int wasteAmount;      // Accumulated waste in the building
    bool wasteCleared;       // Flag to track if waste has been cleared recently
    const int wasteThreshold = 100; // Example threshold for affecting mood

    private:
    void affectResidentsMood(int moodChange) {
        for (Citizen* resident : residents) {
            resident->adjustMood(moodChange);
            std::cout << "Mood of resident adjusted, current mood: " << resident->getMood() << std::endl;
        }
    }
};

public:
    // Building(string type);
    // ~Building();
    //// I dont use these load functions to give buildings resources initailly like upon creation

    ////Because we access citizens through the buildings they occcupy I use the
    void addResident(Citizen *occupant)
    {
        residents.push_back(occupant);
        std::cout << "Resident added to building. Total residents: " << residents.size() << std::endl;
    }

    // virtual void loadElectricity(int units); //needs utilities
    // virtual void loadWater(int units); //needs utilities
    // virtual bool useElectricity(int units);
    // virtual bool useWater(int units);
    // virtual void demolish()=0;

    //// Call goToWork for each resident 
    //// I dont want to do it  this way cause it complicates how energy gets consumed
    //// see adult->goToWork() for more info
    void sendResidentsToWork()
    {
        for (Citizen *adult : residents)
        {
            adult->goToWork();
        }
    };

    
    
////Instead this implementation.
void sendResidentsToWork() {
        int totalElectricityConsumption = residents.size() * 5; // Example: 5 units per resident

        if (resourceDepartment->requestElectricity(totalElectricityConsumption)) {
            std::cout << "Building consumed " << totalElectricityConsumption << " units of electricity for work." << std::endl;
        } else {
            std::cout << "Not enough electricity available for work!" << std::endl;
            //affect mood if resources denied
            for (Citizen* resident : residents) {
                resident->adjustMood(-5); 
                std::cout << "Mood of resident affected, current mood: " << resident->getMood() << std::endl;
            }
        }
    }

    //// Accumulate waste each time residents go to work
        accumulateWaste();

        //// Check waste clearance; if not cleared and over threshold, affect mood
        if (!wasteCleared && wasteAmount > wasteThreshold) {
            affectResidentsMood(-10); // Affect mood negatively due to uncleared waste
            std::cout << "Mood of residents affected due to uncleared waste." << std::endl;
        }
};

void accumulateWaste() {
       int wastePerResident = 2; // Example: 2 units of waste generated per resident per work session
        wasteAmount += residents.size() * wastePerResident;
        wasteCleared = false; // Mark waste as not cleared
        std::cout << "Building accumulated " << residents.size() * wastePerResident 
                  << " units of waste. Total waste: " << wasteAmount << std::endl;
    }

    int getWasteAmount() const {
        return wasteAmount;
    }

    void clearWaste() {
        wasteAmount = 0;
        wasteCleared = true; // Mark waste as cleared
        std::cout << "Building waste cleared." << std::endl;
    }



#endif