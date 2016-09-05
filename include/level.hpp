#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <surface.hpp>
#include <physicsengine.hpp>

class Level: public sf::Sprite
{
    public:
        Level(std::string minimap_directory, int size_x, sf::Vector2f internal_size, PhysicsEngine* engine);
        ~Level();
        void constructVertexArrays(sf::RenderWindow* window);
        void changeObjective(std::function<bool(PhysicsEngine* engine)> lambda);
        std::vector<Surface> visibleMap;
        std::function<bool(PhysicsEngine* engine)> victoryCondition;
        std::function<bool(PhysicsEngine* engine)> failureCondition;
    protected:

    private:
        sf::Image minimap;
        sf::Texture minimap_tex;
        sf::Vector2f _size;
};

#endif // LEVEL_HPP
