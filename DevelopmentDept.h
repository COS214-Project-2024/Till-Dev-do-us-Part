////hold factory

#ifndef DevelopmentDept_H
#define DevelopmentDept_H
#include <map>
#include <vector>
#include "Department.h"
#include "BuildingFactory.h"

class DevelopmentDept : public Department {

private:
    int land;
    std::map<std::string,float> priceList;
    std::map<std::string, BuildingFactory*> factories; 
public:
    DevelopmentDept(float budget);
    bool allocateLand(int Landsize);
    float getPrice(std:: string buildingType);
    void addFactory(const std::string& buildingType, BuildingFactory* factory);
    Building* build(std:: string buildingType);

};

#endif 
