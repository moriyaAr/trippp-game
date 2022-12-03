#include "TargetMovement.h"
#include "CatchMovement.h"
const float NUM_OF_STEPS = 50;

//-------------------------
//Ctor that take to position to to set the movement
TargetMovement::TargetMovement(const sf::Vector2f magnetPos ,const sf::Vector2f myPos) : MoveStrategy()
{
	sf::Vector2f distance = magnetPos - myPos;
	m_magnetMoveRate.x = distance.x / NUM_OF_STEPS;
	m_magnetMoveRate.y = distance.y / NUM_OF_STEPS;
	m_timer.restart();
}

//move Ctor (becouse we have uniq_ptr in uniq_ptr) calling father move ctor
TargetMovement::TargetMovement(TargetMovement&& other) :MoveStrategy(std::move(other))
{
	m_magnetMoveRate=other.m_magnetMoveRate;
	m_index = other.m_index;
}

//------------------------------------------
//update the next step in this movement
void TargetMovement::execute(sf::Sprite* pic)
{
	if (m_index == NUM_OF_STEPS)
		pic->move(0, 0);
	else
	{
		pic->move(m_magnetMoveRate);
		m_index++;
	}
}