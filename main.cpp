#include "game.hpp"
#include "argument_parser.hpp"
#define SIZE_X 1600
#define SIZE_Y 900
#define VERSION "alcohol 0,5%"

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
    PhysicsEngine* engine = new PhysicsEngine(sf::Vector2i(SIZE_X, SIZE_Y));
    //std::vector <Ability> default_skillset;
    Entity* player = new Entity(engine, sf::Color::Red, 1, sf::Vector2f(100, 100));
    //player.learnSkills(default_skillset);
    Entity* npc1 = new Entity(engine, sf::Color::Blue, 2, sf::Vector2f(400, 100));
    Entity* npc2 = new Entity(engine, sf::Color::Green, 2, sf::Vector2f(10, 100));
    Entity* npc3 = new Entity(engine, sf::Color::Blue, 2, sf::Vector2f(80, 100));
    Entity* npc4 = new Entity(engine, sf::Color::Blue, 2, sf::Vector2f(110, 100));
    Entity* npc5 = new Entity(engine, sf::Color::Blue, 2, sf::Vector2f(40, 100));
    Entity* npc6 = new Entity(engine, sf::Color::Blue, 2, sf::Vector2f(700, 100));
    Entity* npc7 = new Entity(engine, sf::Color::Blue, 2, sf::Vector2f(600, 100));
    Entity* npc8 = new Entity(engine, sf::Color::Blue, 2, sf::Vector2f(500, 100));
    Level* default_map = new Level("data/somemap.png", SIZE_X, sf::Vector2f(32, 32), engine);
    parseArguments(argc, argv);
    Game* g = new Game(engine, default_map, SIZE_X, SIZE_Y, VERSION);
    while (g->isRunning())
    {
        g->think();
        g->draw();
    }
    delete engine;
    delete default_map;
    delete g;
    delete player;
    delete npc1;
    delete npc2;
    delete npc3;
    delete npc4;
    delete npc5;
    delete npc6;
    delete npc7;
    delete npc8;
    asm("NOP"); ///It works!
    return 0;
}

