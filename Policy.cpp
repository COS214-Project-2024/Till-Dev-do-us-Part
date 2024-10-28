#include "Policy.h"

Policy::Policy( std::string name, std::string code)
    : name(name), code(code) {}



std::string Policy:: getName()
{
    return name;
}
