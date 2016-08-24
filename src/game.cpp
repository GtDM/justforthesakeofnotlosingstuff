#include "game.hpp"

Game::Game(Entity* player, Entity* npc, PhysicsEngine* engine, Level* level, int size_x, int size_y, std::string version)
{
    _window.create(sf::VideoMode(size_x, size_y), version);
    _window.setFramerateLimit(60);
    _state = true;
    _engine = engine;
    _default_player = player;
    _npc = npc;
    _size.x = size_x;
    _size.y = size_y;
    _level = level;
    _level->constructVertexArrays(&_window);
    font.loadFromFile("data/under.ttf");
    frameRate.setFont(font);
    frameRate.setCharacterSize(100);
	frameRate.setPosition(20, 60);
	frameRate.setFillColor(sf::Color::White);
}

Game::~Game()
{

}

void Game::sing()
{

}

void Game::think()
{
    static sf::Clock clock; /// Magiczny zegar SFMLa...
	int fps = round(1.0f / clock.restart().asSeconds()); /// ...liczy FPSy.
	_engine->framerate = fps;
	std::stringstream ss; /// Magiczny strumień ciągów znaków...
	ss << "FPS: " << fps; /// ...łączy liczbę FPSów z napisem "FPS"...
	frameRate.setString(ss.str()); /// ...i aktualizuje globalną zmienną, wyświetlaną magicznie w draw()...
    _engine->clock.restart(); ///equals roughly 300-600 microseconds
    for(auto &entity : _engine->_entitylist)
    {
        entity->finalVector = sf::Vector2f(0, 0);
        for(auto s : entity->_skillz)
            s.second.reset();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        _window.close();
        _state = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _default_player->_skillz["jump"].invoke(); ///JUST TO SHOW THAT IT IS COOL, NOT WORTH IT BEFORE…
        _default_player->_skillz["jump"].deactivate(); ///TODO Working cooldowns in abilities
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ///TODO Availability check in Ability
    {
        _default_player->_skillz["walk left"].invoke();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _default_player->_skillz["walk right"].invoke();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _default_player->_forces.push_back(Force(0, 2, 1));
    }
    for(auto &entity : _engine->_entitylist)
    {
        _engine->updateFinalVector(entity);
        _engine->processCollision(_level->visibleMap, entity);
        entity->move(entity->finalVector);
    }
}

void Game::draw()
{
    _window.clear();
    for(auto x : _level->visibleMap)
        _window.draw(x);
    _window.draw(*_level);
    for(auto &x : _engine->_entitylist)
        _window.draw(*x);
    _window.draw(frameRate);
    _window.display();
}
