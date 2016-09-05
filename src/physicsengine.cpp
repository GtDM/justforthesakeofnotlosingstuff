#include "physicsengine.hpp"

PhysicsEngine::PhysicsEngine(sf::Vector2i size)
{
    _size = size;
}

PhysicsEngine::~PhysicsEngine()
{
    //dtor
}

void PhysicsEngine::addEntity(Entity* e)
{
    this->_entitylist.push_back(e);
}

void PhysicsEngine::processGravity(Entity* entity)
{
    entity->addForce(Force(0, 3, 1));
}
void PhysicsEngine::updateFinalVector(Entity* entity)
{
    for(auto it = entity->_forces.begin(); it != entity->_forces.end() && !entity->_forces.empty();)
    {
        if(it->getTimeLeft() <= 0)
        {
            entity->_forces.erase(it++);
        }
        else
        {
            it->removeTime(1);
            entity->finalVector.x += it->x;
            entity->finalVector.y += it->y;
            it++;
        }
    }
}

void PhysicsEngine::processCollision(std::vector <Surface> surfaces, Entity* entity)
{
    bool i = false;
    sf::FloatRect entityBounds = entity->getGlobalBounds();
    processGravity(entity);
    for(auto y : surfaces)
    {
        sf::FloatRect intersection;
        if(entityBounds.intersects(y.getGlobalBounds(), intersection))
        {
            i = true;
            if(intersection.height < intersection.width) //Up & Down
            {
                if(std::abs(intersection.top - entityBounds.top) < std::abs(y.getGlobalBounds().top - intersection.top))
                {
                    std::string b = y.getBehavior(top);
                    if(b == "top_collision")
                        topCollision(entity, intersection);
                }
                else
                {
                    std::string b = y.getBehavior(down);
                    if(b == "down_collision")
                        downCollision(entity, intersection);
                }
            }
            else
            {
                if(std::abs(intersection.left - entityBounds.left) > std::abs(y.getGlobalBounds().left - intersection.left))
                {
                    std::string b = y.getBehavior(right);
                    if(b == "right_collision")
                        rightCollision(entity, intersection);
                }
                else
                {
                    std::string b = y.getBehavior(left);
                    if(b == "left_collision")
                        leftCollision(entity, intersection);
                }
            }
        }
    }
    if(!i)
    {
        entity->_skillz["walk right"].activate();
        entity->_skillz["walk left"].activate();
    }

}

void PhysicsEngine::topCollision(Entity* entity, sf::FloatRect intersection) ///Collision relative to an entity
{
    ///Entity pod
    entity->_skillz["jump"].deactivate();
    entity->_skillz["walk right"].activate();
    entity->_skillz["walk left"].activate();
    if(entity->finalVector.y < 0)
        entity->finalVector.y = 0;
    entity->setPosition(entity->getPosition().x, entity->getPosition().y + 0.25 * intersection.height);
}

void PhysicsEngine::downCollision(Entity* entity, sf::FloatRect intersection)
{
    entity->_skillz["jump"].activate();
    entity->_skillz["walk right"].activate();
    entity->_skillz["walk left"].activate();
    if(entity->finalVector.y > 0)
        entity->finalVector.y = 0;
    entity->setPosition(entity->getPosition().x, entity->getPosition().y - 0.25 * intersection.height);
}

void PhysicsEngine::leftCollision(Entity* entity, sf::FloatRect intersection)
{
    entity->_skillz["walk left"].deactivate();
    entity->_skillz["walk right"].activate();
    if(entity->finalVector.x < 0)
        entity->finalVector.x = 0;
    entity->setPosition(entity->getPosition().x + 0.25 * intersection.width, entity->getPosition().y);
}

void PhysicsEngine::rightCollision(Entity* entity, sf::FloatRect intersection)
{
    entity->_skillz["walk left"].activate();
    entity->_skillz["walk right"].deactivate();
    if(entity->finalVector.x > 0)
        entity->finalVector.x = 0;
    entity->setPosition(entity->getPosition().x - 0.25 * intersection.width, entity->getPosition().y);
}
