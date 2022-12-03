#include "plane.h"

const sf::Vector2i SIZE = { 300,130 };
const sf::Vector2i CUR_START = { 300,WIN_Y };
const sf::Vector2f POSITION = { WIN_X,500 };
const sf::Vector2f ORIGEN = { 0,130 };
const float TAKE_OFF = 1.1;
const float FLY_LOW = 1.3;
const float TAKE_ON = 1.8;
//------------------------------------
//ctor of plane and calling to father Ctor
Plane::Plane() :Obsticles()
{
	init(SIZE, CUR_START, POSITION, ORIGEN,OBS_PIC);
	m_timer.restart();
}
//--------------------------------
// the func ovveride a specific movement
void Plane::move()
{
	if (m_timer.getElapsedTime().asSeconds() < TAKE_OFF)
		Obsticles::move();
	else if (m_timer.getElapsedTime().asSeconds() < FLY_LOW)
		sf::Sprite::move(-Resources::resources().MOVE_RATE, Resources::resources().MOVE_RATE);
	else if (m_timer.getElapsedTime().asSeconds() < TAKE_ON)
		Obsticles::move();
	else
		sf::Sprite::move(-Resources::resources().MOVE_RATE, -Resources::resources().MOVE_RATE);
}

//------------------------------
// regist to Factory to Allow Factory to produce him
bool Plane::m_registerit = Factory::registerit(e_Plane,
	[]() -> std::unique_ptr<MovedObject> { return std::make_unique<Plane>(); });