#ifndef RESOURCE_H
#define RESOURCE_H

class Resource {
private:
    std::string name;
    float available;
    float maxCapacity;

public:
    Resource(std::string name, float available, float maxCapacity)
        : name(name), available(available), maxCapacity(maxCapacity) {}

    float getAvailable() const { return available; }
    float getMax() const { return maxCapacity; }
};

#endif
