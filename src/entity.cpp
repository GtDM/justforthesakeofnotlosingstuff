#include "entity.hpp"

Entity::Entity(PhysicsEngine* p, sf::Color c, int priority, sf::Vector2f position)
{
    this->setFillColor(c);
    this->setSize(sf::Vector2f(20, 20));
    this->setPosition(position);
    this->_priority_number = priority; ///TODO priority_number that matters, first one is player
    p->addEntity(this);
    Ability nothing(1, [this](){std::cout << "One does not simply invoke an ability that one does not have\n";}); ///TODO Better skill learning
    nothing.activate();
    Ability jump(10, [this](){addForce(Force(0, -10));});
    Ability walk_left(10, [this](){addForce(Force(-1, 0));});
    walk_left.activate();
    Ability walk_right(10, [this](){addForce(Force(1, 0));});
    walk_right.activate();
    _skillz.insert(AbilityInstance{"jump", jump});
    _skillz.insert(AbilityInstance{"walk left", walk_left});
    _skillz.insert(AbilityInstance{"walk right", walk_right});
    _skillz.insert(AbilityInstance{"do nothing", nothing});
    _life = 100;

}

Entity::Entity()
{
    this->setPosition(100, 0);
    this->setFillColor(sf::Color::Red);
    this->setSize(sf::Vector2f(100, 100));
    this->_priority_number = 9999;
}

Entity::~Entity()
{
    //dtor
}

void Entity::learnSkills(AbilityMap skillset)
{
    //_skillz = skillset;
}

/*void Entity::removeForce(std::iterator <Force> it)
{
    this->_forces.erase(it);
}*/

void Entity::addForce(Force force)
{
    this->_forces.push_back(force);
}
