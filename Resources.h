#ifndef RESOURCE_H
#define RESOURCE_H

class Resources {
private:
    std::string name;
    float available;
    float maxCapacity;

public:
    Resources(std::string name, float available, float maxCapacity)
        : name(name), available(available), maxCapacity(maxCapacity) {}

    float getAvailable() const { return available; }
    float getMax() const { return maxCapacity; }
};

#endif
