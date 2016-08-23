#include "surface.hpp"


Surface::~Surface()
{
    //dtor
}

void Surface::setType(std::string t)
{
    type = t;
    this->setBehavior();
}

void Surface::getBehavior(Side s)
{

}

void Surface::setBehavior()
{
    if(this->getType() == "grass")
    {

    }
    else if(this->getType() == "water")
    {

    }
    else
    {

    }
}
