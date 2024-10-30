#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <map>
#include <string>
#include <vector>
#include "Department.h"
#include "Policy.h"
#include "Memento.h"

class Government {
    private:
        static Government* instance;
        std::vector<Policy> policies;
        std::map<std::string, Department*> departments;
        Government();  // Private constructor for singleton 

    public:
        static Government* getInstance();
        Department* getDepartment(const std::string& name);
        void enactPolicy(const Policy& policy);
        void revertPolicy(const std::string& name);
        void addDepartment(std::string name, Department* department);
        void removeDepartment(std:: string name);
        // void notifyCitizens();
};

#endif