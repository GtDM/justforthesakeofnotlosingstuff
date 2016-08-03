#include "entity.hpp"

Entity::Entity(PhysicsEngine* p)
{
    setPosition(0, 0);
    this->setFillColor(sf::Color::Red);
    this->setSize(sf::Vector2f(20, 20));
    this->_priority_number = 1; ///TODO priority_number that matters, first one is player
    p->addEntity(this);
    Ability nothing(1);
    Ability jump(10, [this](){_forces.push_back(Force(0, -1, sf::milliseconds(5)));});
    Ability walk_left(10, [this](){_forces.push_back(Force(-0.33f, 0, sf::milliseconds(1)));});
    walk_left.activate();
    Ability walk_right(10, [this](){_forces.push_back(Force(0.33f, 0, sf::milliseconds(1)));});
    walk_right.activate();
    _skillz.push_back(jump);
    _skillz.push_back(walk_left);
    _skillz.push_back(walk_right);
    _skillz.push_back(nothing);
}

Entity::Entity()
{
    this->setPosition(100, 0);
    this->setFillColor(sf::Color::Red);
    this->setSize(sf::Vector2f(100, 100));
    this->_priority_number = 1;
}

Entity::~Entity()
{
    //dtor
}