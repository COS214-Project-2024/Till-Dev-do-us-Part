#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>
#include <vector>

class Policy;  // Forward declaration

class Memento {
private:
    float budget;
    std::vector<Policy> activePolicies;

public:
    float getBudget() const;
    void setBudget(float budget);
    std::vector<Policy> getActivePolicies() const;
    void setActivePolicies(const std::vector<Policy>& policies);
};

#endif 
