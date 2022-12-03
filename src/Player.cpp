#include "Player.h"
#include "RideState.h"
#include "JumpingState.h"
//--------------------------------
//Ctor parameters are wich num in the deqeu to calc position
Player::Player(const int index)
{
	m_state = std::make_unique<RideState>(index);
}
//--------------------------------
//the func draw the player
void Player::draw()
{
	m_state->draw();
}
//--------------------------------
// the func update the visability of the player
void Player::update(sf::Time delta)
{
	if(m_state!=nullptr)
		m_state = std::move(m_state->update(delta));
}
//--------------------------------
// the func return if the player contain some obj or not
bool Player::intersects(const sf::FloatRect rect) const
{
	return m_state->getGlobalBounds().intersects(rect);
}
//--------------------------------
// the func return if the player in bend state or not
bool Player::isBendState() const
{
	if (m_state->getState() == e_bend)
		return true;
	return false;
}

//-------------------------------------------
// the func treet falling down case
void Player::fallDown()
{
	if (!m_die)
	{
		m_state->fallDown();
		m_die = true;
	}
}
//--------------------------------
// the func treet the user input
void Player::handleInput(sf::Keyboard::Key input)
{
	if (!m_die)
	{
		std::unique_ptr<State> state_ = std::move(m_state->handleInput(input));
		if (state_)
			m_state = std::move(state_);
	}
}