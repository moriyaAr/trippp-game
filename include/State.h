#pragma once
#include <memory>
#include "Animation.h"
#include "MoveStrategy.h"
class Player;
class State : public Animation
{
public:
	State() {};
	virtual ~State() {};
	State(State&& other);
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key key) = 0;
	virtual std::unique_ptr<State> update(sf::Time delta);
	void fallDown();
	State& operator=(State&&);
	AnimOption getState() const { return m_act; };
protected:
	bool m_finishRound = false;
	AnimOption m_act;
	int m_index;
	std::unique_ptr<MoveStrategy> m_movement = nullptr;
};