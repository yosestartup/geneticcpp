#include "CVarVls.h"


double CVarVls::getValue()
{
    return value;
}
std::string CVarVls::getName()
{
    return name;
}
void CVarVls::setValue(double tempValue)
{
    value = tempValue;
}
void CVarVls::setName(std::string tempName)
{
    name = tempName;
}
