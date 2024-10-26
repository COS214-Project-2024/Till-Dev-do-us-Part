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
                                      //// Accumulated Waste and Sewage in the building
    int wasteAmount;
    int waterAmount;
    int sewageAmount;
    bool wasteCleared;               // Track if waste has been cleared
    bool sewageCleared;              // Track if sewage has been cleared
    const int wasteThreshold = 100;  // Threshold for affecting mood due to waste
    const int sewageThreshold = 100; // Threshold for affecting mood due to sewage

private:
    //// i  affect the mood the like this cause it doesnt make sense for citizens to just jump states like that
    ////like you sad cause you dont have electricity but all of a sudden you happy cause you have water?
    void affectResidentsMood(int moodChange)
    {
        for (Citizen *resident : residents)
        {
            resident->adjustMood(moodChange);
            std::cout << "Mood of resident adjusted, current mood: " << resident->getMood() << std::endl;
        }
    }

public:
    // Building(string type);
    // ~Building();
  
    ////Because we access citizens through the buildings they occcupy I use the
    void addResident(Citizen *occupant)
    {
        residents.push_back(occupant);
        std::cout << "Resident added to building. Total residents: " << residents.size() << std::endl;
    }
  //// I dont use these load functions to give buildings resources initailly like upon creation

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

    ////Instead this implementation >>>
    void sendResidentsToWork()
    {
        int totalElectricityConsumption = residents.size() * 5; // Example: 5 units per resident
        int totalWaterConsumption = residents.size() * 3;       // Example: 3 units of water per resident
        int totalSewageGeneration = residents.size() * 2;       // Example: 2 units of sewage per resident

//See resource department to see how this is handled
        bool electricityAvailable = resourceDepartment->requestElectricity(totalElectricityConsumption);
        bool waterAvailable = resourceDepartment->requestWater(totalWaterConsumption);

        if (electricityAvailable)
        {
            std::cout << "Building consumed " << totalElectricityConsumption << " units of electricity for work." << std::endl;
        }
        else
        {
            std::cout << "Not enough electricity available for work!" << std::endl;
            affectResidentsMood(-5); // Affect mood due to lack of electricity
        }

        if (waterAvailable)
        {
            std::cout << "Building consumed " << totalWaterConsumption << " units of water for work." << std::endl;
        }
        else
        {
            std::cout << "Not enough water available for work!" << std::endl;
            affectResidentsMood(-5); // Affect mood due to lack of water
        }

        accumulateWaste();
        accumulateSewage(totalSewageGeneration);

        // Check waste clearance; if not cleared and over threshold, affect mood
        if (!wasteCleared && wasteAmount > wasteThreshold)
        {
            affectResidentsMood(-10); // Affect mood due to uncleared waste
            std::cout << "Mood of residents affected due to uncleared waste." << std::endl;
        }

        // Check sewage clearance; if not cleared and over threshold, affect mood
        if (!sewageCleared && sewageAmount > sewageThreshold)
        {
            affectResidentsMood(-10); // Affect mood due to uncleared sewage
            std::cout << "Mood of residents affected due to uncleared sewage." << std::endl;
        }
    }

    //// Accumulate waste each time residents go to work
    accumulateWaste();

    //// Check waste clearance; if not cleared and over threshold, affect mood
    if (!wasteCleared && wasteAmount > wasteThreshold)
    {
        affectResidentsMood(-10); // Affect mood negatively due to uncleared waste
        std::cout << "Mood of residents affected due to uncleared waste." << std::endl;
    }
};

void accumulateSewage(int amount)
{
    sewageAmount += amount;
    sewageCleared = false; // Mark sewage as uncleared
    std::cout << "Building generated " << amount << " units of sewage. Total sewage: " << sewageAmount << std::endl;
}

void accumulateWaste()
{
    int wastePerResident = 2; // Example: 2 units of waste generated per resident per work session
    wasteAmount += residents.size() * wastePerResident;
    wasteCleared = false; // Mark waste as not cleared
    std::cout << "Building accumulated " << residents.size() * wastePerResident
              << " units of waste. Total waste: " << wasteAmount << std::endl;
}

int getWasteAmount() const
{
    return wasteAmount;
}

void clearWaste()
{
    wasteAmount = 0;
    wasteCleared = true; // Mark waste as cleared
    std::cout << "Building waste cleared." << std::endl;
}

void clearSewage()
{
    sewageAmount = 0;
    sewageCleared = true; // Mark sewage as cleared
    std::cout << "Building sewage cleared." << std::endl;
}

#endif