#include "WayJumping.h"

const sf::Vector2i SIZE = { 60,50 };
const sf::Vector2i CUR_START = { 1034,1180 };
const sf::Vector2f ORIGEN = { 0,50 };

//---------------------------------------
//Ctor of Way Jumping and calling to father Ctor
WayJumping::WayJumping() :Gift()
{
	init(SIZE, CUR_START, ORIGEN);
}

// regist to Factory to Allow Factory to produce him
bool WayJumping::m_registerit = Factory::registerit(e_WayJumping,
	[]() -> std::unique_ptr<MovedObject> { return std::make_unique<WayJumping>(); });
