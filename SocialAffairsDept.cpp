#include "SocialAffairsDept.h"

SocialAffairsDept:: SocialAffairsDept(float budget) : Department(budget)
{
    
}
void SocialAffairsDept:: addCitizen(Citizen* citizen)
{
    citizens.push_back(citizen);
}
void SocialAffairsDept:: addToEmployed(Citizen* citizen)
{
    employed.push_back(citizen);
}
void SocialAffairsDept:: addToUnemployed(Citizen* citizen)
{
    unmeployed.push_back(citizen);
}
void SocialAffairsDept:: addToMinors(Citizen* citizen)
{
    minors.push_back(citizen);
}
