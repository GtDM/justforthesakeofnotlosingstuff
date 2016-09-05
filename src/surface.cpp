#include "surface.hpp"
#include "entity.hpp"


Surface::~Surface()
{
    //dtor
}

void Surface::setType(std::string t)
{
    type = t;
    this->setBehavior();
}

std::string Surface::getBehavior(Side s)
{
    switch(s)
    {
        case top: return behaviorTop;
        case down: return behaviorDown;
        case left: return behaviorLeft;
        case right: return behaviorRight;
    }
}

void Surface::setBehavior()
{
    if(this->getType() == "grass")
    {
        behaviorTop = "top_collision";
        behaviorDown = "down_collision";
        behaviorLeft = "left_collision";
        behaviorRight = "right_collision";
    }
    else if(this->getType() == "water")
    {
        behaviorTop = "";
        behaviorDown = "down_collision";
        behaviorLeft = "";
        behaviorRight = "";
    }
    else
    {
        behaviorTop = "top_collision";
        behaviorDown = "";
        behaviorLeft = "";
        behaviorRight = "";
    }
}

