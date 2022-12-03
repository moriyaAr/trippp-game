#include "State.h"
#include "Player.h"
#include "FallingMovement.h"

//---------------------------------------
// the func update the vizability
std::unique_ptr<State> State::update(sf::Time delta)
{
	m_animationTimer.restart();
	m_finishRound = Animation::update(delta, m_act);
	m_movement->execute(this);
	return nullptr;
}

//move ctor (becouse we have uniq_ptr in uniq_ptr) and calling to father move Ctor
State::State(State&& other):Animation(std::move(other))
{
	if (&other != this)
	{
		m_finishRound = other.m_finishRound;
		m_act = other.m_act;
		m_index = other.m_index;
		m_movement = std::move(other.m_movement);
	}
}

//realization of move assigen operator becouse of uniq_ptr
State& State::operator=(State&& other)
{
	if (&other != this)
	{
		m_finishRound = other.m_finishRound;
		m_act = other.m_act;
		m_index = other.m_index;
		m_movement = std::move(other.m_movement);
	}
	return *this;
}

//-------------------------------
// mobility of fall 
void State::fallDown()
{
	m_movement = std::make_unique<FallingMovement>();
}
