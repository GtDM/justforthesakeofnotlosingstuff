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
    entity->_forces.push_back(Force(0, 1, 3));
}
void PhysicsEngine::processMovement(std::vector <sf::RectangleShape> surfaces)
{
    for(auto &x : _entitylist)
    {
        sf::Vector2f finalVector(0, 0);
        bool i = false;
        sf::FloatRect entity = x->getGlobalBounds();
        for(auto y : surfaces)
        {
            sf::FloatRect s = y.getGlobalBounds();
            if(entity.intersects(s)) ///TODO Collision affects not only gravity
            {
                i = true;
                float m1 = std::min(std::abs(entity.top - (s.top + s.height)) /*entity under*/, std::abs((entity.top + entity.height) - s.top) /*entity above*/);
                float m2 = std::min(std::abs(entity.left - (s.left + s.width))/*entity on the right*/, std::abs((entity.left + entity.width) - s.left) /*entity on the right*/);
                float m3 = std::min(m1, m2);
                if(y.getFillColor() == sf::Color(0, 113, 0))
                {
                    //std::cout << "trawka\n";
                    if(m3 == std::abs((entity.top + entity.height) - s.top))
                    {
                        std::cout << "up\n";
                        x->_skillz[0].activate();
                        x->_skillz[1].activate();
                        x->_skillz[2].activate();
                    }
                    else if(m3 != m2) processGravity(x);

                    if(m3 == std::abs(entity.top - (s.top + s.height)))
                    {
                        std::cout << "down\n";
                        x->_skillz[0].deactivate();
                        x->_skillz[1].activate();
                        x->_skillz[2].activate();
                    }
                    else if(m3 == std::abs(entity.left - (s.left + s.width)))///TODO Collision alles WIP
                    {
                        std::cout << "right\n";
                        x->_skillz[1].deactivate();
                        x->_skillz[2].activate();
                    }
                    else
                    {
                        std::cout << "left\n";
                        x->_skillz[2].deactivate();
                        x->_skillz[1].activate();
                    }
                }
                else if(y.getFillColor() == sf::Color(0, 113, 165))
                {
                    //std::cout << "wasser\n";
                    if(m3 == std::abs((entity.top + entity.height) - s.top))
                    {
                        std::cout << "up\n";
                        x->_skillz[0].activate(); ///TODO Should be swimming
                    }
                    else if(m3 != m2) processGravity(x);

                    if(m3 == std::abs(entity.top - (s.top + s.height))) std::cout << "down\n";
                    else if(m3 == std::abs(entity.left - (s.left + s.width))) std::cout << "right\n";
                    else std::cout << "left\n";
                }
                else std::cout << y.getFillColor().r << " " << y.getFillColor().g << " " << y.getFillColor().b << "\n";
            }
        }
        for(std::vector<Force>::iterator it = x->_forces.begin(); it != x->_forces.end() && !x->_forces.empty();)
        {
            if(it->getTimeLeft() <= 0)
            {
                x->_forces.erase(it++);
            }
            else
            {
                it->removeTime(1);
                finalVector.x += it->x;
                finalVector.y += it->y;
                it++;
            }
        }
        if(!i)
        {
            processGravity(x);
            x->_skillz[1].activate();
            x->_skillz[2].activate();
        }
        x->move(finalVector);
    }
}
