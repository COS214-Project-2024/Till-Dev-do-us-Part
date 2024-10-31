#ifndef FEELING_H
#define FEELING_H

#include <string>

class Feeling {
    protected:
        std::string name;

    public:
        virtual Feeling* reaction() = 0; 
        virtual std::string getName() const {
            return name;
        }
        virtual ~Feeling() {}
};

#endif 