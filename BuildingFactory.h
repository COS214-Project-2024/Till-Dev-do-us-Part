#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H
class Building;  // Forward declaration

class BuildingFactory{

protected:
    Building* building;

public:
    //BuildingFactory();
    virtual Building* build()=0;
    virtual ~BuildingFactory() {
        delete building;
        building = nullptr;
    }

};

#endif