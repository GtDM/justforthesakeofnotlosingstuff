#include "game.hpp"

Game::Game(PhysicsEngine* engine, Level* level, int size_x, int size_y, std::string version)
{
    _window.create(sf::VideoMode(size_x, size_y), version);
    _window.setFramerateLimit(60);
    _state = true;
    _engine = engine;
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
    handleKeyboard();
    for(auto &entity : _engine->_entitylist)
    {
        _engine->updateFinalVector(entity);
        _engine->processCollision(_level->visibleMap, entity);
        entity->move(entity->finalVector);
    }
    if(_level->victoryCondition(_engine))
    {
        ///Some applause
        std::cout << "Congratulations!\n You have won ze game.\n But unfortunately you missed a party, because you are drunk\nGG\n";
        this->_state = false;
    }
    if(_level->failureCondition(_engine))
    {
        std::cout << "No cake for you, dummy\n You are dead\n But you might show up on a party celebrating some hero (not you, of course)\n Good day, sir\n";
        this->_state = false;
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

void Game::handleKeyboard()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        _window.close();
        _state = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _engine->_entitylist[0]->_skillz["jump"].invoke();
        _engine->_entitylist[0]->_skillz["jump"].deactivate(); ///TODO Working cooldowns in abilities
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _engine->_entitylist[0]->_skillz["walk left"].invoke();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _engine->_entitylist[0]->_skillz["walk right"].invoke();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _engine->_entitylist[0]->setMP(_engine->_entitylist[0]->getMP() + 1);
        //_engine->_entitylist[0]->_forces.push_back(Force(0, 2, 1));
        //_engine->_entitylist[0]->_skillz["do nothing"].invoke();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _engine->_entitylist[1]->_skillz["jump"].invoke();
        _engine->_entitylist[1]->_skillz["jump"].deactivate();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        _engine->_entitylist[1]->_skillz["walk left"].invoke();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _engine->_entitylist[1]->_skillz["walk right"].invoke();
    }
}
