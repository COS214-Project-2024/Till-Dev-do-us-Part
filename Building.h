#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <vector>
#include "ResourceDepartment.h"
using namespace std;

class Citizen;       // for now since Citizen is not defined
class BuildingState; // for now since BuildingState is not defined

class Building
{
protected:
    ResourceDepartment *resourceDepartment;
    std::vector<Citizen *> residents;
    int wasteAmount;
    int waterAmount;
    int sewageAmount;
    bool wasteCleared;
    bool sewageCleared;
    const int wasteThreshold = 100;
    const int sewageThreshold = 100;

    int initialElectricityUnits = 50; // Example: initial electricity units
    int initialWaterUnits = 30;       // Example: initial water units

    // void affectResidentsMood(int moodChange)
    // {
    //     for (Citizen *resident : residents)
    //     {
    //         resident->adjustMood(moodChange);
    //         std::cout << "Mood of resident adjusted, current mood: " << resident->getMood() << std::endl;
    //     }
    // }

public:
    Building(ResourceDepartment *resourceDept) : resourceDepartment(resourceDept), wasteAmount(0), waterAmount(0), sewageAmount(0), wasteCleared(true), sewageCleared(true)
    {
        // Request initial resources upon building creation
        bool initialElectricityAvailable = resourceDepartment->requestElectricity(initialElectricityUnits);
        bool initialWaterAvailable = resourceDepartment->requestWater(initialWaterUnits);

        if (initialElectricityAvailable)
        {
            std::cout << "Building loaded with initial electricity: " << initialElectricityUnits << " units." << std::endl;
        }
        else
        {
            std::cout << "Initial electricity not available!" << std::endl;
            affectResidentsMood(-5); // Affect mood due to lack of initial electricity
        }

        if (initialWaterAvailable)
        {
            std::cout << "Building loaded with initial water: " << initialWaterUnits << " units." << std::endl;
        }
        else
        {
            std::cout << "Initial water not available!" << std::endl;
            affectResidentsMood(-5); // Affect mood due to lack of initial water
        }
    }

    void addResident(Citizen *occupant)
    {
        residents.push_back(occupant);
        std::cout << "Resident added to building. Total residents: " << residents.size() << std::endl;
    }

    void sendResidentsToWork()
    {
        int totalElectricityConsumption = residents.size() * 5;
        int totalWaterConsumption = residents.size() * 3;
        int totalSewageGeneration = residents.size() * 2;

        bool electricityAvailable = resourceDepartment->requestElectricity(totalElectricityConsumption);
        bool waterAvailable = resourceDepartment->requestWater(totalWaterConsumption);

        if (electricityAvailable)
        {
            std::cout << "Building consumed " << totalElectricityConsumption << " units of electricity for work." << std::endl;
        }
        else
        {
            std::cout << "Not enough electricity available for work!" << std::endl;
            affectResidentsMood(-5);
        }

        if (waterAvailable)
        {
            std::cout << "Building consumed " << totalWaterConsumption << " units of water for work." << std::endl;
        }
        else
        {
            std::cout << "Not enough water available for work!" << std::endl;
            affectResidentsMood(-5);
        }

        accumulateWaste();
        accumulateSewage(totalSewageGeneration);

        if (!wasteCleared && wasteAmount > wasteThreshold)
        {
            affectResidentsMood(-10);
            std::cout << "Mood of residents affected due to uncleared waste." << std::endl;
        }

        if (!sewageCleared && sewageAmount > sewageThreshold)
        {
            affectResidentsMood(-10);
            std::cout << "Mood of residents affected due to uncleared sewage." << std::endl;
        }
    }

    void accumulateWaste()
    {
        int wastePerResident = 2;
        wasteAmount += residents.size() * wastePerResident;
        wasteCleared = false;
        std::cout << "Building accumulated " << residents.size() * wastePerResident << " units of waste. Total waste: " << wasteAmount << std::endl;
    }

    void accumulateSewage(int amount)
    {
        sewageAmount += amount;
        sewageCleared = false;
        std::cout << "Building generated " << amount << " units of sewage. Total sewage: " << sewageAmount << std::endl;
    }

    int getWasteAmount() const
    {
        return wasteAmount;
    }
    int getSewageAmount() const
    {
        return sewageAmount;
    }

    void clearWaste()
    {
        wasteAmount = 0;
        wasteCleared = true;
        std::cout << "Building waste cleared." << std::endl;
    }

    void clearSewage()
    {
        sewageAmount = 0;
        sewageCleared = true;
        std::cout << "Building sewage cleared." << std::endl;
    }
};

#endif
