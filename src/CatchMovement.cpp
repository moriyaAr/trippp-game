#include "CatchMovement.h"

const float ITERATION_TIME = 0.1;
const float ULTRA_UP_RATE = 2;
const float ULTRA_DOWN_RATE = -3;
const float ENLARGE = 1.1;
const float REDUCE = 0.9;

// ctor 
CatchMovement::CatchMovement() : MoveStrategy() {}

//move ctor (becouse we have uniq_ptr in uniq_ptr)
CatchMovement::CatchMovement(CatchMovement&& other):MoveStrategy(std::move(other)){}

//----------------------------------------------
// the func update the next step of catch movement
// no return value no parameters
void CatchMovement::execute(sf::Sprite* pic)
{
	double time = m_timer.getElapsedTime().asSeconds();
	if (m_timer.getElapsedTime().asSeconds() < ITERATION_TIME)
	{
		pic->move(Resources::resources().MOVE_RATE*ULTRA_UP_RATE, 0);
		pic->scale(ENLARGE, ENLARGE);
	}
	else
	{
		pic->move(Resources::resources().MOVE_RATE * ULTRA_DOWN_RATE, 0);
		pic->scale(REDUCE, REDUCE);
	}
}
