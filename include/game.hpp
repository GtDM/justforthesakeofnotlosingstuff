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

class Game
{
    public:
        Game(Entity* player, PhysicsEngine* engine, Level* level, int size_x, int size_y, std::string version);
        ~Game();
        bool isRunning(){return _state;}
        void draw();
        void sing(); ///TODO Let's sing a song, it won't take long
        void think(); ///TODO Bug: Sometimes player disappears
        sf::Vector2i _size;
    protected:

    private:
        bool _state;
        sf::Event _event;
        sf::RenderWindow _window;
        //sf::Clock clock; Might be used for animations, bullets and forces
        PhysicsEngine* _engine;
        Entity* _default_player;
        Level* _level;
};

#endif // GAME_HPP
