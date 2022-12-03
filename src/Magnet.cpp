#include "Magnet.h"
#include "HoldMovement.h"

const float MAGNET_TIME = 5;
const sf::Vector2i SIZE = { 60,60 };
const sf::Vector2i CUR_START = { 1034,WIN_Y };
const sf::Vector2f ORIGEN = { 0,60 };
//--------------------------------

//-------------------------------------
//ctor of coin sak call to father Ctor
Magnet::Magnet() :Gift()
{
	init(SIZE, CUR_START, ORIGEN);
}

//behaivier when catch
void Magnet::stop()
{
	if (m_isStoped)
		return;
	m_isStoped = true;
	m_timer.restart();
	m_movement = std::make_unique< HoldMovement>();

}
//--------------------------------
// movement behaivier
void Magnet::move()
{
	if (m_timer.getElapsedTime().asSeconds() > MAGNET_TIME)
		m_movement = std::make_unique< DriveMovement>();
	Gift::move();
}
//--------------------------------
// regist to Factory to Allow Factory to produce him
bool Magnet::m_registerit = Factory::registerit(e_Magnet,
	[]() -> std::unique_ptr<MovedObject> { return std::make_unique<Magnet>(); });