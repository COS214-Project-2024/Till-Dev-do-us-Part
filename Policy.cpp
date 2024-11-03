#include "Policy.h"
#include <iostream>

Policy::Policy( std::string name, std::string code,std::string description)
    : name(name), code(code), description(description) {}



std::string Policy:: getName()
{
    return name;
}
std::string Policy:: getDescription()
{
    return description;
}

Policy:: ~Policy()
{
    

}

