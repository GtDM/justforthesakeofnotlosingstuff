#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <functional>
#include <entity.hpp>
#include <iostream>

class Ability
{
    public:
        Ability(int c, std::function <void()> i = [](){std::cout << "One does not simply invoke an ability, that one doesn't have\n";}): f(i), cooldown(c), used(0){}
        ~Ability(){}
        void setCooldown(int c){ cooldown = c;}
        int getCooldown() { return cooldown; }
        bool isAvailable(){return available;}
        void activate(){available = true;}
        void deactivate(){available = false;}
        void invoke()
        {
            if(isAvailable())
                this->f();
            used = true;
        }
        bool wasUsed(){return used;}
        void reset(){used = false;}
    protected:

    private:
        std::function <void()> f;
        int cooldown;
        bool available;
        bool used;
};

#endif // ABILITY_HPP
