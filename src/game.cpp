#include "game.hpp"

Game::Game(Entity* player, PhysicsEngine* engine, Level* level, int size_x, int size_y, std::string version)
{
    _window.create(sf::VideoMode(size_x, size_y), version);
    _state = true;
    _engine = engine;
    _default_player = player;
    _size.x = size_x;
    _size.y = size_y;
    _level = level;
    _level->constructVertexArrays(&_window);
}

Game::~Game()
{

}

void Game::sing()
{

}

void Game::think()
{
    _engine->clock.restart(); ///equals roughly 300-600 microseconds
    /*if(_window.pollEvent(_event))
    {
        if(_event.type == sf::Event::Closed)
        {
            _window.close();
            _state = false;
        }
    }*/
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        _window.close();
        _state = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && _default_player->_skillz[0].isAvailable())
    {
        //_default_player->_forces.push_back(Force(0, -8, sf::milliseconds(5))); ///TODO Adjust forces while not making too many of them
        _default_player->_skillz[0].invoke(); ///JUST TO SHOW THAT IT IS COOL, NOT WORTH IT BEFORE…
        _default_player->_skillz[0].deactivate(); ///TODO Working cooldowns in abilities
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _default_player->_skillz[1].isAvailable()) ///TODO Availability check in Ability
    {
        _default_player->_skillz[1].invoke();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _default_player->_skillz[2].isAvailable())
    {
        _default_player->_skillz[2].invoke();
    }
    /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _default_player->_forces.push_back(Force(0, 0.33f, sf::milliseconds(1)));
    }*/
    //std::cout << _default_player->getPosition().y << " " << _default_player->getPosition().x << "\n";
    _engine->processMovement(_level->visibleMap);
}

void Game::draw()
{
    _window.clear();
    for(auto x : _level->visibleMap)
        _window.draw(x);
    _window.draw(*_level);
    for(auto &x : _engine->_entitylist)
        _window.draw(*x);
    _window.display();
}
