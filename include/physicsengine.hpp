#ifndef PHYSICSENGINE_HPP
#define PHYSICSENGINE_HPP
#include <vector>
#include <entity.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>

class Entity;

class PhysicsEngine
{
    public:
        PhysicsEngine(sf::Vector2i size);
        ~PhysicsEngine();
        void processGravity(Entity* entity); ///TODO gravity changes depending on level or gravity sources
        void addEntity(Entity* e);
        void processMovement(std::vector <sf::RectangleShape> surface);
        sf::Clock clock;
        std::vector <Entity*> _entitylist;
        int framerate;
    protected:
    private:
        sf::Vector2i _size;
};

#endif // PHYSICSENGINE_HPP


