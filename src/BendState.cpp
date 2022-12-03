#include "BendState.h"
#include "RideState.h"
#include "HoldMovement.h"
#include "Player.h"

const sf::Vector2f ORIGEN = { 0,200 };
//------------------------------

//ctor, parameter is index of player 
BendState::BendState(const int index):State()
{
	m_index = index;
	m_act = e_bend;
	Animation::init(m_act, PLAYER_PIC,ORIGEN, { START_POS.x + (CONTINU_POS.x * m_index), START_POS.y + (CONTINU_POS.y * m_index) });
	m_movement = std::make_unique<HoldMovement>();
}

//move ctor (becouse we have uniq_ptr in uniq_ptr)
BendState::BendState(BendState&& other) :State(std::move(other))
{}

//move assigen operator (becouse we have uniq_ptr in uniq_ptr)
BendState& BendState::operator=(BendState&& other)
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

// the func control key pressed and responds accordingly
//------------------------------
std::unique_ptr<State> BendState::handleInput(sf::Keyboard::Key key)
{
	return NULL;
}

//---------------------------------
// the func update the animation
std::unique_ptr<State> BendState::update(sf::Time delta)
{
	State::update(delta);
	if (m_finishRound)
		return std::make_unique<RideState>(m_index);
	return std::make_unique<BendState>(std::move(*this));
}
