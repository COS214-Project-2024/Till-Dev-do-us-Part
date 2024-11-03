#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department {
protected:
    float budget;

public:
    // Department(float budget) : budget(budget) {}

    void receiveTax(float amount)
    {
        if (amount > 0)
            budget += amount; 
            
    }

    float getBudget()
    {
        return budget; 
    }
    
    virtual ~Department(){}
};

#endif 
