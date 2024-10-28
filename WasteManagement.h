#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utility.h"
#include "Building.h"
#include <vector>

class WasteManagement : public Utility
{
private:
    std::vector<Building *> wasteSources;
    std::vector<Building *> capacity;

public:
    WasteManagement(int cap) : capacity(cap) {} ;
    WasteManagement(Resources *resource, ResourceDepartment *department, float totalProduction, int workers)
        : Utility("WasteManagement", department, resource, totalProduction, workers) {}

    // Iterator class
    class Iterator
    {
    private:
        std::vector<Building *>::iterator it;

    public:
        explicit Iterator(std::vector<Building *>::iterator initIt) : it(initIt) {}

        Building *operator*() const { return *it; }
        Iterator &operator++()
        {
            ++it;
            return *this;
        }
        bool operator!=(const Iterator &other) const { return it != other.it; }
    };

    // Methods to add/remove buildings as waste sources
    void addWasteSource(Building *building) { wasteSources.push_back(building); }
    void removeWasteSource(Building *building);

    // Methods to obtain iterators
    Iterator begin() { return Iterator(wasteSources.begin()); }
    Iterator end() { return Iterator(wasteSources.end()); }

    void serviceDelivery()
    {
        std::cout << "WasteManagement managing waste. Current capacity: units.\n";
        for (auto building : wasteSources)
        {
            if (building->getWasteAmount() > 0)
            {
                // if (manageWaste(building->getWasteAmount())) {
                //     building->clearWaste();
                // }
            }
        }
    }

    // bool manageWaste(int amount) { return consume(amount); }
};

#endif
