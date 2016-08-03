#ifndef FORCE_HPP
#define FORCE_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Force: public sf::Vector2f
{
    public:
        Force(float x, float y){this->x = x; this->y = y; totalDuration = sf::milliseconds(1);  timeleft = sf::milliseconds(1);}
        Force(float x, float y, sf::Time d){this->x = x; this->y = y; totalDuration = d; timeleft = d;}
        ~Force(){}
        sf::Time getTimeLeft(){return timeleft;}
        sf::Time getDuration(){return totalDuration;}
        void removeTime(sf::Time delta_t){timeleft -= delta_t;}
    protected:
    private:
        sf::Time timeleft;
        sf::Time totalDuration; ///TODO totalDuration should be constant
};

#endif // FORCE_HPP


