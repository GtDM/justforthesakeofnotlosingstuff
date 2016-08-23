#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <functional>
#include <entity.hpp>
#include <iostream>

class Ability
{
    public:
        Ability(int c, std::function <void()> i = [](){std::cout << "One does not simply invoke an ability, that one doesn't have\n";}): invoke(i), cooldown(c){}
        ~Ability(){}
        void setCooldown(int c){ cooldown = c;}
        int getCooldown() { return cooldown; }
        bool isAvailable(){return available;}
        void activate(){available = true;}
        void deactivate(){available = false;}
        std::function <void()> invoke;
    protected:

    private:
        int cooldown;
        bool available;
};

#endif // ABILITY_HPP
