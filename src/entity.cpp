#include "entity.hpp"

Entity::Entity(PhysicsEngine* p, sf::Color c)
{
    setPosition(0, 0);
    this->setFillColor(c);
    this->setSize(sf::Vector2f(20, 20));
    this->setPosition(sf::Vector2f(100, 0));
    this->_priority_number = 1; ///TODO priority_number that matters, first one is player
    p->addEntity(this);
    Ability nothing(1, [this](){std::cout << "One does not simply invoke an ability that one does not have\n";}); ///TODO TEMP START
    Ability jump(10, [this](){_forces.push_back(Force(0, -10));});
    Ability walk_left(10, [this](){_forces.push_back(Force(-1, 0));});
    walk_left.activate();
    Ability walk_right(10, [this](){_forces.push_back(Force(1, 0));});
    walk_right.activate();
    _skillz.insert(AbilityInstance{"jump", jump});
    _skillz.insert(AbilityInstance{"walk left", walk_left});
    _skillz.insert(AbilityInstance{"walk right", walk_right});
    _skillz.insert(AbilityInstance{"do nothing", nothing}); ///TODO TEMP END
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

void Entity::learnSkills(std::unordered_map <std::string, Ability> skillset)
{
    //_skillz = skillset;
}
