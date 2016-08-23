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
    entity->_forces.push_back(Force(0, 3, 1));
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
                    ///Entity pod
                    entity->_skillz[0].deactivate();
                    entity->_skillz[1].activate();
                    entity->_skillz[2].activate();
                    if(entity->finalVector.y < 0)
                        entity->finalVector.y = 0;
                }
                else
                {
                    ///Entity na
                    entity->_skillz[0].activate();
                    entity->_skillz[1].activate();
                    entity->_skillz[2].activate();
                    if(entity->finalVector.y > 0)
                        entity->finalVector.y = 0;
                }
            }
            else
            {
                if(std::abs(intersection.left - entityBounds.left) > std::abs(y.getGlobalBounds().left - intersection.left))
                {
                    ///Entity przed
                    entity->_skillz[1].activate();
                    entity->_skillz[2].deactivate();
                    if(entity->finalVector.x > 0)
                        entity->finalVector.x = 0;
                }
                else
                {
                    ///Entity za
                    entity->_skillz[1].deactivate();
                    entity->_skillz[2].activate();
                    if(entity->finalVector.x < 0)
                        entity->finalVector.x = 0;
                }
            }
        }
    }
    if(!i)
    {
        entity->_skillz[1].activate();
        entity->_skillz[2].activate();
    }

}

void PhysicsEngine::correctPosition(Entity* entity)
{
    ///TODO write this function
}
