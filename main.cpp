#include <game.hpp>
#define SIZE_X 1600
#define SIZE_Y 900
#define VERSION "alcohol 0,1%"

using namespace std;
using namespace sf;

/**Important project priority list
2. ENTITIES AND PROCESSING THEM
3. SKILL TREE AND ZE SKILLZ
4. EXPERIENCE AND HUD
**/

///TODO Alles dependent on fps
///TODO Bug: Game crashes, can't reproduce in debug mode, related to movement
//1. MAP - Done in some sense

int main(int argc, char** argv)
{
    PhysicsEngine engine(sf::Vector2i(SIZE_X, SIZE_Y));
    Entity player(&engine);
    Level default_map("data/somemap.png", SIZE_X);
    Game g(&player, &engine, &default_map, SIZE_X, SIZE_Y, VERSION);
    while (g.isRunning())
    {
        g.think();
        g.draw();
    }
    return 0;
}

