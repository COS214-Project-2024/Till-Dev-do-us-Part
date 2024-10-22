#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department {
protected:
    float budget;

public:
    Department(float budget) : budget(budget) {}
    virtual ~Department() = default;
};

#endif 
