#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <surface.hpp>

class Level: public sf::Sprite
{
    public:
        Level(std::string minimap_directory, int size_x, sf::Vector2f internal_size);
        ~Level();
        void constructVertexArrays(sf::RenderWindow* window);
        std::vector<Surface> visibleMap;
    protected:

    private:
        sf::Image minimap;
        sf::Texture minimap_tex;
        sf::Vector2f _size;
};

#endif // LEVEL_HPP
