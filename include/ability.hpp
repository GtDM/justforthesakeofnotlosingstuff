#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <functional>
#include <entity.hpp>
#include <iostream>

class Ability
{
    public:
        Ability(int c, std::function <void()> i): f(i), cooldown(c), used(0){}
        Ability(): f([](){std::cout << "One does not simply invoke an ability, that one doesn't have\n";}), cooldown(0), used(0){}
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

typedef std::unordered_map <std::string, Ability> AbilityMap;
typedef std::pair <std::string, Ability> AbilityInstance;

#endif // ABILITY_HPP
