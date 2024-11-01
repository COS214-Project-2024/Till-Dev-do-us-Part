#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department{

    protected:
        float budget;

    public:
        float getBudget(){
            return budget;
        }
        virtual ~Department(){} 

};

#endif