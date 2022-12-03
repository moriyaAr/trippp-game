#include "RideState.h"
#include "BendState.h"
#include "JumpingState.h"
#include "HoldMovement.h"
#include "Player.h"

const sf::Vector2f ORIGEN = { 0,230 };

//------------------------------
// Ctor and calling to father Ctor
RideState::RideState(const int index):State()
{
	m_index = index;
	m_act = e_ride;
	Animation::init(m_act, PLAYER_PIC, ORIGEN, { START_POS.x + (CONTINU_POS.x * m_index), START_POS.y + (CONTINU_POS.y * m_index) });
	m_movement = std::make_unique<HoldMovement>();
}

//move ctor (becouse we have uniq_ptr in uniq_ptr) and calling to father move Ctor
RideState::RideState(RideState&& other) :State(std::move(other)){}

//realization of move assigen operator becouse of uniq_ptr
RideState& RideState::operator=(RideState&& other)
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
//------------------------------
// the func update the visibility
std::unique_ptr<State> RideState::update(sf::Time delta)
{
	State::update(delta);
	//m_movement->execute(this);	
	//return std::unique_ptr<State>(this);
	return std::make_unique<RideState>(std::move(*this));
}
//------------------------------
// the func treet user assked
std::unique_ptr<State> RideState::handleInput(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Up:
		return std::make_unique<JumpingState>(m_index);
	case sf::Keyboard::Key::Down:
		return std::make_unique<BendState>(m_index);
	default:
		break;
	}
	return nullptr;
}
