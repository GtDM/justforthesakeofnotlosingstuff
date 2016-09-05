#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <unordered_map>
#include "physicsengine.hpp"
#include "force.hpp"
#include "ability.hpp"

class PhysicsEngine;

class Entity: public sf::RectangleShape
{
    public:
        Entity(PhysicsEngine* p, sf::Color c, int priority, sf::Vector2f position);
        Entity();
        ~Entity();
        int getPriority(){return _priority_number;}
        void setPriority(int priority){_priority_number=priority;}
        std::vector <Force> _forces; ///TODO a lot of things should be private
        AbilityMap _skillz;
        void learnSkills(AbilityMap skillset);
        int getHP(){return _life;}
        int getMP(){return _mana;}
        void setHP(int value){_life = value;}
        void setMP(int value){_mana = value;}
        sf::Vector2f finalVector;
        //void removeForce(std::iterator <Force> it);
        void addForce(Force force);
    protected:
    private:
        int _priority_number;
        int _life;
        int _mana;
};

#endif // ENTITY_HPP
