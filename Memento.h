#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>
#include <vector>

class Policy;  // Forward declaration

class Memento {
private:
    std::vector<Policy*> activePolicies;

public:
    Memento();
    std::vector<Policy*> getActivePolicies();
    void setActivePolicies(std::vector<Policy*> policies);
    ~Memento();
};

#endif 
