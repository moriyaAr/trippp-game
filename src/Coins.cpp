#include "Coins.h"
#include "TargetMovement.h"

//---------------------------
const float NUM_OF_STEPS = 50;
const sf::Vector2f ORIGEN = { 20,20 };
const sf::Vector2f POSITION = { 0,0 };

//---------------------------
//ctor init the animation part, lottery position and init the movement
Coins::Coins():MovedObject()
{
	Animation::init(e_coin, PLAYER_PIC, ORIGEN, POSITION);
	int y = (rand() % (LOT_BASIC)) + LOT_RANGE;
	setPosition({ (float)WIN_X,(float)y });
	m_movement = std::make_unique< DriveMovement>();
}

//---------------------------
//the func treet the movment and update of car
//no return value no parameters
void Coins::move()
{
	auto delta = m_time.restart();
	update(delta, e_coin);
	m_movement->execute(this);
}

//---------------------------
// the func change the movment to targeted movement
// return false if the coin is alredy targeted
bool Coins::moveToMagnet(const sf::Vector2f magnetPos)
{
	if (m_moveCondition)
		return false;
	m_movement = std::make_unique< TargetMovement>(magnetPos,getPosition());
	return true;
}

//------------------------------
// regist to Factory to Allow Factory to produce him
bool Coins::m_registerit = Factory::registerit(e_Coins,
	[]() -> std::unique_ptr<MovedObject> { return std::make_unique<Coins>(); });