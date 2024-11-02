#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>
#include <vector>

class Policy;  // Forward declaration

class Memento {
private:
    float budget;
    std::vector<Policy*> activePolicies;

public:
    std::vector<Policy*> getActivePolicies();
    void setActivePolicies(std::vector<Policy*> policies);
    ~Memento();
};

#endif 
