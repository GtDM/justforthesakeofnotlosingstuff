#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "physicsengine.hpp"
#include "force.hpp"
#include "ability.hpp"

class PhysicsEngine;

class Entity: public sf::RectangleShape
{
    public:
        Entity(PhysicsEngine* p, sf::Color c);
        Entity();
        ~Entity();
        int getPriority(){return _priority_number;}
        void setPriority(int priority){_priority_number=priority;}
        std::vector <Force> _forces; ///TODO a lot of things should be private
        std::vector <Ability> _skillz;
        void learnSkills(std::vector <Ability> skillset);
        sf::Vector2f finalVector;
    protected:
    private:
        int _priority_number;
        int _life;
        int _mana;
};

#endif // ENTITY_HPP
