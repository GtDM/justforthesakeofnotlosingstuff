#ifndef FORCE_HPP
#define FORCE_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Force: public sf::Vector2f
{
    public:
        Force(float x, float y, int d = 4){this->x = x; this->y = y; totalDuration = d; timeleft = d;}
        ~Force(){}
        int getTimeLeft(){return timeleft;}
        int getDuration(){return totalDuration;}
        void removeTime(int delta_t){timeleft -= delta_t;}
    protected:
    private:
        int timeleft;
        int totalDuration; ///TODO totalDuration should be constant
};

#endif // FORCE_HPP


