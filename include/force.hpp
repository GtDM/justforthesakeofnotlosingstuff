#ifndef FORCE_HPP
#define FORCE_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Force: public sf::Vector2f
{
    public:
        Force(float a, float b, int d = 4): totalDuration(d), timeleft(d){x = a; y = b;}
        ~Force(){}
        int getTimeLeft(){return timeleft;}
        int getDuration(){return totalDuration;}
        void removeTime(int delta_t){timeleft -= delta_t;}
    protected:
    private:
        const int totalDuration;
        int timeleft;
};

#endif // FORCE_HPP


