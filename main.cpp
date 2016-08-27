#include "game.hpp"
#include "argument_parser.hpp"
#define SIZE_X 1600
#define SIZE_Y 900
#define VERSION "alcohol 0,2%"

using namespace std;
using namespace sf;

/**Important project priority list
2. ENTITIES AND PROCESSING THEM
3. SKILL TREE AND ZE SKILLZ
4. EXPERIENCE AND HUD
5. MUST BE DE MUSIK
**/

///TODO Alles dependent on fps
//1. MAP - Done in some sense

int main(int argc, char** argv)
{
    PhysicsEngine engine(sf::Vector2i(SIZE_X, SIZE_Y));
    //std::vector <Ability> default_skillset;
    Entity player(&engine, sf::Color::Red, 1, sf::Vector2f(100, 100));
    //player.learnSkills(default_skillset);
    Entity npc(&engine, sf::Color::Blue, 2, sf::Vector2f(400, 100));
    Level default_map("data/somemap.png", SIZE_X, sf::Vector2f(32, 32));
    parseArguments(argc, argv);
    Game g(&player, &npc, &engine, &default_map, SIZE_X, SIZE_Y, VERSION);
    while (g.isRunning())
    {
        g.think();
        g.draw();
    }
    asm("NOP"); ///It works!
    return 0;
}

