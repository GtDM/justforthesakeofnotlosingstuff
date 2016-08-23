#include "level.hpp"

Level::Level(std::string minimap_directory, int size_x)
{
    minimap.loadFromFile(minimap_directory);
    minimap_tex.loadFromImage(minimap);
    this->setTexture(minimap_tex, true);
    this->setPosition(size_x - this->getLocalBounds().width, 0); ///Minimap tied to view
}

Level::~Level()
{
    //dtor
}

void Level::constructVertexArrays(sf::RenderWindow* window) ///TODO needs improvement
{
    for(int x = 0; x != 32; x++) ///Temporary size
    {
        for(int y = 0; y != 32; y++) ///Temporary size
        {
            sf::Color c = minimap.getPixel(x, y);
            if(c != sf::Color::White)
            {
                sf::Vector2f v(window->getDefaultView().getSize().x * (x + 1)/ 32, window->getDefaultView().getSize().y * (y + 1) / 32);
                Surface s(sf::Vector2f(window->getDefaultView().getSize().x / 32, window->getDefaultView().getSize().y / 32));
                s.setOrigin(window->getDefaultView().getSize().x / 64, window->getDefaultView().getSize().y / 64);
                s.setPosition(v);
                if(c == sf::Color::Green) ///Zielona trawa
                {
                    s.setFillColor(sf::Color(0, 113, 0));
                    s.setType("grass");
                }
                else if(c == sf::Color::Blue) ///Wasser
                {
                    s.setFillColor(sf::Color(0, 113, 165)); ///TODO Combine Rectangles, that can be combined
                    s.setType("water");
                }
                visibleMap.push_back(s);
            }
        }
    }
}
