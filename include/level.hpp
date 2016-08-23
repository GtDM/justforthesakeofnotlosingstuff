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
        Level(std::string minimap_directory, int size_x);
        ~Level();
        void constructVertexArrays(sf::RenderWindow* window);
        std::vector<Surface> visibleMap; ///TODO Custom class for surfaces or whatever it should be called
    protected:

    private:
        sf::Image minimap;
        sf::Texture minimap_tex;
};

#endif // LEVEL_HPP
