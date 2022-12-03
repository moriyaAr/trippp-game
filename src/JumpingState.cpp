#include "JumpingState.h"
#include "Player.h"
#include "RideState.h"
#include "JumpingMovement.h"
const sf::Vector2f ORIGEN = { 0,250 };

//------------------------------
// Ctor and calling to father Ctor
JumpingState::JumpingState(const int i):State()
{
	m_index = i;
	m_act = e_jump;
	Animation::init(m_act, PLAYER_PIC, ORIGEN , { START_POS.x + (CONTINU_POS.x * m_index), START_POS.y + (CONTINU_POS.y * m_index) });
	m_timer.restart();
	m_movement = std::make_unique<JumpingMovement>();
}

//move ctor (becouse we have uniq_ptr in uniq_ptr) and calling to father move Ctor
JumpingState::JumpingState(JumpingState&& other):State(std::move(other)){}

//realization of move assigen operator becouse of uniq_ptr
JumpingState& JumpingState::operator=(JumpingState&& other)
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
std::unique_ptr<State> JumpingState::update(sf::Time delta)
{
	State::update(delta);
	if (m_finishRound)
		return std::make_unique<RideState>(m_index);
	return std::make_unique<JumpingState>(std::move (*this));
}
