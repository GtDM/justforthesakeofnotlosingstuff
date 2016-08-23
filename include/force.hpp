#ifndef FORCE_HPP
#define FORCE_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Force: public sf::Vector2f
{
    public:
        Force(float a, float b, int d = 4): totalDuration(d), timeleft(d){x = a; y = b;} ///For some reason compiler doesn't recognise fields x, y as part of class Vector2f when initializer list
        ~Force(){}
        int getTimeLeft(){return timeleft;}
        const int getDuration(){return totalDuration;}
        void removeTime(int delta_t){timeleft -= delta_t;}
        Force operator +(const Force &f2){Force result(this->x + f2.x, this->y + f2.y, this->getTimeLeft()); return result;}
    protected:
    private:
        int totalDuration;
        int timeleft;
};

#endif // FORCE_HPP


