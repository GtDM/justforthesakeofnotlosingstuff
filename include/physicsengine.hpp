#ifndef PHYSICSENGINE_HPP
#define PHYSICSENGINE_HPP
#include <vector>
#include <entity.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "surface.hpp"

class Entity;

class PhysicsEngine
{
    public:
        PhysicsEngine(sf::Vector2i size);
        ~PhysicsEngine();
        void processGravity(Entity* entity); ///TODO gravity changes depending on level or gravity sources
        void addEntity(Entity* entity);
        void updateFinalVector(Entity* entity);
        void processCollision(std::vector <Surface> surfaces, Entity* entity);
        sf::Clock clock;
        std::vector <Entity*> _entitylist;
        int framerate;
    protected:
    private:
        sf::Vector2i _size;
};

#endif // PHYSICSENGINE_HPP


