#ifndef FEELING_H
#define FEELING_H

#include <string>

using namespace std;

class Feeling{

    protected:
        string name;

    public:
        virtual Feeling* reaction() = 0;
        virtual std::string getName(){
            return name;
        }
        virtual ~Feeling() {}

};

#endif