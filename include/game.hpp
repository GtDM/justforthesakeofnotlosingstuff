#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <entity.hpp>
#include <physicsengine.hpp>
#include <iostream>
#include <level.hpp>
#include <sstream>

class Game
{
    public:
        Game(PhysicsEngine* engine, Level* level, int size_x, int size_y, std::string version);
        ~Game();
        bool isRunning(){return _state;}
        void draw();
        void sing();
        void think(); ///TODO Bug: Sometimes player disappears and game sometimes crashes, related to movement
        sf::Vector2i _size;
    protected:

    private:
        bool _state;
        sf::RenderWindow _window;
        sf::Text frameRate; ///Stolen legally with author's permission
        sf::Font font;
        PhysicsEngine* _engine;
        Level* _level;
        void handleKeyboard();
};

#endif // GAME_HPP
