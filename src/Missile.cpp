#include "Missile.h"
#include "TargetMovement.h"
#include "HoldMovement.h"
#include <math.h>

const double PI = 3.14159265;
const sf::Vector2i SIZE = { 30,93 };
const sf::Vector2i CUR_START = { 1094,WIN_Y + 155 };
const sf::Vector2f ORIGEN = { 15,93 };
const int OPOSITE_DIRECTION = 180;
//-------------------------------------
//ctor of coin sak call to father Ctor
Missile::Missile()
{
	init(SIZE, CUR_START, ORIGEN);
}

//the func change the movement of the missele to be targeted
void Missile::moveToTarget(const sf::Vector2f location)
{
	sf::Vector2f distance= location - getPosition();
	setRotation(atan2(abs(distance.x), abs(distance.y)) * OPOSITE_DIRECTION / PI);
	m_movement = std::make_unique< TargetMovement>(location, getPosition());
}

//the func hold the movement
void Missile::holdMovement()
{
	m_movement = std::make_unique< HoldMovement>();
}

// regist to Factory to Allow Factory to produce him
bool Missile::m_registerit = Factory::registerit(e_Missile,
	[]() -> std::unique_ptr<MovedObject> { return std::make_unique<Missile>(); });
