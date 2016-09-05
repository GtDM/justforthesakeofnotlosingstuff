#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

enum Side
{
    top, down, left, right
};

class Surface: public sf::RectangleShape
{
    public:
        using sf::RectangleShape::RectangleShape;
        ~Surface();
        std::string getType(){return type;}
        void setType(std::string t);
        std::string getBehavior(Side s); //TODO possibly delete that one
        void setBehavior();
    protected:

    private:
        std::string type;
        std::string behaviorTop;
        std::string behaviorDown;
        std::string behaviorLeft;
        std::string behaviorRight;
};

#endif // SURFACE_HPP
