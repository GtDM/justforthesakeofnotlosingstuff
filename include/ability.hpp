#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <functional>
#include <entity.hpp>
#include <iostream>

class Ability
{
    public:
        Ability(int c, std::function <void()> i = [](){std::cout << "One does not simply invoke an ability, that one doesn't have\n";}){cooldown = c; invoke = i;}
        ~Ability(){}

        int getCooldown() { return cooldown; }
        void setCooldown(int val) { cooldown = val; }
        bool isAvailable(){return available;}
        void activate(){available = true;}
        void deactivate(){available = false;}
        std::function <void()> invoke;

    protected:

    private:
        int cooldown; ///TODO All in sf::Time or in number of frames or something and working
        bool available;
};

#endif // ABILITY_HPP
