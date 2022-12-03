#include "Game.h"

//------------------------------
// the func init the hole game
// no return value nd no parameters
void Game::init()
{
    m_menu.init(&m_inform);
}
//------------------------------
// the func execute the game
// no return value no parameters
void Game::run()
{
    init();
    m_menu.run();
}
