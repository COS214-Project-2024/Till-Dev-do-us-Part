/// i think this will be the Land and Development Department
// BuildingIterator.h
#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H

#include "Building.h"
#include <vector>

class BuildingIterator
{
private:
    const std::vector<Building *> &buildings;
    size_t index;

public:
    BuildingIterator() : buildings({}), index(0) {}
    BuildingIterator(const std::vector<Building *> &buildings)
        : buildings(buildings), index(0) {}

    bool hasNext() const
    {
        return index < buildings.size();
    }

    Building *next()
    {
        if (hasNext())
        {
            return buildings[index++];
        }
        return nullptr;
    }

    void reset()
    {
        index = 0;
    }
};

#endif // BUILDINGITERATOR_H